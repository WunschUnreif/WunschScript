#pragma once

#include <exception>

namespace ws {

namespace vm2 {

    /**
     * @brief The required operation on the object is not allowed.
     *        e.g. get a value from undefined.
     */
    struct OperationNotAllowed: public std::exception {};

    /**
     * @brief To finish the operation, computation must be transferred.
     *        usually an overriden method of some dict.
     */
    struct RequireComputationTransfer: public std::exception {
        size_t executorID;
        size_t codePointer;

        RequireComputationTransfer(size_t eid, size_t pointer)
            : executorID(eid), codePointer(pointer) {}
    };

    /**
     * @brief The required operation doesn't fit this object.
     *        e.g. add a dict on a str.
     */
    struct TypeError: public std::exception {};

}

}
