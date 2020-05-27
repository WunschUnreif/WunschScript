#include "Object.hpp"
#include "ObjectExceptions.hpp"

#include <string>

using namespace ws::vm2;

std::string Object::typeString() {
    switch(type) {
    case TypeUndefined: return "undefined";
    case TypeNil: return "nil";
    case TypeBool: return "bool";
    case TypeInt: return "int";
    case TypeFloat: return "float";
    case TypeStr: return "str";
    case TypeList: return "list";
    case TypeDict: return "dict";
    case TypeFunc: return "func";
    case TypeSystemFunc: return "sysfunc";
    case TypeWeakReference: return "weakref";
    default: return "unknown";
    }
}

uint64_t Object::id() {
    return reinterpret_cast<uint64_t>(this);
}

std::string Object::toString() {
    return typeString() + "@" + std::to_string(id());
}

Object::RValue Object::clone() {
    return std::make_shared<Object>();
}

Object::RValue Object::dCopy() {
    throw OperationNotAllowed();
}

Object::LValue Object::operator[](RValue index) {
    throw OperationNotAllowed();
}

Object::LValue Object::operator[](const std::string& index) {
    throw OperationNotAllowed();
}

Object::RValue Object::opDeref() {
    throw OperationNotAllowed();
}

Object::RValue Object::fcDeref() {
    throw OperationNotAllowed();
}

Object::RValue Object::operator~() {
    throw OperationNotAllowed();
}

Object::RValue Object::operator!() {
    throw OperationNotAllowed();
}

Object::RValue Object::operator+() {
    throw OperationNotAllowed();
}

Object::RValue Object::operator-() {
    throw OperationNotAllowed();
}

Object::RValue Object::operator+(RValue rhs) {
    throw OperationNotAllowed();
}

Object::RValue Object::operator-(RValue rhs) {
    throw OperationNotAllowed();
}

Object::RValue Object::operator*(RValue rhs) {
    throw OperationNotAllowed();
}

Object::RValue Object::operator/(RValue rhs) {
    throw OperationNotAllowed();
}

Object::RValue Object::operator%(RValue rhs) {
    throw OperationNotAllowed();
}

Object::RValue Object::operator<(RValue rhs) {
    throw OperationNotAllowed();
}

Object::RValue Object::operator==(RValue rhs) {
    throw OperationNotAllowed();
}

Object::RValue Object::operator&(RValue rhs) {
    throw OperationNotAllowed();
}

Object::RValue Object::operator|(RValue rhs) {
    throw OperationNotAllowed();
}

Object::RValue Object::operator^(RValue rhs) {
    throw OperationNotAllowed();
}

Object::RValue Object::operator&&(RValue rhs) {
    throw OperationNotAllowed();
}

Object::RValue Object::operator||(RValue rhs) {
    throw OperationNotAllowed();
}

Object::operator bool() {
    return false;
}
