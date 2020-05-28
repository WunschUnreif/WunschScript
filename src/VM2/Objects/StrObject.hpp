#pragma once

#include <string>
#include "Object.hpp"

namespace ws {

namespace vm2 {

    struct StrObject : public Object {
        std::string value;

        StrObject(): Object(TypeStr) {}
        StrObject(const std::string & val): Object(TypeStr), value(val) {}
        StrObject(std::string_view val): Object(TypeStr), value(val) {}

        virtual std::string toString();
        virtual RValue dCopy();
        virtual RValue subscript(RValue index);
        virtual RValue operator+(RValue rhs);
        virtual RValue operator<(RValue rhs);
        virtual RValue operator==(RValue rhs);
        virtual operator bool();

    };

}

}
