#pragma once 

#include <memory>
#include <string>

#include "ExpressionBase.hpp"

namespace ws {

namespace asl {

    struct ExpressionMemberAccess final : public ExpressionBase {

        std::shared_ptr<ExpressionBase> lhs;
        std::string id;

        GeneralDataNode Eval(Environment & env, bool asLval = false)  override;

    };

}

}
