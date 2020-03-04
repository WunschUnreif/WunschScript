#pragma once 

#include <memory>

#include "ExpressionBase.hpp"
#include "Statement.hpp"

namespace ws {

namespace asl {

    struct StatementAssignment final : StatementBase {

        std::shared_ptr<ExpressionBase> lhs;
        std::shared_ptr<ExpressionBase> rhs;

        bool Execute(Environment & env) override;
        
    };

}

}
