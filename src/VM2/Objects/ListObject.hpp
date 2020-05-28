#pragma once

#include <deque>
#include <initializer_list>
#include "Object.hpp"

namespace ws {

namespace vm2 {

    struct ListObject : public Object {
        std::deque<RValue> value;
        bool underRecursiveTraverse = false;

        ListObject(): Object(TypeList) {}
        ListObject(const std::deque<RValue> & val): Object(TypeList), value(val) {}
        ListObject(std::initializer_list<RValue> initvals): Object(TypeList), value(initvals) {}

        virtual std::string toString();
        virtual RValue dCopy();
        virtual LValue operator[](RValue index);
        virtual RValue subscript(RValue index);
        virtual RValue operator+(RValue rhs);
        virtual RValue operator<(RValue rhs);
        virtual RValue operator==(RValue rhs);
        virtual operator bool();
        virtual std::shared_ptr<Iterator> iter();

        virtual void markReachables(uint8_t gcVal);

        struct ListIterator: public Iterator {
            std::deque<RValue>::iterator iter;
            std::deque<RValue>::iterator end;
            
            bool advance() override;
            RValue curr() override;
            bool available() override;

            ListIterator(std::deque<RValue>::iterator iter, std::deque<RValue>::iterator end)
                : iter(iter), end(end) {}
        };

    };

}

}
