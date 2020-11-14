#pragma once

#include <map>

#include "Object.hpp"

namespace ws {

namespace vm2 {

    struct DictObject : public Object {
        std::map<std::string, RValue> value;
        bool underRecursiveTraverse = false;

        DictObject(): Object(TypeDict) {}
        DictObject(const std::map<std::string, RValue> & value)
            : Object(TypeDict), value(value) {}

        std::string typeString() override;
        std::string toString() override;
        RValue dCopy() override;
        LValue operator[](RValue index) override;
        RValue subscript(RValue index) override;
        RValue opDeref() override;
        RValue fcDeref() override;
        RValue operator~() override;
        RValue operator!() override;
        RValue operator+() override;
        RValue operator-() override;
        RValue operator+(RValue rhs) override;
        RValue operator-(RValue rhs) override;
        RValue operator*(RValue rhs) override;
        RValue operator/(RValue rhs) override;
        RValue operator%(RValue rhs) override;
        RValue operator<(RValue rhs) override;
        RValue operator==(RValue rhs) override;
        RValue operator&(RValue rhs) override;
        RValue operator|(RValue rhs) override;
        RValue operator^(RValue rhs) override;
        RValue operator&&(RValue rhs) override;
        RValue operator||(RValue rhs) override;
        operator bool() override;
        std::shared_ptr<Iterator> iter() override;

        void markReachables(uint8_t gcVal) override {}

        struct DictIterator: public Iterator {
            bool advance() override;
            RValue curr() override;
            bool available() override;
        };
    };

}

}
