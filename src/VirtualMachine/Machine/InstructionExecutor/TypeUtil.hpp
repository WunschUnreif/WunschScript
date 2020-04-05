#pragma once 

#include "GeneralDataNode.hpp"
#include "DataNode.hpp"
#include "Machine.hpp"

namespace ws {

namespace vm {

    void AssertLVal(Value & val, Machine * mach, const std::string & inst);
    void AssertRVal(Value & val, Machine * mach, const std::string & inst);

    GeneralDataNode::DataType TypeOf(Value & val);
    bool TypeIs(Value & val, GeneralDataNode::DataType expect);
    void AssertTypeIs(Value & val, GeneralDataNode::DataType expect, Machine * mach, const std::string & inst);

}

}
