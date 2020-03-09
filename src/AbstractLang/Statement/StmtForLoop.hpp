#pragma once 

#include <memory>

#include "Expression/ExpressionBase.hpp"
#include "Statement/Statement.hpp"

namespace ws {

namespace asl {

    struct StatementForLoop final : StatementBase {

        std::string iteratorName;
        std::shared_ptr<ExpressionBase> toIter;
        
        std::shared_ptr<StatementBlock> loopBody;

        bool InnerExecute(Environment & env) override;

    };

}

}
