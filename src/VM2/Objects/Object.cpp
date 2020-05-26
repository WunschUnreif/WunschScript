#include "Object.hpp"

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
    case TypeWeakReference: return "wref";
    default: return "unknown";
    }
}

uint64_t Object::id() {
    return reinterpret_cast<uint64_t>(this);
}

std::string Object::toString() {
    return typeString() + "@" + std::to_string(id());
}
