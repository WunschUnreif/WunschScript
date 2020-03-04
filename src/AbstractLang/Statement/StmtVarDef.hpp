#pragma once 

#include <memory>

#include "ExpressionBase.hpp"
#include "Statement.hpp"

namespace ws {

namespace asl {

    struct StatementVariableDefine final : StatementBase {

        std::string id;
        std::shared_ptr<ExpressionBase> expr;

        bool Execute(Environment & env) override;

    private:
        bool IsReservedWord();
        
    };

}

}
