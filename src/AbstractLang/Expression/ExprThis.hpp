#pragma once 

#include <memory>

#include "Expression/ExpressionBase.hpp"

namespace ws {

namespace asl {

    /**
     * @brief Expression for `this`.
     * Form: `this`
     */
    struct ExpressionThis final : public ExpressionBase {

        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

        int64_t GenByteCode(vm::ByteCodeBuilder & builder) override;

    };

}

}
