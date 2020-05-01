#include "Executor.hpp"
#include "Machine.hpp"
#include "TypeUtil.hpp"

#include <iostream>
#include <functional>
#include <cassert>

using namespace ws::vm;


static GeneralDataNode DoArithmeticCalculationOnFloat(
    GeneralDataNode & lhs, GeneralDataNode & rhs, std::function<double(double, double)> op);

static GeneralDataNode DoArithmeticCalculationOnInt(
    GeneralDataNode & lhs, GeneralDataNode & rhs, std::function<int64_t(int64_t, int64_t)> op);

/**
 * Addition:
 *  1. list + any
 *  2. int + int 
 *  3. float + float 
 *  4. str + str 
 */
bool Executor::add() {
    auto rhs = machine->Pop();
    auto lhs = machine->Pop();

    AssertRVal(lhs, machine, "add");
    AssertRVal(rhs, machine, "add");

    if(TypeIs(lhs, GeneralDataNode::TypeList)) {
        GeneralDataNode newList(GeneralDataNode::TypeList, std::make_shared<DataNodeList>());

        // shallow copy:
        std::dynamic_pointer_cast<DataNodeList>(newList.data)->value = 
            std::dynamic_pointer_cast<DataNodeList>(lhs.value.rval.data)->value;

        std::dynamic_pointer_cast<DataNodeList>(newList.data)->value.push_back(rhs.value.rval);

        machine->Push(newList);
        return true;
    }

    if(TypeIs(lhs, GeneralDataNode::TypeInt) && TypeIs(rhs, GeneralDataNode::TypeInt)) {
        machine->Push(DoArithmeticCalculationOnInt(
            lhs.value.rval, rhs.value.rval,
            [](int64_t a, int64_t b) { return a + b; }
        ));
        return true;
    }

    if(TypeIs(lhs, GeneralDataNode::TypeFloat) && TypeIs(rhs, GeneralDataNode::TypeFloat)) {
        machine->Push(DoArithmeticCalculationOnFloat(
            lhs.value.rval, rhs.value.rval,
            [](double a, double b) { return a + b; }
        ));
        return true;
    }

    if(TypeIs(lhs, GeneralDataNode::TypeString) && TypeIs(rhs, GeneralDataNode::TypeString)) {
        auto lvalue = std::dynamic_pointer_cast<DataNodeStr>(lhs.value.rval.data)->value;
        auto rvalue = std::dynamic_pointer_cast<DataNodeStr>(rhs.value.rval.data)->value;

        machine->Push(GeneralDataNode(GeneralDataNode::TypeString, std::make_shared<DataNodeStr>(lvalue + rvalue)));
        return true;
    }
    
    machine->ReportError("add: type error.");
    return true;
}

bool Executor::sub() {
    auto rhs = machine->Pop();
    auto lhs = machine->Pop();

    AssertRVal(lhs, machine, "sub");
    AssertRVal(rhs, machine, "sub");

    if(TypeIs(lhs, GeneralDataNode::TypeInt) && TypeIs(rhs, GeneralDataNode::TypeInt)) {
        machine->Push(DoArithmeticCalculationOnInt(
            lhs.value.rval, rhs.value.rval,
            [](int64_t a, int64_t b) { return a - b; }
        ));
        return true;
    }

    if(TypeIs(lhs, GeneralDataNode::TypeFloat) && TypeIs(rhs, GeneralDataNode::TypeFloat)) {
        machine->Push(DoArithmeticCalculationOnFloat(
            lhs.value.rval, rhs.value.rval,
            [](double a, double b) { return a - b; }
        ));
        return true;
    }
    
    machine->ReportError("sub: type error.");
    return true;
}

bool Executor::div() {
    auto rhs = machine->Pop();
    auto lhs = machine->Pop();

    AssertRVal(lhs, machine, "div");
    AssertRVal(rhs, machine, "div");

    if(TypeIs(lhs, GeneralDataNode::TypeInt) && TypeIs(rhs, GeneralDataNode::TypeInt)) {
        machine->Push(DoArithmeticCalculationOnInt(
            lhs.value.rval, rhs.value.rval,
            [](int64_t a, int64_t b) { return a / b; }
        ));
        return true;
    }

    if(TypeIs(lhs, GeneralDataNode::TypeFloat) && TypeIs(rhs, GeneralDataNode::TypeFloat)) {
        machine->Push(DoArithmeticCalculationOnFloat(
            lhs.value.rval, rhs.value.rval,
            [](double a, double b) { return a / b; }
        ));
        return true;
    }
    
    machine->ReportError("div: type error.");
    return true;
}

bool Executor::rem() {
    auto rhs = machine->Pop();
    auto lhs = machine->Pop();

    AssertRVal(lhs, machine, "rem");
    AssertRVal(rhs, machine, "rem");

    if(TypeIs(lhs, GeneralDataNode::TypeInt) && TypeIs(rhs, GeneralDataNode::TypeInt)) {
        machine->Push(DoArithmeticCalculationOnInt(
            lhs.value.rval, rhs.value.rval,
            [](int64_t a, int64_t b) { return a % b; }
        ));
        return true;
    }
    
    machine->ReportError("rem: type error.");
    return true;
}

// ----------------------------- Utility Functions -----------------------------

static GeneralDataNode DoArithmeticCalculationOnInt(
    GeneralDataNode & lhs, GeneralDataNode & rhs, std::function<int64_t(int64_t, int64_t)> op) {
    auto lvalue = std::dynamic_pointer_cast<DataNodeInt>(lhs.data)->value;
    auto rvalue = std::dynamic_pointer_cast<DataNodeInt>(rhs.data)->value;
    
    return GeneralDataNode(GeneralDataNode::TypeInt, std::make_shared<DataNodeInt>(op(lvalue, rvalue)));
}

static GeneralDataNode DoArithmeticCalculationOnFloat(
    GeneralDataNode & lhs, GeneralDataNode & rhs, std::function<double(double, double)> op) {
    auto lvalue = std::dynamic_pointer_cast<DataNodeFloat>(lhs.data)->value;
    auto rvalue = std::dynamic_pointer_cast<DataNodeFloat>(rhs.data)->value;
    
    return GeneralDataNode(GeneralDataNode::TypeFloat, std::make_shared<DataNodeFloat>(op(lvalue, rvalue)));
}
