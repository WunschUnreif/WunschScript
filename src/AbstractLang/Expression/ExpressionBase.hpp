#ifndef __WS_ASL_EXPRESSION_BASE_HPP__
#define __WS_ASL_EXPRESSION_BASE_HPP__

#include "GeneralDataNode.hpp"
#include "Environment.hpp"

namespace ws {

namespace asl {

    struct ExpressionBase {
        virtual ~ExpressionBase() = 0;

        virtual GeneralDataNode Eval(Environment & env, bool asLval = false) = 0;
    };

}

}

#endif // !__WS_ASL_EXPRESSION_BASE_HPP__
