#pragma once

#include "Object.hpp"

namespace ws {

namespace vm2 {

    struct WRefObject : public Object {
        std::weak_ptr<Object> ref;

        WRefObject(): Object(TypeWeakReference) {}
        WRefObject(RValue ref): Object(TypeWeakReference), ref(ref) {}

        virtual std::string toString();
        virtual RValue dCopy();
        virtual RValue opDeref();
        virtual RValue fcDeref();
        virtual RValue operator==(RValue rhs);
        virtual operator bool();
    };

}

}
