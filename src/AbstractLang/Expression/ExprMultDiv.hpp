#pragma once 

#include <memory>

#include "ExpressionBase.hpp"

namespace ws {

namespace asl {

    /**
     * @brief Expression for mult.
     * Form: `lhs * rhs`
     * Requirements: lhs, rhs : int|float; lhs|rhs : list, rhs|lhs : int
     */
    struct ExpressionMultiply final : ExpressionBase {

        std::shared_ptr<ExpressionBase> lhs;
        std::shared_ptr<ExpressionBase> rhs;

        GeneralDataNode Eval(Environment & env, bool asLval = false);

    private:
        GeneralDataNode EvalForInt(GeneralDataNode lhsResult, GeneralDataNode rhsResult);
        GeneralDataNode EvalForFloat(GeneralDataNode lhsResult, GeneralDataNode rhsResult);

        /// list * int
        GeneralDataNode EvalForList(GeneralDataNode lhsResult, GeneralDataNode rhsResult);

    };

    /**
     * @brief Expression for divide and mod.
     * Form: `lhs [/ | %] rhs`
     * Requirements: lhs, rhs : int|float
     */
    struct ExpressionDivMod final : ExpressionBase {

        enum DivModOp {
            OpDivide,
            opMod
        } op;

        std::shared_ptr<ExpressionBase> lhs;
        std::shared_ptr<ExpressionBase> rhs;

        GeneralDataNode Eval(Environment & env, bool asLval = false);

    private:
        GeneralDataNode EvalForInt(GeneralDataNode lhsResult, GeneralDataNode rhsResult);
        GeneralDataNode EvalForFloat(GeneralDataNode lhsResult, GeneralDataNode rhsResult);

    };

}

}

