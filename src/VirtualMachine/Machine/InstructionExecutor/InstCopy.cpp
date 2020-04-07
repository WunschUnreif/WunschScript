#include "Executor.hpp"
#include "Machine.hpp"
#include "TypeUtil.hpp"

#include <iostream>
#include <cassert>

using namespace ws::vm;

bool Executor::copy() {
    auto & top = machine->Top();
    
    AssertRVal(top, machine, "copy");
    machine->Push(top);

    return true;
}

bool Executor::dcopy() {
    auto top = machine->Pop();
    
    AssertRVal(top, machine, "dcopy");
    try {
        machine->Push(top.value.rval.DeepCopy());
    } catch (std::runtime_error & e) {
        machine->ReportError(std::string("dcopy: ") + e.what());
    }

    return true;
}

bool Executor::wref() {
    auto top = machine->Pop();
    
    AssertRVal(top, machine, "wref");
    machine->Push(GeneralDataNode(GeneralDataNode::TypeWeakReference, std::make_shared<DataNodeWeakReference>(top.value.rval)));

    return true;
}

bool Executor::opderef() {
    auto top = machine->Pop();
    
    AssertRVal(top, machine, "opderef");
    AssertTypeIs(top, GeneralDataNode::TypeWeakReference, machine, "opderef");

    auto ref = std::dynamic_pointer_cast<DataNodeWeakReference>(top.value.rval.data);

    if(ref->ptr.expired()) {
        machine->Push(GeneralDataNode(GeneralDataNode::TypeNil, std::make_shared<DataNodeNil>()));
    } else {
        machine->Push(GeneralDataNode(ref->type, ref->ptr.lock()));
    }

    return true;
}

bool Executor::fcderef() {
    auto top = machine->Pop();
    
    AssertRVal(top, machine, "fcderef");
    AssertTypeIs(top, GeneralDataNode::TypeWeakReference, machine, "fcderef");

    auto ref = std::dynamic_pointer_cast<DataNodeWeakReference>(top.value.rval.data);

    if(ref->ptr.expired()) {
        machine->ReportError("fcderef: weak ref expired.");
    } else {
        machine->Push(GeneralDataNode(ref->type, ref->ptr.lock()));
    }

    return true;
}
