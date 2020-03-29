#include <sstream>
#include <iomanip>

#include "Instruction.hpp"

using namespace ws::vm;

std::string Instruction::ToString(size_t codePointer) {
    std::ostringstream result;

    // 1. Add instruction name, extend to 8 characters' width
    result << GetOpName(opcode);
    while(result.str().length() < 8) result << ' ';

    // 2. Add argument string.
    switch(argumentType) {
    case ArgTypeNull:
        break;
    case ArgTypeBool:
        result << argument.argBool ? "true" : "false";
    case ArgTypeInt:
        result << std::to_string(argument.argInt);
        break;
    case ArgTypeFloat:
        result << std::to_string(argument.argFloat);
        break;
    case ArgTypeString:
        result << argString;
        break;
    }

    // 3. In case the instruction is jmp-like, add the target address.
    switch(opcode) {
    case JMP:
    case JFALSE:
    case NEXT:
    case PROC:
        result << " <" << std::hex << std::setw(6) << std::setfill('0') << codePointer + argument.argInt << ">";
        break;
    }

    return result.str();
}
