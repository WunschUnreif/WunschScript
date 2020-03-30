#pragma once 

#include <memory>

#include "Expression/ExpressionBase.hpp"

namespace ws {

namespace asl {

    /**
     * @brief Expression for comparison.
     * Form: `lhs [< | <= | >= | >] rhs`
     * Requirements: lhs, rhs : int | float | str 
     */
    struct ExpressionCompare final : public ExpressionBase {

        enum CompareOp {
            CompareLess,
            CompareLessEq, 
            CompareGreater,
            CompareGreaterEq
        } op;

        std::shared_ptr<ExpressionBase> lhs;
        std::shared_ptr<ExpressionBase> rhs;

        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

        int64_t GenByteCode(vm::ByteCodeBuilder & builder) override;

    private:
        GeneralDataNode EvalForString(GeneralDataNode lhsStrNode, GeneralDataNode rhsStrNode);
        GeneralDataNode EvalForInt(GeneralDataNode lhsIntNode, GeneralDataNode rhsIntNode);
        GeneralDataNode EvalForFloat(GeneralDataNode lhsFloatNode, GeneralDataNode rhsFloatNode);

    };

}

}
