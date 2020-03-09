#pragma once 

#include <memory>

#include "Expression/ExpressionBase.hpp"
#include "Statement/Statement.hpp"

namespace ws {

namespace asl {

    struct StatementReturn final : StatementBase {

        std::shared_ptr<ExpressionBase> expr;

        bool InnerExecute(Environment & env) override;

    };

}

}
