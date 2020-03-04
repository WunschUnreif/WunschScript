#ifndef __WS_ASL_EXPRESSION_BASE_HPP__
#define __WS_ASL_EXPRESSION_BASE_HPP__

#include <exception>

#include "GeneralDataNode.hpp"
#include "Environment.hpp"

namespace ws {

namespace asl {

    struct Environment;

    struct ExpressionBase {
        virtual ~ExpressionBase() {}

        virtual GeneralDataNode Eval(Environment & env, bool asLval = false) = 0;

        virtual void SetValue(Environment & env, GeneralDataNode target) {
            env.ReportError(std::runtime_error("Cannot set value to this expression"));
        }
    };

}

}

#endif // !__WS_ASL_EXPRESSION_BASE_HPP__
