#include "StrObject.hpp"
#include "IntObject.hpp"
#include "BoolObject.hpp"
#include "ObjectExceptions.hpp"

using namespace ws::vm2;

std::string StrObject::toString() {
    return value;
}

Object::RValue StrObject::dCopy() {
    return std::make_shared<StrObject>(value);
}

Object::RValue StrObject::subscript(RValue index) {
    int64_t idx = index->as<IntObject>()->value;
    if(idx < 0 || idx >= value.length()) {
        throw IndexOutOfRange();
    }
    char c[2] = {value[idx], 0};
    return std::make_shared<StrObject>(std::string(c));
}

Object::RValue StrObject::operator+(RValue rhs) {
    return std::make_shared<StrObject>(value + rhs->toString());
}

Object::RValue StrObject::operator<(RValue rhs) {
    return std::make_shared<BoolObject>(
        value < rhs->as<StrObject>()->value
    );
}

Object::RValue StrObject::operator==(RValue rhs) {
    return std::make_shared<BoolObject>(
        value == rhs->as<StrObject>()->value
    );
}

StrObject::operator bool() {
    return value != "";
}
