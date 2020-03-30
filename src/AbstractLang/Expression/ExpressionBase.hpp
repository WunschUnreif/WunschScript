#ifndef __WS_ASL_EXPRESSION_BASE_HPP__
#define __WS_ASL_EXPRESSION_BASE_HPP__

#include <exception>

#include "DataRepresentation/GeneralDataNode.hpp"
#include "Environment/Environment.hpp"

#include "CodeBuilder.hpp"
#include "Opcode.hpp"

namespace ws {

namespace asl {

    struct Environment;

    struct ExpressionBase {
        
        virtual ~ExpressionBase() {}

        virtual GeneralDataNode Eval(Environment & env, bool asLval = false) = 0;

        virtual void SetValue(Environment & env, GeneralDataNode target) {
            env.ReportError(std::runtime_error("Cannot set value to this expression"));
        }

        virtual int64_t GenByteCode(vm::ByteCodeBuilder & builder) { return 0; };

        virtual int64_t GenByteCodeLval(vm::ByteCodeBuilder & builder) { 
            throw std::runtime_error("Cannot gen bytecode for this expression as lval");
        };


    };

}

}

#endif // !__WS_ASL_EXPRESSION_BASE_HPP__
