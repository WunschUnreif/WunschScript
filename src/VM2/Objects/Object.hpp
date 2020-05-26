#pragma once

#include <memory>

namespace ws {

namespace vm2 {

    struct Machine;

    struct Object {
        enum Type {
            TypeUndefined,
            TypeNil,
            TypeBool,
            TypeInt,
            TypeFloat,
            TypeStr,
            TypeList,
            TypeDict,
            TypeFunc,
            TypeSystemFunc,
            TypeWeakReference
        } type = TypeUndefined;

        Machine * machine;

        using RValue = std::shared_ptr<Object>;
        using LValue = std::shared_ptr<Object> *;

        struct Value {
            union {
                RValue rval;
                LValue lval;
            };
            bool isLVal;

            Value(RValue rv): rval(rv), isLVal(false) {}
            Value(LValue lv): lval(lv), isLVal(true)  {}
        };

        virtual std::string typeString();
        virtual std::string toString();
        virtual uint64_t id();
        virtual RValue clone() = 0;
        virtual RValue dcopy() = 0;
        virtual LValue operator[](RValue index) = 0;
        virtual LValue operator[](const std::string& key) = 0;
        virtual RValue opderef() = 0;
        virtual RValue fcderef() = 0;
        virtual RValue operator~() = 0;
        virtual RValue operator!() = 0;
        virtual RValue operator+() = 0;
        virtual RValue operator-() = 0;
        virtual RValue operator+(RValue rhs) = 0;
        virtual RValue operator-(RValue rhs) = 0;
        virtual RValue operator*(RValue rhs) = 0;
        virtual RValue operator/(RValue rhs) = 0;
        virtual RValue operator%(RValue rhs) = 0;
        virtual RValue operator<(RValue rhs) = 0;
        virtual RValue operator==(RValue rhs) = 0;
        virtual RValue operator&(RValue rhs) = 0;
        virtual RValue operator|(RValue rhs) = 0;
        virtual RValue operator^(RValue rhs) = 0;
        virtual RValue operator&&(RValue rhs) = 0;
        virtual RValue operator||(RValue rhs) = 0;
        virtual operator bool() = 0;
    };

}

}
