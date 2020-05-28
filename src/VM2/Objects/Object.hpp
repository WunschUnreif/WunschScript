#pragma once

#include <memory>
#include <string_view>
#include <string>
#include "ObjectExceptions.hpp"

namespace ws {

namespace vm2 {

    struct Object : public std::enable_shared_from_this<Object> {
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

        struct Iterator {
            /* try move to next object */
            virtual bool advance();
            /* get the current object */
            virtual RValue curr();
            /* curr is avaliable */
            virtual bool available();
        };

        //===----------------- Interface methods -----------------===
        virtual std::string typeString();
        virtual std::string toString();
        virtual uint64_t id();
        virtual RValue clone();
        virtual RValue dCopy();
        virtual LValue operator[](RValue index);
        virtual LValue operator[](std::string_view key);
        virtual RValue subscript(RValue index);
        virtual RValue subscript(std::string_view key);
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
        virtual std::shared_ptr<Iterator> iter();

        // Note: this function only marks its sub-objects recursively, not object it self
        virtual void markReachables(uint8_t gcVal) {}

        template<class T>
        T* as() { T* r = dynamic_cast<T*>(this); if(!r) throw TypeError(); return r; }

        struct DefaultIterator: public Iterator {
            RValue self;
            bool availability = true;
            virtual bool advance();
            virtual RValue curr();
            virtual bool available();
            DefaultIterator(RValue self): self(self) {}
        };

        //===----------------- C++ object lifetime -----------------===
        Object() {}
        virtual ~Object() {}
    protected:
        Object(Type t): type(t) {}
    };

    constexpr static size_t ObjectSize = sizeof(Object);

}

}
