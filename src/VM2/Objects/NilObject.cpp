#include "NilObject.hpp"
#include "ObjectExceptions.hpp"
#include "BoolObject.hpp"

#include <string>

using namespace ws::vm2;

std::string NilObject::toString() {
    return "nil";
}

NilObject::RValue NilObject::dCopy() {
    return NilObject::THE_ONLY_NIL;
}

NilObject::LValue NilObject::operator[](RValue index) {
    return &NilObject::THE_ONLY_NIL;
}

NilObject::LValue NilObject::operator[](const std::string& index) {
    return &NilObject::THE_ONLY_NIL;
}

NilObject::RValue NilObject::opDeref() {
    return NilObject::THE_ONLY_NIL;
}

NilObject::RValue NilObject::fcDeref() {
    return NilObject::THE_ONLY_NIL;
}

NilObject::RValue NilObject::operator~() {
    return NilObject::THE_ONLY_NIL;
}

NilObject::RValue NilObject::operator!() {
    return NilObject::THE_ONLY_NIL;
}

NilObject::RValue NilObject::operator+() {
    return NilObject::THE_ONLY_NIL;
}

NilObject::RValue NilObject::operator-() {
    return NilObject::THE_ONLY_NIL;
}

NilObject::RValue NilObject::operator+(RValue rhs) {
    return NilObject::THE_ONLY_NIL;
}

NilObject::RValue NilObject::operator-(RValue rhs) {
    return NilObject::THE_ONLY_NIL;
}

NilObject::RValue NilObject::operator*(RValue rhs) {
    return NilObject::THE_ONLY_NIL;
}

NilObject::RValue NilObject::operator/(RValue rhs) {
    return NilObject::THE_ONLY_NIL;
}

NilObject::RValue NilObject::operator%(RValue rhs) {
    return NilObject::THE_ONLY_NIL;
}

NilObject::RValue NilObject::operator<(RValue rhs) {
    return NilObject::THE_ONLY_NIL;
}

NilObject::RValue NilObject::operator==(RValue rhs) {
    return std::make_shared<BoolObject>(rhs->type == TypeNil);
}

NilObject::RValue NilObject::operator&(RValue rhs) {
    return NilObject::THE_ONLY_NIL;
}

NilObject::RValue NilObject::operator|(RValue rhs) {
    return NilObject::THE_ONLY_NIL;
}

NilObject::RValue NilObject::operator^(RValue rhs) {
    return NilObject::THE_ONLY_NIL;
}

NilObject::RValue NilObject::operator&&(RValue rhs) {
    return NilObject::THE_ONLY_NIL;
}

NilObject::RValue NilObject::operator||(RValue rhs) {
    return NilObject::THE_ONLY_NIL;
}

NilObject::operator bool() {
    return false;
}

