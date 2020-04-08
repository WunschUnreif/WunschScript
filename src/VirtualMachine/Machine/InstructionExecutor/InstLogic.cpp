#include "Executor.hpp"
#include "Machine.hpp"
#include "TypeUtil.hpp"

#include <iostream>
#include <cassert>

using namespace ws::vm;

bool Executor::lnot() {
    auto top = machine->Pop();

    AssertRVal(top, machine, "lnot");
    AssertTypeIs(top, GeneralDataNode::TypeBool, machine, "lnot");

    auto value = std::dynamic_pointer_cast<DataNodeBool>(top.value.rval.data)->value;
    machine->Push(GeneralDataNode(GeneralDataNode::TypeBool, std::make_shared<DataNodeBool>(!value)));

    return true;
}

bool Executor::land() {
    auto rhs = machine->Pop();
    auto lhs = machine->Pop();

    AssertRVal(lhs, machine, "land");
    AssertRVal(rhs, machine, "land");

    AssertTypeIs(lhs, GeneralDataNode::TypeBool, machine, "land");
    AssertTypeIs(rhs, GeneralDataNode::TypeBool, machine, "land");

    auto valueL = std::dynamic_pointer_cast<DataNodeBool>(lhs.value.rval.data)->value;
    auto valueR = std::dynamic_pointer_cast<DataNodeBool>(rhs.value.rval.data)->value;

    machine->Push(GeneralDataNode(GeneralDataNode::TypeBool, std::make_shared<DataNodeBool>(valueL && valueR)));

    return true;
}

bool Executor::lor() {
    auto rhs = machine->Pop();
    auto lhs = machine->Pop();

    AssertRVal(lhs, machine, "lor");
    AssertRVal(rhs, machine, "lor");

    AssertTypeIs(lhs, GeneralDataNode::TypeBool, machine, "lor");
    AssertTypeIs(rhs, GeneralDataNode::TypeBool, machine, "lor");

    auto valueL = std::dynamic_pointer_cast<DataNodeBool>(lhs.value.rval.data)->value;
    auto valueR = std::dynamic_pointer_cast<DataNodeBool>(rhs.value.rval.data)->value;

    machine->Push(GeneralDataNode(GeneralDataNode::TypeBool, std::make_shared<DataNodeBool>(valueL || valueR)));

    return true;
}
