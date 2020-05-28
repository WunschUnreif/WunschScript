#include "BoolObject.hpp"
#include "ObjectExceptions.hpp"

#include <string>

using namespace ws::vm2;

std::string BoolObject::toString() {
    return value ? "true" : "false";
}

BoolObject::RValue BoolObject::dCopy() {
    return std::make_shared<BoolObject>(value);
}

BoolObject::RValue BoolObject::operator!() {
    return std::make_shared<BoolObject>(!value);
}

BoolObject::RValue BoolObject::operator==(RValue rhs) {
    if(rhs->type != TypeBool) {
        return std::make_shared<BoolObject>(false);
    }

    return std::make_shared<BoolObject>(rhs->as<BoolObject>()->value == value);
}

BoolObject::RValue BoolObject::operator^(RValue rhs) {
    return std::make_shared<BoolObject>(rhs->as<BoolObject>()->value != value);
}

BoolObject::RValue BoolObject::operator&&(RValue rhs) {
    return std::make_shared<BoolObject>(rhs->as<BoolObject>()->value && value);
}

BoolObject::RValue BoolObject::operator||(RValue rhs) {
    return std::make_shared<BoolObject>(rhs->as<BoolObject>()->value || value);
}

BoolObject::operator bool() {
    return value;
}

