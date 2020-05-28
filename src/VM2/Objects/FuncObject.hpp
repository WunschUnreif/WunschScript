#pragma once 

#include <vector>
#include <map>
#include "Object.hpp"

namespace ws {

namespace vm2 {

    struct FuncObject : public Object {
        size_t executorID;
        size_t codePointer;

        std::weak_ptr<Object> contextThis;

        std::vector<std::string> paramNames;
        bool withArrTail = false;
        std::string arrParamName;

        std::map<std::string, RValue> captures;

        FuncObject(): Object(TypeFunc) {}
        FuncObject(size_t exeID, size_t codePointer)
            : Object(TypeFunc), executorID(exeID), codePointer(codePointer) {}

        virtual std::string toString();
        virtual RValue dCopy();
        virtual RValue operator==(RValue rhs);
        virtual operator bool();

        virtual void markReachables(uint8_t gcVal);
    };

}

}
