#pragma once 

#include <memory>

#include "ExpressionBase.hpp"
#include "Statement.hpp"

namespace ws {

namespace asl {

    struct StatementReturn final : StatementBase {

        std::shared_ptr<ExpressionBase> expr;

        bool InnerExecute(Environment & env) override;

    };

}

}
