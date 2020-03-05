#pragma once 

#include <memory>

#include "ExpressionBase.hpp"
#include "Statement.hpp"

namespace ws {

namespace asl {

    struct StatementWhileLoop final : StatementBase {

        std::shared_ptr<ExpressionBase> cond;
        
        std::shared_ptr<StatementBlock> loopBody;

        bool InnerExecute(Environment & env) override;

    };

}

}
