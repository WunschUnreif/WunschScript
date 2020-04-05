#include "Executor.hpp"
#include "Machine.hpp"

using namespace ws::vm;

bool Executor::immN() {
    Value result(GeneralDataNode(GeneralDataNode::TypeNil, std::make_shared<DataNodeNil>()));

    machine->Push(result);

    return true;
}

bool Executor::immI(int64_t arg) {
    Value result(GeneralDataNode(GeneralDataNode::TypeInt, std::make_shared<DataNodeInt>(arg)));

    machine->Push(result);

    return true;
}

bool Executor::immF(double arg) {
    Value result(GeneralDataNode(GeneralDataNode::TypeFloat, std::make_shared<DataNodeFloat>(arg)));

    machine->Push(result);

    return true;
}

bool Executor::immB(bool arg) {
    Value result(GeneralDataNode(GeneralDataNode::TypeBool, std::make_shared<DataNodeBool>(arg)));

    machine->Push(result);

    return true;
}

bool Executor::immS(const std::string & arg) {
    Value result(GeneralDataNode(GeneralDataNode::TypeString, std::make_shared<DataNodeStr>(arg)));

    machine->Push(result);

    return true;
}

bool Executor::immL() {
    Value result(GeneralDataNode(GeneralDataNode::TypeList, std::make_shared<DataNodeList>()));

    machine->Push(result);

    return true;
}

bool Executor::immD() {
    Value result(GeneralDataNode(GeneralDataNode::TypeDict, std::make_shared<DataNodeDict>()));

    machine->Push(result);

    return true;
}

bool Executor::pop() {
    machine->Pop();
    return true;
}
