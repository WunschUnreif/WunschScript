#include <exception>
#include <iostream>

#include "CodeBuilder.hpp"

using namespace ws::vm;

template <typename T>
void ByteCodeBuilder::PushImmediate(T imm) {
    uint8_t * argByteSeq = reinterpret_cast<uint8_t*>(&imm);
    for(int i = 0; i < sizeof(int64_t); ++i) {
        bytecode.codeBuffer.push_back(argByteSeq[i]);
    }
}

int64_t ByteCodeBuilder::Append(OpCode code) {
    if(OpCodeHasArgument(code)) {
        throw std::runtime_error("Calling append(code) where code need argument.");
    }

    int64_t address = bytecode.codeBuffer.size();

    bytecode.codeBuffer.push_back(static_cast<uint8_t>(code));

    return address;
}

int64_t ByteCodeBuilder::Append(OpCode code, int64_t argInt) {
    if(!OpCodeHasArgument(code)) {
        throw std::runtime_error("Calling append(code) where code don't need argument.");
    }

    int64_t address = bytecode.codeBuffer.size();

    bytecode.codeBuffer.push_back(static_cast<uint8_t>(code));
    PushImmediate(argInt);

    return address;
}

int64_t ByteCodeBuilder::Append(OpCode code, double argFloat) {
    if(!OpCodeHasArgument(code)) {
        throw std::runtime_error("Calling append(code) where code don't need argument.");
    }

    int64_t address = bytecode.codeBuffer.size();

    bytecode.codeBuffer.push_back(static_cast<uint8_t>(code));
    PushImmediate(argFloat);

    return address;
}

int64_t ByteCodeBuilder::Append(OpCode code, bool argBool) {
    if(!OpCodeHasArgument(code)) {
        throw std::runtime_error("Calling append(code) where code don't need argument.");
    }

    int64_t address = bytecode.codeBuffer.size();

    bytecode.codeBuffer.push_back(static_cast<uint8_t>(code));
    PushImmediate(static_cast<int64_t>(argBool));

    return address;
}

int64_t ByteCodeBuilder::Append(OpCode code, const std::string & argString) {
    if(!OpCodeHasArgument(code)) {
        throw std::runtime_error("Calling append(code) where code don't need argument.");
    }

    int64_t address = bytecode.codeBuffer.size();

    bytecode.codeBuffer.push_back(static_cast<uint8_t>(code));
    PushImmediate(GetOffsetForConst(argString));

    return address;
}

int64_t ByteCodeBuilder::GetOffsetForConst(const std::string & str) {
    if(constMap.find(str) == constMap.end()) {
        constMap[str] = bytecode.dataBuffer.size();

        for(auto c : str) {
            bytecode.dataBuffer.push_back(static_cast<uint8_t>(c));
        }
        bytecode.dataBuffer.push_back(0);
    }

    return constMap[str];
}
