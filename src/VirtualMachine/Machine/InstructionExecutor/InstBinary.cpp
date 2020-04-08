#include "Executor.hpp"
#include "Machine.hpp"
#include "TypeUtil.hpp"

#include <iostream>
#include <cassert>

using namespace ws::vm;

bool Executor::bnot() {
    auto top = machine->Pop();

    AssertRVal(top, machine, "bnot");
    AssertTypeIs(top, GeneralDataNode::TypeInt, machine, "bnot");

    auto value = std::dynamic_pointer_cast<DataNodeInt>(top.value.rval.data)->value;
    machine->Push(GeneralDataNode(GeneralDataNode::TypeInt, std::make_shared<DataNodeInt>(~value)));

    return true;
}

bool Executor::band() {
    auto rhs = machine->Pop();
    auto lhs = machine->Pop();

    AssertRVal(lhs, machine, "band");
    AssertRVal(rhs, machine, "band");

    AssertTypeIs(lhs, GeneralDataNode::TypeInt, machine, "band");
    AssertTypeIs(rhs, GeneralDataNode::TypeInt, machine, "band");

    auto valueL = std::dynamic_pointer_cast<DataNodeInt>(lhs.value.rval.data)->value;
    auto valueR = std::dynamic_pointer_cast<DataNodeInt>(rhs.value.rval.data)->value;

    machine->Push(GeneralDataNode(GeneralDataNode::TypeInt, std::make_shared<DataNodeInt>(valueL & valueR)));

    return true;
}

bool Executor::bor() {
    auto rhs = machine->Pop();
    auto lhs = machine->Pop();

    AssertRVal(lhs, machine, "bor");
    AssertRVal(rhs, machine, "bor");

    AssertTypeIs(lhs, GeneralDataNode::TypeInt, machine, "bor");
    AssertTypeIs(rhs, GeneralDataNode::TypeInt, machine, "bor");

    auto valueL = std::dynamic_pointer_cast<DataNodeInt>(lhs.value.rval.data)->value;
    auto valueR = std::dynamic_pointer_cast<DataNodeInt>(rhs.value.rval.data)->value;

    machine->Push(GeneralDataNode(GeneralDataNode::TypeInt, std::make_shared<DataNodeInt>(valueL | valueR)));

    return true;
}

bool Executor::bxor() {
    auto rhs = machine->Pop();
    auto lhs = machine->Pop();

    AssertRVal(lhs, machine, "bxor");
    AssertRVal(rhs, machine, "bxor");

    AssertTypeIs(lhs, GeneralDataNode::TypeInt, machine, "bxor");
    AssertTypeIs(rhs, GeneralDataNode::TypeInt, machine, "bxor");

    auto valueL = std::dynamic_pointer_cast<DataNodeInt>(lhs.value.rval.data)->value;
    auto valueR = std::dynamic_pointer_cast<DataNodeInt>(rhs.value.rval.data)->value;

    machine->Push(GeneralDataNode(GeneralDataNode::TypeInt, std::make_shared<DataNodeInt>(valueL ^ valueR)));

    return true;
}
