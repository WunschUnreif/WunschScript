#pragma once 

#include <memory>

#include "Expression/ExpressionBase.hpp"

namespace ws {

namespace asl {

    /**
     * @brief Expression for deepcopy.
     * Form: `<ref>`
     * Requirements: ref : any
     */
    struct ExpressionDeepCopy final : public ExpressionBase {

        std::shared_ptr<ExpressionBase> ref;

        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

        int64_t GenByteCode(vm::ByteCodeBuilder & builder) override;

    };

    struct ExpressionDeepCopyModify final : public ExpressionBase {

        std::shared_ptr<ExpressionBase> ref;

        std::vector<std::string> keyToMod;
        std::vector<std::shared_ptr<ExpressionBase>> valToMod;

        GeneralDataNode Eval(Environment & env, bool asLval = false) override;

        int64_t GenByteCode(vm::ByteCodeBuilder & builder) override;

    };

}

}
