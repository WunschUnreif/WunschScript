#pragma once 

#include <vector>
#include <memory>

#include "Expression/ExpressionBase.hpp"

namespace ws {

namespace asl {

    struct ExpressionFuncCall final : public ExpressionBase {

        std::shared_ptr<ExpressionBase> funcObj;
        std::vector<std::shared_ptr<ExpressionBase>> params;

        GeneralDataNode Eval(Environment & env, bool asLval = false);

        int64_t GenByteCode(vm::ByteCodeBuilder & builder) override;

    private:
        GeneralDataNode EvalForFunc(GeneralDataNode func, Environment & env);
        GeneralDataNode EvalForSystemFunc(GeneralDataNode func, Environment & env);

    };

}

}
