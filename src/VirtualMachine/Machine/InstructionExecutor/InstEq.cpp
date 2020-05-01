#include "Executor.hpp"
#include "Machine.hpp"
#include "TypeUtil.hpp"

#include <iostream>
#include <cassert>

using namespace ws::vm;

bool Executor::eq() {
    auto rhs = machine->Pop();
    auto lhs = machine->Pop();

    AssertRVal(lhs, machine, "eq");
    AssertRVal(rhs, machine, "eq");

    machine->Push(GeneralDataNode(GeneralDataNode::TypeBool, std::make_shared<DataNodeBool>(
        lhs.value.rval.IsEqualTo(rhs.value.rval)
    )));

    return true;
}

bool Executor::ne() {
    auto rhs = machine->Pop();
    auto lhs = machine->Pop();

    AssertRVal(lhs, machine, "eq");
    AssertRVal(rhs, machine, "eq");

    machine->Push(GeneralDataNode(GeneralDataNode::TypeBool, std::make_shared<DataNodeBool>(
        !lhs.value.rval.IsEqualTo(rhs.value.rval)
    )));

    return true;
}
