#pragma once 

#include <memory>

#include "Expression/ExpressionBase.hpp"

namespace ws {

namespace asl {

    /**
     * @brief Expression for binary not.
     * Form: `~rhs`
     * Requirements: rhs : int
     */
    struct ExpressionBinaryNot final : public ExpressionBase {
        std::shared_ptr<ExpressionBase> rhs;

        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

        int64_t GenByteCode(vm::ByteCodeBuilder & builder) override;
    };

    /**
     * @brief Expression for binary and/or/xor.
     * Form: `lhs [ `&` | `||` | `^` ] rhs`
     * Requirements: lhs, rhs : int
     */
    struct ExpressionBinaryBinaryOp final : public ExpressionBase {
        enum BinaryOp {
            BinaryAnd,
            BinaryOr,
            BinaryXor
        } op;

        std::shared_ptr<ExpressionBase> lhs;
        std::shared_ptr<ExpressionBase> rhs;

        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

        int64_t GenByteCode(vm::ByteCodeBuilder & builder) override;
    };

}

}
