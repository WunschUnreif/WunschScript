#include "FuncObject.hpp"
#include "BoolObject.hpp"
#include "ObjectExceptions.hpp"

using namespace ws::vm2;

std::string FuncObject::toString() {
    std::string result = "func(";

    bool first = true;
    for(auto & parName : paramNames) {
        if(!first) {
            result += ", ";
        }
        result += parName;
        first = false;
    }

    if(withArrTail) {
        if(!first) {
            result += ", ";
        }
        result += "[" + arrParamName + "]";
    }
    
    result += ")@" + std::to_string(executorID) + ":" + std::to_string(codePointer);
    return result;
}

Object::RValue FuncObject::dCopy() {
    return std::make_shared<FuncObject>(*this);
}

Object::RValue FuncObject::operator==(RValue rhs) {
    if(rhs->type != TypeFunc) {
        return std::make_shared<BoolObject>(false);
    }

    return std::make_shared<BoolObject>(
        executorID == rhs->as<FuncObject>()->executorID &&
        codePointer == rhs->as<FuncObject>()->codePointer
    );
}

FuncObject::operator bool() {
    return true;
}

void FuncObject::markReachables(uint8_t gcVal) {
    for(auto & kv : captures) {
        if(kv.second && kv.second->gcMarking != gcVal) {
            kv.second->gcMarking = gcVal;
            kv.second->markReachables(gcVal);
        }
    }
}
