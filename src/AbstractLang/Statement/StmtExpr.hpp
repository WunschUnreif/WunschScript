#pragma once 

#include <memory>

#include "Expression/ExpressionBase.hpp"
#include "Statement/Statement.hpp"

namespace ws {

namespace asl {

    struct StatementExpression final : StatementBase {

        std::shared_ptr<ExpressionBase> expr;

        bool InnerExecute(Environment & env) override;

        int64_t GenByteCode(vm::ByteCodeBuilder & builder) override;

    };

}

}
