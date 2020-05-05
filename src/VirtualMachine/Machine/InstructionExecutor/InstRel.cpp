#include "Executor.hpp"
#include "Machine.hpp"
#include "TypeUtil.hpp"

#include <iostream>
#include <functional>
#include <cassert>

using namespace ws::vm;

static bool operator < (const GeneralDataNode & a, const GeneralDataNode & b);
static bool operator == (const GeneralDataNode & a, const GeneralDataNode & b);

bool Executor::lt() {
    auto rhs = machine->Pop();
    auto lhs = machine->Pop();

    AssertRVal(lhs, machine, "le");
    AssertRVal(rhs, machine, "le");

    try {
        auto result = lhs.value.rval < rhs.value.rval;
        machine->Push(GeneralDataNode(GeneralDataNode::TypeBool, std::make_shared<DataNodeBool>(result)));
    } catch (std::runtime_error & e) {
        machine->ReportError(std::string("lt: ") + e.what());
    }

    return true;
}

bool Executor::lte() {
    auto rhs = machine->Pop();
    auto lhs = machine->Pop();

    AssertRVal(lhs, machine, "le");
    AssertRVal(rhs, machine, "le");

    try {
        auto result = lhs.value.rval < rhs.value.rval || lhs.value.rval == rhs.value.rval;
        machine->Push(GeneralDataNode(GeneralDataNode::TypeBool, std::make_shared<DataNodeBool>(result)));
    } catch (std::runtime_error & e) {
        machine->ReportError(std::string("lt: ") + e.what());
    }

    return true;
}

bool Executor::gt() {
    auto rhs = machine->Pop();
    auto lhs = machine->Pop();

    AssertRVal(lhs, machine, "le");
    AssertRVal(rhs, machine, "le");

    try {
        auto result = !(lhs.value.rval < rhs.value.rval) && !(lhs.value.rval == rhs.value.rval);
        machine->Push(GeneralDataNode(GeneralDataNode::TypeBool, std::make_shared<DataNodeBool>(result)));
    } catch (std::runtime_error & e) {
        machine->ReportError(std::string("lt: ") + e.what());
    }

    return true;
}

bool Executor::gte() {
    auto rhs = machine->Pop();
    auto lhs = machine->Pop();

    AssertRVal(lhs, machine, "le");
    AssertRVal(rhs, machine, "le");

    try {
        auto result = !(lhs.value.rval < rhs.value.rval);
        machine->Push(GeneralDataNode(GeneralDataNode::TypeBool, std::make_shared<DataNodeBool>(result)));
    } catch (std::runtime_error & e) {
        machine->ReportError(std::string("lt: ") + e.what());
    }

    return true;
}


// ----------------------------- Utility Functions -----------------------------
static bool operator < (std::shared_ptr<DataNodeInt> a, std::shared_ptr<DataNodeInt> b) {
    return a->value < b->value;
}

static bool operator == (std::shared_ptr<DataNodeInt> a, std::shared_ptr<DataNodeInt> b) {
    return a->value == b->value;
}

static bool operator < (std::shared_ptr<DataNodeFloat> a, std::shared_ptr<DataNodeFloat> b) {
    return a->value < b->value;
}

static bool operator == (std::shared_ptr<DataNodeFloat> a, std::shared_ptr<DataNodeFloat> b) {
    return a->value == b->value;
}

static bool operator < (std::shared_ptr<DataNodeStr> a, std::shared_ptr<DataNodeStr> b) {
    return a->value < b->value;
}

static bool operator == (std::shared_ptr<DataNodeStr> a, std::shared_ptr<DataNodeStr> b) {
    return a->value == b->value;
}

static bool operator < (const GeneralDataNode & a, const GeneralDataNode & b) {
    if(a.type == GeneralDataNode::TypeInt && b.type == GeneralDataNode::TypeInt) {
        return std::dynamic_pointer_cast<DataNodeInt>(a.data)->value < std::dynamic_pointer_cast<DataNodeInt>(b.data)->value;
    }

    if(a.type == GeneralDataNode::TypeFloat && b.type == GeneralDataNode::TypeFloat) {
        return std::dynamic_pointer_cast<DataNodeFloat>(a.data)->value < std::dynamic_pointer_cast<DataNodeFloat>(b.data)->value;
    }

    if(a.type == GeneralDataNode::TypeString && b.type == GeneralDataNode::TypeString) {
        return std::dynamic_pointer_cast<DataNodeStr>(a.data)->value < std::dynamic_pointer_cast<DataNodeStr>(b.data)->value;
    }

    throw std::runtime_error("relation operations can only apply to int, float or str.");
}

static bool operator == (const GeneralDataNode & a, const GeneralDataNode & b) {
    if(a.type == GeneralDataNode::TypeInt && b.type == GeneralDataNode::TypeInt) {
        return std::dynamic_pointer_cast<DataNodeInt>(a.data) == std::dynamic_pointer_cast<DataNodeInt>(b.data);
    }

    if(a.type == GeneralDataNode::TypeFloat && b.type == GeneralDataNode::TypeFloat) {
        return std::dynamic_pointer_cast<DataNodeFloat>(a.data) == std::dynamic_pointer_cast<DataNodeFloat>(b.data);
    }

    if(a.type == GeneralDataNode::TypeString && b.type == GeneralDataNode::TypeString) {
        return std::dynamic_pointer_cast<DataNodeStr>(a.data) == std::dynamic_pointer_cast<DataNodeStr>(b.data);
    }

    throw std::runtime_error("relation operations can only apply to int, float or str.");
}
