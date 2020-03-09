#pragma once 

#include <memory>

#include "Expression/ExpressionBase.hpp"
#include "Statement/Statement.hpp"

namespace ws {

namespace asl {

    struct StatementCondition final : StatementBase {

        std::shared_ptr<ExpressionBase> cond;
        
        std::shared_ptr<StatementBlock> thenBranch;
        std::shared_ptr<StatementBlock> elseBranch;

        bool InnerExecute(Environment & env) override;

    };

}

}
