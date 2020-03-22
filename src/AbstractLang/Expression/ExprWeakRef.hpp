#pragma once 

#include <memory>

#include "Expression/ExpressionBase.hpp"

namespace ws {

namespace asl {

    /**
     * @brief Expression for weak ref.
     * Form: `@ref`
     * Requirements: ref : any
     */
    struct ExpressionWeakRef final : public ExpressionBase {

        std::shared_ptr<ExpressionBase> ref;

        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

    };

    /**
     * @brief Expression for optional deref.
     * Form: `weakref?`
     * Requirements: weakref : weak_ref
     */
    struct ExpressionOptionalDeref final : public ExpressionBase {

        std::shared_ptr<ExpressionBase> expr;

        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

    };

    /**
     * @brief Expression for strong deref.
     * Form: `weakref!`
     * Requirements: weakref : weak_ref
     */
    struct ExpressionStrongDeref final : public ExpressionBase {

        std::shared_ptr<ExpressionBase> expr;

        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

    };

}

}
