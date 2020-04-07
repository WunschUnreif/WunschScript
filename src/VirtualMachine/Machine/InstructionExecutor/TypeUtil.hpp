#pragma once 

#include "GeneralDataNode.hpp"
#include "DataNode.hpp"
#include "Machine.hpp"

namespace ws {

namespace vm {

    void AssertLVal(const Value & val, Machine * mach, const std::string & inst);
    void AssertRVal(const Value & val, Machine * mach, const std::string & inst);

    GeneralDataNode::DataType TypeOf(const Value & val);
    bool TypeIs(const Value & val, GeneralDataNode::DataType expect);
    void AssertTypeIs(const Value & val, GeneralDataNode::DataType expect, Machine * mach, const std::string & inst);

    bool DictHasAttribute(const Value & val, const std::string & attribute);

}

}
