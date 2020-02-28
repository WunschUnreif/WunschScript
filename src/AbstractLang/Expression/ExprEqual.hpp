#pragma once 

#include <memory>

#include "ExpressionBase.hpp"

namespace ws {

namespace asl {

    /**
     * @brief Expression for comparison.
     * Form: `lhs [== | !=] rhs`
     * Requirements: lhs, rhs : any
     */
    struct ExpressionEqual final : ExpressionBase {

        enum EqualOp {
            TestEqual,
            TestUnequal
        } op;

        std::shared_ptr<ExpressionBase> lhs;
        std::shared_ptr<ExpressionBase> rhs;

        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

    };

}

}
