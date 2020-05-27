#pragma once

#include "Object.hpp"

namespace ws {

namespace vm2 {

    struct NilObject : public Object {

        NilObject(): Object(TypeNil) {}

        virtual std::string toString();
        virtual RValue dCopy();
        virtual LValue operator[](RValue index);
        virtual LValue operator[](const std::string& key);
        virtual RValue opDeref();
        virtual RValue fcDeref();
        virtual RValue operator~();
        virtual RValue operator!();
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
        virtual RValue operator&&(RValue rhs);
        virtual RValue operator||(RValue rhs);
        virtual operator bool();

        static RValue THE_ONLY_NIL;

    };

    Object::RValue NilObject::THE_ONLY_NIL = std::make_shared<NilObject>();

}

}
