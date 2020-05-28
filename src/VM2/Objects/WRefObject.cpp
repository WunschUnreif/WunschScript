#include "WRefObject.hpp"
#include "BoolObject.hpp"
#include "NilObject.hpp"
#include "ObjectExceptions.hpp"

using namespace ws::vm2;

std::string WRefObject::toString() {
    return std::string("wref(of ") + (ref.expired() ? std::string("nil") : std::to_string(ref.lock()->id())) + ")";
}

Object::RValue WRefObject::dCopy() {
    return std::make_shared<WRefObject>(*this);
}

Object::RValue WRefObject::opDeref() {
    if(ref.expired()) {
        return NilObject::THE_ONLY_NIL;
    }
    return ref.lock();
}

Object::RValue WRefObject::fcDeref() {
    if(ref.expired()) {
        throw WeakRefExpired();
    }
    return ref.lock();
}
