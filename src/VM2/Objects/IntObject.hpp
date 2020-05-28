#pragma once

#include "Object.hpp"

namespace ws {

namespace vm2 {

    struct IntObject : public Object {
        int64_t value = 0;

        IntObject(): Object(TypeInt) {}
        IntObject(int64_t val): Object(TypeInt), value(val) {}

        virtual std::string toString();
        virtual RValue dCopy();
        virtual RValue operator~();
        virtual RValue operator+();
        virtual RValue operator-();
        virtual RValue operator+(RValue rhs);
        virtual RValue operator-(RValue rhs);
        virtual RValue operator*(RValue rhs);
        virtual RValue operator/(RValue rhs);
        virtual RValue operator%(RValue rhs);
        virtual RValue operator<(RValue rhs);
        virtual RValue operator==(RValue rhs);
        virtual RValue operator&(RValue rhs);
        virtual RValue operator|(RValue rhs);
        virtual RValue operator^(RValue rhs);
        virtual operator bool();

    };

}

}
