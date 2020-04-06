#include "Executor.hpp"
#include "Machine.hpp"
#include "TypeUtil.hpp"

#include <iostream>
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

bool Executor::func() {
    auto funcNode = std::make_shared<DataNodeFunc>();
    Value funcVal(GeneralDataNode(GeneralDataNode::TypeFunc, funcNode));

    funcNode->executorID = executorID;
    funcNode->startOffset = codePointer + vm::OpCodeSize + (vm::OpCodeSize + vm::OpArgSize);
                            // skip:          func                      proc...             -> scope...

    machine->Push(funcVal);

    return true;
}

bool Executor::param(const std::string & arg) {
    auto top = machine->Top();

    AssertRVal(top, machine, "param");
    AssertTypeIs(top, GeneralDataNode::TypeFunc, machine, "param");

    auto funcNode = std::dynamic_pointer_cast<DataNodeFunc>(top.value.rval.data);

    funcNode->paramNames.push_back(arg);

    return true;
}

bool Executor::arrparam(const std::string & arg) {
    auto top = machine->Top();

    AssertRVal(top, machine, "param");
    AssertTypeIs(top, GeneralDataNode::TypeFunc, machine, "param");

    auto funcNode = std::dynamic_pointer_cast<DataNodeFunc>(top.value.rval.data);

    if(funcNode->withArrTail) {
        machine->ReportError("arrparam: duplicated arr-tail parameter.");
    }

    funcNode->withArrTail = true;
    funcNode->arrName = arg;

    return true;
}

bool Executor::precall() {
    auto top = machine->Top();

    AssertRVal(top, machine, "precall");
    AssertTypeIs(top, GeneralDataNode::TypeFunc, machine, "precall");

    precallStack.emplace();

    return true;
}

bool Executor::arg() {
    auto top = machine->Pop();

    AssertRVal(top, machine, "arg");
    precallStack.top().emplace_back(top.value.rval);

    return true;
}

bool Executor::call() {
    auto top = machine->Pop();

    std::cout << top.value.rval.ToString() << std::endl;

    AssertRVal(top, machine, "call");
    
    if(TypeIs(top, GeneralDataNode::TypeFunc)) {
        auto funcNode = std::dynamic_pointer_cast<DataNodeFunc>(top.value.rval.data);

        // construct a executor
        machine->workerExecutors.emplace(machine->metaExecutors[funcNode->executorID]);
        auto & funcExe = machine->workerExecutors.top();

        // put the start offset
        funcExe.codePointer = funcNode->startOffset;

        // register `this`
        funcExe.thisDict = funcNode->thisDict;

        // bind the captures
        for(size_t i = 0; i < funcNode->captureIDs.size(); ++i) {
            funcExe.bindingPour[funcNode->captureIDs[i]] = funcNode->captureVals[i];
        }

        // bind the arguments
        if(precallStack.top().size() < funcNode->paramNames.size()) {
            machine->ReportError("call: arguments too few.");
        }

        for(size_t i = 0; i < funcNode->paramNames.size(); ++i) {
            funcExe.bindingPour[funcNode->paramNames[i]] = precallStack.top()[i];
        }

        // bind the arr-argument
        if(funcNode->withArrTail) {
            auto arrNode = std::make_shared<DataNodeList>();
            GeneralDataNode arr(GeneralDataNode::TypeList, arrNode);

            for(size_t i = funcNode->paramNames.size(); i < precallStack.top().size(); ++i) {
                arrNode->value.emplace_back(precallStack.top()[i]);
            }

            funcExe.bindingPour[funcNode->arrName] = arr;
        } else {
            if(precallStack.top().size() != funcNode->paramNames.size()) {
                machine->ReportError("call: arguments too many.");
            }
        }

        // pop precall stack
        precallStack.pop();
        return false;
    } else if(TypeIs(top, GeneralDataNode::TypeSystemFunc)) {
        auto sysfunc = std::dynamic_pointer_cast<DataNodeSystemFunc>(top.value.rval.data)->impl;

        machine->Push(Value(sysfunc(precallStack.top(), *machine, *this)));
        precallStack.pop();

        return true;
    }

    machine->ReportError("call: not a function.");
    return true;
}

bool Executor::bind(const std::string & arg) {
    auto top = machine->Top();

    AssertRVal(top, machine, "bind");
    AssertTypeIs(top, GeneralDataNode::TypeFunc, machine, "bind");

    auto funcNode = std::dynamic_pointer_cast<DataNodeFunc>(top.value.rval.data);
    auto captureValue = scopeDirectory->Access(currentScopePathStack.top(), arg);

    funcNode->captureIDs.push_back(arg);
    funcNode->captureVals.push_back(captureValue.value.rval);

    return true;
}

bool Executor::ithis() {
    if(thisDict.expired()) {
        machine->ReportError("this: this already expired.");
    }

    machine->Push(GeneralDataNode(GeneralDataNode::TypeDict, thisDict.lock()));
    return true;
}
