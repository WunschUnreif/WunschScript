#pragma once

#include <functional>
#include <deque>
#include "Object.hpp"

namespace ws {

namespace vm2 {

    struct Machine;
    struct Executor;

    struct SysFuncObject : public Object {
        using ImplType = std::function<RValue(std::deque<RValue>, Machine &, Executor &)>;
        
        ImplType impl;
        int32_t paramNum = -1;  // < 0 means don't check param count

        SysFuncObject(): Object(TypeSystemFunc) {}
        SysFuncObject(ImplType impl, int32_t paramNum = -1)
            : Object(TypeSystemFunc), impl(impl), paramNum(paramNum) {}

        virtual std::string toString();
        virtual RValue dCopy();
        virtual RValue operator==(RValue rhs);
        virtual operator bool();
    };

}

}