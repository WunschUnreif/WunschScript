#pragma once 

#include <vector>
#include <memory>

#include "ExpressionBase.hpp"

namespace ws {

namespace asl {

    struct ExpressionFuncCall final : public ExpressionBase {

        std::shared_ptr<ExpressionBase> funcObj;
        std::vector<std::shared_ptr<ExpressionBase>> params;

        GeneralDataNode Eval(Environment & env, bool asLval = false);

    private:
        GeneralDataNode EvalForFunc(GeneralDataNode func, Environment & env);
        GeneralDataNode EvalForSystemFunc(GeneralDataNode func, Environment & env);

    };

}

}
