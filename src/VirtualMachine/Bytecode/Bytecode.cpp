#include <sstream>
#include <iomanip>
#include <exception>

#define REQUIRE_GET_PARAM_IMPL

#include "ByteCode.hpp"
#include "Opcode.hpp"

using namespace ws::vm;

std::string ByteCode::ToString() {
    int indent = 0;
    std::string result;

    size_t codePointer = 0;
    while(codePointer < codeBuffer.size()) {
        std::ostringstream currStr;
        auto opCode = OpCode(codeBuffer[codePointer]);
        auto opName = GetOpName(opCode);

        if(opCode == ENDP || opCode == ENDPS) {
            indent--;
        }

        currStr << std::setw(8) << std::setfill('0') << std::hex << codePointer << " ";
        currStr << std::setw(0) << std::setfill(' ') << std::dec;

        for(int i = 0; i < indent; ++i) currStr << "|---";
        currStr << opName;
        for(auto i = opName.length(); i < 8; ++i) currStr << " ";

        if(OpCodeHasArgument(opCode)) {
            int64_t paramI = GetParamAtCode<int64_t>(codePointer);
            double paramF = GetParamAtCode<double>(codePointer);
            bool paramB = GetParamAtCode<bool>(codePointer);

            switch(opCode) {
                // Parameter is string
                case ACCID:
                case ACCIDL:
                case IMMS:
                case PARAM:
                case ARRPARAM:
                case BIND:
                case NAME:
                case GET:
                case SET:
                case ITER:
                case SCOPE:
                case FILE:
                    currStr << GetConstAt(paramI);
                    break;

                // Parameter is integer
                case IMMI:
                case LINE:
                    currStr << paramI;
                    break;
                
                // Special cases
                case IMMF:
                    currStr << paramF;
                    break;
                
                case IMMB:
                    currStr << paramB;
                    break;

                case JFALSE:
                case JMP:
                case NEXT:
                case PROC:
                    currStr << paramI << " <" 
                            << std::hex << std::setw(6) << std::setfill('0') << codePointer + paramI
                            << std::dec << std::setw(0) << std::setfill(' ') << ">";
                    break;
            }
        }

        currStr << std::endl;

        codePointer += OpCodeSize;
        if(OpCodeHasArgument(opCode)) {
            codePointer += sizeof(int64_t);
        }

        if(opCode == PROC) {
            indent++;
        }

        result += currStr.str();
    }
    return result;
} 

std::string ByteCode::GetConstAt(size_t offset) {
    return std::string(reinterpret_cast<char*>(&dataBuffer[offset]));
}
