#pragma once 

#include <memory>

#include "ExpressionBase.hpp"
#include "Statement.hpp"

namespace ws {

namespace asl {

    struct StatementExpression final : StatementBase {

        std::shared_ptr<ExpressionBase> expr;

        void Execute(Environment & env);

    };

}

}
