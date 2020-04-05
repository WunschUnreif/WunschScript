#include "Executor.hpp"
#include "Machine.hpp"
#include "TypeUtil.hpp"

#include <cassert>

using namespace ws::vm;

bool Executor::proc(int64_t arg) {
    return jmp(arg);
}

bool Executor::endps() {
    currentScopePathStack.pop();

    return true;
}

bool Executor::endp() {
    Value nilval(GeneralDataNode(GeneralDataNode::TypeNil, std::make_shared<DataNodeNil>()));

    machine->Push(nilval);

    assert(&machine->workerExecutors.top() == this);
    machine->currentWorkerFinished = true;

    return false;
}

bool Executor::ret() {
    machine->currentWorkerFinished = true;

    return false;
}
