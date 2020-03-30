#include <sstream>
#include <iostream>
#include <iomanip>
#include <exception>

#define REQUIRE_GET_PARAM_IMPL

#include "ByteCode.hpp"
#include "Opcode.hpp"

using namespace ws::vm;

ByteCode::ByteCode(std::ifstream & file) {
    std::vector<uint8_t> buffer;
    uint8_t checksum = 0;

    // check the file size
    file.seekg(0, std::ios_base::end);
    auto filesize = file.tellg();
    file.seekg(0, std::ios_base::beg);

    if(filesize < 13) {
        throw std::runtime_error("Bytecode file empty.");
    }

    // load the whole file
    while(!file.eof()) {
        char currbyte;
        file.get(currbyte);

        if(file.eof()) {
            break;
        }

        buffer.push_back(static_cast<uint8_t>(currbyte));
        checksum ^= static_cast<uint8_t>(currbyte);
    }

    // check the checksum
    if(checksum != 0) {
        throw std::runtime_error("Bytecode file's checksum incorrect.");
    }

    // check the magic numbers
    if(
        buffer[0] != 'W' ||
        buffer[1] != 'S' ||
        buffer[2] != 'V' ||
        buffer[3] != 'M'
    ) {
        throw std::runtime_error("Bytecode file's magic number incorrect.");
    }

    // parse data buffer start addr
    int64_t dataStartAddr = *reinterpret_cast<int64_t*>(&buffer[4]);

    // load the code and data buffer
    codeBuffer.assign(buffer.begin() + 12, buffer.begin() + dataStartAddr);
    dataBuffer.assign(buffer.begin() + dataStartAddr, buffer.end() - 1);
}

void ByteCode::WriteToFile(std::ofstream & file) {
    uint8_t checksum = 0;
    
    uint8_t magicNumbers[4] = {'W', 'S', 'V', 'M'};
    int64_t dataStartAddr = sizeof(magicNumbers) + sizeof(int64_t) + codeBuffer.size() * sizeof(uint8_t);

    // 1. Write the magic number
    for(int i = 0; i < 4; ++i) {
        file.put(magicNumbers[i]);
        checksum ^= magicNumbers[i];
    }

    // 2. Write the data start address
    for(int i = 0; i < sizeof(int64_t); ++i) {
        uint8_t toPut = reinterpret_cast<uint8_t*>(&dataStartAddr)[i];
        file.put(toPut);
        checksum ^= toPut;
    }

    // 3. Write the code buffer
    for(size_t i = 0; i < codeBuffer.size(); ++i) {
        file.put(codeBuffer[i]);
        checksum ^= codeBuffer[i];
    }

    // 4. Write the data buffer
    for(size_t i = 0; i < dataBuffer.size(); ++i) {
        file.put(dataBuffer[i]);
        checksum ^= dataBuffer[i];
    }

    // 5. Write the checksum
    file.put(checksum);
}

std::string ByteCode::ToString() {
    std::string result;
    size_t codePointer = 0; // current code address
    int indent = 0;         // current indent level

    // iterate over each instruction
    while(codePointer < codeBuffer.size()) {
        std::ostringstream currStr;
        auto instruction = GetInstructionAt(codePointer);

        // in case the indent shoule decrease
        if(instruction.opcode == ENDP || instruction.opcode == ENDPS) {
            indent--;
        }

        // output the code address in hex
        currStr << std::setw(8) << std::setfill('0') << std::hex << codePointer << "    ";
        currStr << std::setw(0) << std::setfill(' ') << std::dec;

        // output the indent level
        for(int i = 0; i < indent; ++i) currStr << "....";
        
        // output the instruction string
        currStr << instruction.ToString(codePointer);

        // end of line
        currStr << std::endl;

        // increment the code pointer
        codePointer += OpCodeSize;
        if(OpCodeHasArgument(instruction.opcode)) {
            codePointer += sizeof(int64_t);
        }

        // in case the indent shoule increase
        if(instruction.opcode == PROC) {
            indent++;
        }

        // merge the string stream into result
        result += currStr.str();
    }

    return result;
} 

std::string ByteCode::GetConstAt(size_t offset) {
    return std::string(reinterpret_cast<char*>(&dataBuffer[offset]));
}

Instruction ByteCode::GetInstructionAt(size_t offset) {
    Instruction result;
    
    result.opcode = OpCode(codeBuffer[offset]);

    // Fill in the argument
    if(OpCodeHasArgument(result.opcode)) {
        switch(result.opcode) {
        case ACCID:
        case ACCIDL:
        case IMMS:
        case PARAM:
        case ARRPARAM:
        case BIND:
        case NAME:
        case GET:
        case GETL:
        case SET:
        case ITER:
        case SCOPE:
        case FILE:
            // arg type is string
            result.argumentType = Instruction::ArgTypeString;
            result.argString = GetConstAt(GetArgAtCode<int64_t>(offset));
            break;

        case IMMF:
            // arg type is float
            result.argumentType = Instruction::ArgTypeFloat;
            result.argument.argFloat = GetArgAtCode<double>(offset);
            break;
        
        case IMMB:
            // arg type is bool
            result.argumentType = Instruction::ArgTypeBool;
            result.argument.argBool = GetArgAtCode<bool>(offset);
            break;

        case IMMI:
        case LINE:
        case JFALSE:
        case JMP:
        case NEXT:
        case PROC:
            // arg type is int
            result.argumentType = Instruction::ArgTypeInt;
            result.argument.argInt = GetArgAtCode<int64_t>(offset);
            break;
        }
    }

    return result;
}

#undef REQUIRE_GET_PARAM_IMPL
