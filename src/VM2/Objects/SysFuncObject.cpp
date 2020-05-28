#include "SysFuncObject.hpp"
#include "BoolObject.hpp"
#include "ObjectExceptions.hpp"

using namespace ws::vm2;

std::string SysFuncObject::toString() {
    return "sysfunc@" + std::to_string(reinterpret_cast<uint64_t>(impl.target<void*>()));
}

Object::RValue SysFuncObject::dCopy() {
    return std::make_shared<SysFuncObject>(impl, paramNum);
}

Object::RValue SysFuncObject::operator==(RValue rhs) {
    if(rhs->type != TypeSystemFunc) {
        return std::make_shared<BoolObject>(false);
    }

    return std::make_shared<BoolObject>(
        impl.target<void*>() == rhs->as<SysFuncObject>()->impl.target<void*>()
    );
}

SysFuncObject::operator bool() {
    return true;
}
