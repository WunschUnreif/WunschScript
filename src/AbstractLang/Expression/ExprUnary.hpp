#pragma once 

#include <memory>

#include "ExpressionBase.hpp"

namespace ws {

namespace asl {

    /**
     * @brief Expression for unary plus/minus.
     * Form: `+/- rhs`
     * Requirements: rhs : int, float
     */
    struct ExpressionUnaryPM final : public ExpressionBase {

        enum UnaryOp {
            UnaryPlus,
            UnaryMinus 
        } op;

        std::shared_ptr<ExpressionBase> rhs;

        GeneralDataNode Eval(Environment & env, bool asLval = false);

    private:
        GeneralDataNode EvalForInt(GeneralDataNode intResult);
        GeneralDataNode EvalForFloat(GeneralDataNode floatResult);

    };

}

}
