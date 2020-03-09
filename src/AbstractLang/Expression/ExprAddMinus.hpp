#pragma once 

#include <memory>

#include "Expression/ExpressionBase.hpp"

namespace ws {

namespace asl {

    /**
     * @brief Expression for add.
     * Form: `lhs + rhs`
     * Requirements: lhs, rhs : int|float|str; lhs : list
     */
    struct ExpressionAdd final : public ExpressionBase {
        
        std::shared_ptr<ExpressionBase> lhs;
        std::shared_ptr<ExpressionBase> rhs;

        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

    private: 
        GeneralDataNode EvalForInt(GeneralDataNode lhsResult, GeneralDataNode rhsResult);
        GeneralDataNode EvalForFloat(GeneralDataNode lhsResult, GeneralDataNode rhsResult);
        GeneralDataNode EvalForString(GeneralDataNode lhsResult, GeneralDataNode rhsResult);

        GeneralDataNode EvalForList(GeneralDataNode lhsResult, GeneralDataNode rhsResult);

    };

    /**
     * @brief Expression for minus.
     * Form: `lhs - rhs`
     * Requirements: lhs, rhs : int|float
     */
    struct ExpressionMinus final : public ExpressionBase {
        
        std::shared_ptr<ExpressionBase> lhs;
        std::shared_ptr<ExpressionBase> rhs;

        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

    private: 
        GeneralDataNode EvalForInt(GeneralDataNode lhsResult, GeneralDataNode rhsResult);
        GeneralDataNode EvalForFloat(GeneralDataNode lhsResult, GeneralDataNode rhsResult);

    };

}

}
