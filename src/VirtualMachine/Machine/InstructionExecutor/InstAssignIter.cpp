#include "Executor.hpp"
#include "Machine.hpp"
#include "TypeUtil.hpp"

#include <iostream>
#include <cassert>

using namespace ws::vm;

bool Executor::assign() {
    auto rVal = machine->Pop();
    auto lVal = machine->Pop();

    AssertLVal(lVal, machine, "assign");
    AssertRVal(rVal, machine, "assign");

    *lVal.value.lval = rVal.value.rval;

    return true;
}

bool Executor::iter(const std::string & arg) {
    auto iteratee = machine->Pop();

    AssertRVal(iteratee, machine, "iter");

    forloopStack.emplace(arg, iteratee.value.rval);
    auto & topFrame = forloopStack.top();

    if(TypeIs(iteratee, GeneralDataNode::TypeDict)) {
        topFrame.iteratingDict = true;
        auto dictNode = std::dynamic_pointer_cast<DataNodeDict>(iteratee.value.rval.data);

        topFrame.dictIterator = dictNode->value.begin();
        topFrame.dictEnding = dictNode->value.end();

        bindingPour[arg] = 
            GeneralDataNode(GeneralDataNode::TypeString,  
                std::make_shared<DataNodeStr>(topFrame.dictIterator->first)
            );
        
        machine->Push(GeneralDataNode(GeneralDataNode::TypeBool, std::make_shared<DataNodeBool>(dictNode->value.empty())));
    } else if(TypeIs(iteratee, GeneralDataNode::TypeList)) {
        topFrame.iteratingList = true;
        auto listNode = std::dynamic_pointer_cast<DataNodeList>(iteratee.value.rval.data);

        topFrame.listIterator = listNode->value.begin();
        topFrame.listEnding = listNode->value.end();

        bindingPour[arg] = *topFrame.listIterator;

        machine->Push(GeneralDataNode(GeneralDataNode::TypeBool, std::make_shared<DataNodeBool>(listNode->value.empty())));
    } else {
        bindingPour[arg] = topFrame.iteratee;

        machine->Push(GeneralDataNode(GeneralDataNode::TypeBool, std::make_shared<DataNodeBool>(false)));
    }

    return true;
}
