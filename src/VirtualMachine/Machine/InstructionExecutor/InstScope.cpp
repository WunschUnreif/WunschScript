#include <iostream>

#include "Executor.hpp"
#include "Machine.hpp"

#include "TypeUtil.hpp"

using namespace ws::vm;

bool Executor::scope(const std::string & arg) {
    scopeDirectory->PushScope(arg);
    currentScopePathStack.push(arg);

    if(!bindingPour.empty()) {
        scopeDirectory->PourBindings(arg, bindingPour);
        bindingPour.clear();
    }

    return true;
}

bool Executor::name(const std::string & arg) {
    scopeDirectory->InsertName(currentScopePathStack.top(), arg);

    return true;
}

bool Executor::get(const std::string & arg) {
    auto val = scopeDirectory->Access(currentScopePathStack.top(), arg);

    if(TypeIs(val, GeneralDataNode::TypeUndefined)) {
        machine->ReportError("get: undefined name " + arg);
    }

    machine->Push(val);

    return true;
}

bool Executor::getL(const std::string & arg) {
    auto val = scopeDirectory->Access(currentScopePathStack.top(), arg, true);

    AssertLVal(val, machine, "getL");
    machine->Push(val);

    return true;
}

bool Executor::set(const std::string & arg) {
    auto top = machine->Pop();

    AssertRVal(top, machine, "set");

    try {
        scopeDirectory->Bind(currentScopePathStack.top(), arg, top.value.rval);
    } catch (std::runtime_error & e) {
        machine->ReportError(std::string("set: ") + e.what());
    }

    return true;
}
