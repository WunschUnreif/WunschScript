#pragma once 

#include <memory>

#include "Expression/ExpressionBase.hpp"
#include "Statement/Statement.hpp"

namespace ws {

namespace asl {

    struct StatementVariableDefine final : StatementBase {

        std::string id;
        std::shared_ptr<ExpressionBase> expr;

        bool InnerExecute(Environment & env) override;

    private:
        bool IsReservedWord();
        
    };

}

}
