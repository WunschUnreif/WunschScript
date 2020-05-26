#pragma once

#include <map>
#include <string>

#include "Opcode.hpp"
#include "Instruction.hpp"
#include "ByteCode.hpp"

namespace ws {

namespace vm {

    struct ByteCodeBuilder {

        ByteCode bytecode;

        int64_t Append(OpCode code);

        int64_t Append(OpCode code, int64_t argInt);
        int64_t Append(OpCode code, double argFloat);
        int64_t Append(OpCode code, bool argBool);
        int64_t Append(OpCode code, const std::string & argString);

        void ChangeArgumentForCode(size_t offset, int64_t argInt);

    private:
        std::map<std::string, int64_t> constMap;

        int64_t GetOffsetForConst(const std::string & str);

        template <typename T>
        void PushImmediate(T imm);

        void PushOpcodePadding();

    };

}

}
