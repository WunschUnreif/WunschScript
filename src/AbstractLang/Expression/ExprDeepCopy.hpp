#pragma once 

#include <memory>

#include "ExpressionBase.hpp"

namespace ws {

namespace asl {

    /**
     * @brief Expression for deepcopy.
     * Form: `<ref>`
     * Requirements: ref : any
     */
    struct ExpressionDeepCopy final : public ExpressionBase {

        std::shared_ptr<ExpressionBase> ref;

        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

    };

}

}
