#pragma once

#include <vector>
#include <string>
#include <fstream>

#include <cstdint>

#include "Opcode.hpp"
#include "Instruction.hpp"

namespace ws {

namespace vm {

    struct ByteCode {

        /// Default constructor
        ByteCode() {}

        /// Construct from file
        explicit ByteCode(std::ifstream & file);

        std::vector<uint8_t> codeBuffer;
        std::vector<uint8_t> dataBuffer;

        Instruction&& GetInstructionAt(size_t offset);

        std::string ToString();
        void WriteToFile(std::ofstream & file);

        size_t GetAddressUpperBound() { return codeBuffer.size(); }

    private:

        template<typename T>
        T GetArgAtCode(size_t offset);

        std::string GetConstAt(size_t offset);

    };

#ifdef REQUIRE_GET_PARAM_IMPL
    // template functions for parameter accessing
    template<>
    int64_t ByteCode::GetArgAtCode<int64_t>(size_t offset) {
        return *reinterpret_cast<int64_t*>(&codeBuffer[offset + OpCodeSize]);
    }

    template<>
    double ByteCode::GetArgAtCode<double>(size_t offset) {
        return *reinterpret_cast<double*>(&codeBuffer[offset + OpCodeSize]);
    }

    template<>
    bool ByteCode::GetArgAtCode<bool>(size_t offset) {
        return static_cast<bool>(
            *reinterpret_cast<int64_t*>(&codeBuffer[offset + OpCodeSize])
        );
    }
#endif

}

}
