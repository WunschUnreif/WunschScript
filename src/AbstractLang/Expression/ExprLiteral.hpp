#pragma once 

#include "Expression/ExpressionBase.hpp"

namespace ws {

namespace asl {

    struct ExpressionLiteral final : public ExpressionBase {
        GeneralDataNode value;
        
        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

        int64_t GenByteCode(vm::ByteCodeBuilder & builder) override;

    private:
        int64_t GenByteCodeForPlainImmediate(vm::ByteCodeBuilder & builder);
        int64_t GenByteCodeForList(vm::ByteCodeBuilder & builder);
        int64_t GenByteCodeForDict(vm::ByteCodeBuilder & builder);
        int64_t GenByteCodeForFunc(vm::ByteCodeBuilder & builder);
    };

}

}
