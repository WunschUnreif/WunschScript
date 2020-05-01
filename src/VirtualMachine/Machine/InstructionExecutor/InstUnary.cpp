#include "Executor.hpp"
#include "Machine.hpp"
#include "TypeUtil.hpp"

#include <iostream>
#include <cassert>

using namespace ws::vm;

bool Executor::uadd() {
    auto top = machine->Pop();

    AssertRVal(top, machine, "uadd");
    
    if(TypeIs(top, GeneralDataNode::TypeInt)) {
        auto value = std::dynamic_pointer_cast<DataNodeInt>(top.value.rval.data)->value;

        machine->Push(GeneralDataNode(GeneralDataNode::TypeInt, std::make_shared<DataNodeInt>(value)));
        return true;
    }

    if(TypeIs(top, GeneralDataNode::TypeFloat)) {
        auto value = std::dynamic_pointer_cast<DataNodeFloat>(top.value.rval.data)->value;

        machine->Push(GeneralDataNode(GeneralDataNode::TypeFloat, std::make_shared<DataNodeFloat>(value)));
        return true;
    }

    machine->ReportError("uadd: type must be int or float");
    return true;
}

bool Executor::usub() {
    auto top = machine->Pop();

    AssertRVal(top, machine, "usub");
    
    if(TypeIs(top, GeneralDataNode::TypeInt)) {
        auto value = std::dynamic_pointer_cast<DataNodeInt>(top.value.rval.data)->value;

        machine->Push(GeneralDataNode(GeneralDataNode::TypeInt, std::make_shared<DataNodeInt>(-value)));
        return true;
    }

    if(TypeIs(top, GeneralDataNode::TypeFloat)) {
        auto value = std::dynamic_pointer_cast<DataNodeFloat>(top.value.rval.data)->value;

        machine->Push(GeneralDataNode(GeneralDataNode::TypeFloat, std::make_shared<DataNodeFloat>(-value)));
        return true;
    }

    machine->ReportError("usub: type must be int or float");
    return true;
}
