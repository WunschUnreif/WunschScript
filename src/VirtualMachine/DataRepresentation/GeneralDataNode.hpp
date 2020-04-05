#pragma once

#include <memory>

#include "DataNodeBase.hpp"

namespace ws {

namespace vm {

    /**
     * @brief A linkage to any type of data.
     */
    struct GeneralDataNode {

        enum DataType {
            TypeUndefined,          // for uninitialized value 
            TypeNil,
            TypeBool,
            TypeInt, 
            TypeFloat,
            TypeString,
            TypeList,
            TypeDict,
            TypeFunc,
            TypeSystemFunc,
            TypeWeakReference
        } type = TypeUndefined;

        std::shared_ptr<DataNodeBase> data;

        GeneralDataNode() {}
        GeneralDataNode(DataType type, std::shared_ptr<DataNodeBase> data):
            type(type), data(data) {}

        std::string ToString();
        bool IsEqualTo(GeneralDataNode rhs);
        GeneralDataNode DeepCopy();

    };

    /**
     * @brief The value struct which is needed in the execution stack.
     */
    struct Value {
        bool isLval = false;
        struct StorageValue {
            GeneralDataNode * lval;
            GeneralDataNode rval;
        } value;

        Value(GeneralDataNode rval)
            { isLval = false; value.rval = rval; }

        Value(GeneralDataNode * lval)
            { isLval = true; value.lval = lval; }

    };

    typedef std::shared_ptr<Value> ValuePointer;

} // namespace vm

} // namespace ws
