#pragma once 

#include <string>

#include "Opcode.hpp"

namespace ws {

namespace vm {

    struct Instruction {

        OpCode opcode;

        enum ArgumentType {
            ArgTypeNull,
            ArgTypeInt,
            ArgTypeBool,
            ArgTypeFloat,
            ArgTypeString
        } argumentType = ArgTypeNull;

        union _Arg{
            bool argBool;
            int64_t argInt;
            double argFloat;
        } argument;
        std::string argString;

        std::string ToString(size_t codePointer = 0);

    };

}

}
