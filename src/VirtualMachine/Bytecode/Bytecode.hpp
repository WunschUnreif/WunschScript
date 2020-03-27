#pragma once

#include <vector>
#include <string>

#include <cstdint>

#include "Opcode.hpp"

namespace ws {

namespace vm {

    struct ByteCode {

        std::vector<uint8_t> codeBuffer;
        std::vector<uint8_t> dataBuffer;

        std::string GetConstAt(size_t offset);

        template<typename T>
        T GetParamAtCode(size_t offset);

        std::string ToString();

    };

#ifdef REQUIRE_GET_PARAM_IMPL
    // template functions for parameter accessing
    template<>
    int64_t ByteCode::GetParamAtCode<int64_t>(size_t offset) {
        return *reinterpret_cast<int64_t*>(&codeBuffer[offset + OpCodeSize]);
    }

    template<>
    double ByteCode::GetParamAtCode<double>(size_t offset) {
        return *reinterpret_cast<double*>(&codeBuffer[offset + OpCodeSize]);
    }

    template<>
    bool ByteCode::GetParamAtCode<bool>(size_t offset) {
        return static_cast<bool>(
            *reinterpret_cast<int64_t*>(&codeBuffer[offset + OpCodeSize])
        );
    }
#endif

}

}
