#pragma once

#include <memory>
#include "ObjectExceptions.hpp"

namespace ws {

namespace vm2 {

    struct Object {
        //===----------------- Object Data Fields -----------------===
        enum Type: uint8_t {
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

        uint8_t gcMarking = 0;

        //===----------------- Associated Data Types -----------------===
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

            RValue asRValue();
            LValue asLValue();
        };

        //===----------------- Interface methods -----------------===
        virtual std::string typeString();
        virtual std::string toString();
        virtual uint64_t id();
        virtual RValue clone();
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

        virtual void markReachables() {}

        template<class T>
        T* as() { T* r = dynamic_cast<T*>(this); if(!r) throw TypeError(); return r; }

        //===----------------- C++ object lifetime -----------------===
        Object() {}
        virtual ~Object() {}
    protected:
        Object(Type t): type(t) {}
    };

    constexpr static size_t ObjectSize = sizeof(Object);

}

}
