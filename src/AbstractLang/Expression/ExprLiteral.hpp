#pragma once 

#include "Expression/ExpressionBase.hpp"

namespace ws {

namespace asl {

    struct ExpressionLiteral final : public ExpressionBase {
        GeneralDataNode value;
        
        GeneralDataNode Eval(Environment & env, bool asLval = false) override;
    };

}

}
