#pragma once 

#include <memory>

#include "Expression/ExpressionBase.hpp"
#include "Statement/Statement.hpp"

namespace ws {

namespace asl {

    struct StatementWhileLoop final : StatementBase {

        std::shared_ptr<ExpressionBase> cond;
        
        std::shared_ptr<StatementBlock> loopBody;

        bool InnerExecute(Environment & env) override;

        int64_t GenByteCode(vm::ByteCodeBuilder & builder) override;

    };

}

}
