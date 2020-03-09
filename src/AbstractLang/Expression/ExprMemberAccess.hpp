#pragma once 

#include <memory>
#include <string>

#include "Expression/ExpressionBase.hpp"

namespace ws {

namespace asl {

    /**
     * @brief Expression for member access.
     * Form: `lhs.id`
     * Requirements: lhs : dict, id : ID
     */
    struct ExpressionMemberAccess final : public ExpressionBase {

        std::shared_ptr<ExpressionBase> lhs;
        std::string id;

        GeneralDataNode Eval(Environment & env, bool asLval = false)  override;
        void SetValue(Environment & env, GeneralDataNode target) override;

    };

    /**
     * @brief Expression for member access that needs calculation for key string.
     * Form: `lhs[rhs]`
     * Requirements: (1) lhs : dict, rhs : str; (2) lhs : list, rhs : int
     */
    struct ExpressionMemberAccessCalaulated final : public ExpressionBase {

        std::shared_ptr<ExpressionBase> lhs;
        std::shared_ptr<ExpressionBase> rhs;

        GeneralDataNode Eval(Environment & env, bool asLval = false)  override;
        void SetValue(Environment & env, GeneralDataNode target) override;

    };

}

}
