#pragma once 

#include <memory>

#include "Expression/ExpressionBase.hpp"

namespace ws {

namespace asl {

    /**
     * @brief Expression for logical not.
     * Form: `!rhs`
     * Requirements: rhs : bool
     */
    struct ExpressionLogicalNot final : public ExpressionBase {
        std::shared_ptr<ExpressionBase> rhs;

        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

        int64_t GenByteCode(vm::ByteCodeBuilder & builder) override;
    };

    /**
     * @brief Expression for logical and/or.
     * Form: `lhs [ `&&` | `||` ] rhs`
     * Requirements: lhs, rhs : bool
     */
    struct ExpressionLogicalBinaryOp final : public ExpressionBase {
        enum LogicalOp {
            LogicalAnd,
            LogicalOr
        } op;

        std::shared_ptr<ExpressionBase> lhs;
        std::shared_ptr<ExpressionBase> rhs;

        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

        int64_t GenByteCode(vm::ByteCodeBuilder & builder) override;
    };

}

}
