#pragma once 

#include <string>

#include "Expression/ExpressionBase.hpp"

namespace ws {

namespace asl {

    struct ExpressionID final : public ExpressionBase {
        std::string identifier;

        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

        void SetValue(Environment & env, GeneralDataNode target) override;

        int64_t GenByteCode(vm::ByteCodeBuilder & builder) override;
        int64_t GenByteCodeLval(vm::ByteCodeBuilder & builder) override;
    };

}

}
