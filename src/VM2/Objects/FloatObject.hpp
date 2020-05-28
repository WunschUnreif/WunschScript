#pragma once

#include "Object.hpp"

namespace ws {

namespace vm2 {

    struct FloatObject : public Object {
        double value = 0;

        FloatObject(): Object(TypeFloat) {}
        FloatObject(double val): Object(TypeFloat), value(val) {}

        virtual std::string toString();
        virtual RValue dCopy();
        virtual RValue operator+();
        virtual RValue operator-();
        virtual RValue operator+(RValue rhs);
        virtual RValue operator-(RValue rhs);
        virtual RValue operator*(RValue rhs);
        virtual RValue operator/(RValue rhs);
        virtual RValue operator<(RValue rhs);
        virtual RValue operator==(RValue rhs);
        virtual operator bool();

    };

}

}
