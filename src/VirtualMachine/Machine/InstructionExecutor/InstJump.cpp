#include "Executor.hpp"
#include "Machine.hpp"

using namespace ws::vm;

bool Executor::jmp(int64_t arg) {
    codePointer += arg;
    return true;
}

bool Executor::jfalse(int64_t arg) {
    Value top = machine->Pop();

    if(!top.isLval && top.value.rval.type == GeneralDataNode::TypeBool) {
        if(std::dynamic_pointer_cast<DataNodeBool>(top.value.rval.data)->value == false) {
            codePointer += arg;
        }
    } else {
        machine->ReportError("jfalse: Condition is not bool.");
    }

    return true;
}

bool Executor::next(int64_t arg) {
    if(forloopStack.empty()) {
        machine->ReportError("next: Not in iterating mode.");
    }

    auto frame = forloopStack.top();

    if(frame.iteratingDict) {
        if(frame.dictIterator != frame.dictEnding) {
            // advance iterator; binding iterator var; jump;
            frame.dictIterator++;
            bindingPour[frame.iteratorName] = frame.dictIterator->second;
            codePointer += arg;
        } else {
            // end iterating;
            forloopStack.pop();
        }
    } else if(frame.iteratingList) {
        if(frame.listIterator != frame.listEnding) {
            // advance iterator; binding iterator var; jump;
            frame.listIterator++;
            bindingPour[frame.iteratorName] = *frame.listIterator;
            codePointer += arg;
        } else {
            // end iterating;
            forloopStack.pop();
        }
    } else {
        // iterating over non-iterable, just leave.
        forloopStack.pop();
    }

    return true;
}
