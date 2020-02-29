#include <iostream>

#include <cassert>

#include "GeneralDataNode.hpp"

using namespace ws::asl;

std::string GeneralDataNode::ToString() {
    std::string result;

    switch(type) {
    case TypeUndefined:     result = "undefined()"                     ; break;
    case TypeNil:           result = "nil(" +    data->ToString() + ')'; break;
    case TypeBool:          result = "bool(" +   data->ToString() + ')'; break;
    case TypeInt:           result = "int(" +    data->ToString() + ')'; break;
    case TypeFloat:         result = "float(" +  data->ToString() + ')'; break;
    case TypeString:        result = "str(" +    data->ToString() + ')'; break;
    case TypeList:          result = "list(" +   data->ToString() + ')'; break;
    case TypeDict:          result = "dict(" +   data->ToString() + ')'; break;
    case TypeFunc:          result = "func(" +   data->ToString() + ')'; break;
    case TypeSystemFunc:    result = "sysfunc("+ data->ToString() + ')'; break;
    }

    return result;
}

bool GeneralDataNode::IsEqualTo(GeneralDataNode rhs) {
    if(type == rhs.type && data != nullptr) {
        assert(rhs.data != nullptr);
        
        return data->IsEqualTo(rhs.data);
    }

    /// type of undefined is always not equal to each other
    return false;
}

GeneralDataNode GeneralDataNode::DeepCopy() {
    GeneralDataNode result;
    result.type = type;
    if(data != nullptr) {
        result.data = data->DeepCopy();
    }

    return result;
}
