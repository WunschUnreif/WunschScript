#pragma once 

#include <memory>

#include "ExpressionBase.hpp"

namespace ws {

namespace asl {

    /**
     * @brief Expression for `this`.
     * Form: `this`
     */
    struct ExpressionThis final : public ExpressionBase {

        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

    };

}

}
