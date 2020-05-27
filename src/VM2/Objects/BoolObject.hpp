#pragma once

#include "Object.hpp"

namespace ws {

namespace vm2 {

    struct BoolObject : public Object {
        bool value;

        BoolObject(): Object(TypeBool), value(false) {}
        BoolObject(bool val): Object(TypeBool), value(val) {}

        virtual std::string toString();
        virtual RValue dCopy();
        virtual RValue operator!();
        virtual RValue operator==(RValue rhs);
        virtual RValue operator&(RValue rhs);
        virtual RValue operator|(RValue rhs);
        virtual RValue operator^(RValue rhs);
        virtual RValue operator&&(RValue rhs);
        virtual RValue operator||(RValue rhs);
        virtual operator bool();
    };

}

}
