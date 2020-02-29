#pragma once 

#include <string>

#include "ExpressionBase.hpp"

namespace ws {

namespace asl {

    struct ExpressionID final : public ExpressionBase {
        std::string identifier;

        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

        void SetValue(Environment & env, GeneralDataNode target) override;
    };

}

}
