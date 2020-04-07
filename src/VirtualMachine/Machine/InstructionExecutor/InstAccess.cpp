#include "Executor.hpp"
#include "Machine.hpp"
#include "TypeUtil.hpp"

#include <iostream>
#include <cassert>

using namespace ws::vm;

bool Executor::accid(const std::string & arg) {
    auto top = machine->Pop();

    AssertRVal(top, machine, "accid");
    AssertTypeIs(top, GeneralDataNode::TypeDict, machine, "accid");

    auto dictNode = std::dynamic_pointer_cast<DataNodeDict>(top.value.rval.data);
    auto iter = dictNode->value.find(arg);

    if(iter == dictNode->value.end()) {
        machine->ReportError("accid: attribute " + arg + " doesn't exist.");
    }

    machine->Push(iter->second);
    return true;
}

bool Executor::accidL(const std::string & arg) {
    auto top = machine->Pop();

    AssertRVal(top, machine, "accidL");
    AssertTypeIs(top, GeneralDataNode::TypeDict, machine, "accidL");

    auto dictNode = std::dynamic_pointer_cast<DataNodeDict>(top.value.rval.data);

    machine->Push(&(dictNode->value[arg]));
    return true;
}

bool Executor::access() {
    auto rhs = machine->Pop();
    auto lhs = machine->Pop();

    AssertRVal(lhs, machine, "access");
    AssertRVal(rhs, machine, "access");

    if(TypeIs(lhs, GeneralDataNode::TypeList)) {    // list[int]
        AssertTypeIs(rhs, GeneralDataNode::TypeInt, machine, "access");

        auto & list = std::dynamic_pointer_cast<DataNodeList>(lhs.value.rval.data)->value;
        auto index = std::dynamic_pointer_cast<DataNodeInt>(rhs.value.rval.data)->value;

        if(index < 0 || index >= list.size()) {
            machine->ReportError("access: index out of range.");
        }

        machine->Push(list[index]);

        return true;
    } else if(TypeIs(lhs, GeneralDataNode::TypeString)) {   // str[int], str[list[int]]
        if(TypeIs(rhs, GeneralDataNode::TypeInt)) {     // str[int]
            auto & str = std::dynamic_pointer_cast<DataNodeStr>(lhs.value.rval.data)->value;
            auto index = std::dynamic_pointer_cast<DataNodeInt>(rhs.value.rval.data)->value;

            if(index < 0 || index >= str.length()) {
                machine->ReportError("access: index out of range.");
            }

            machine->Push(GeneralDataNode(
                GeneralDataNode::TypeString, 
                std::make_shared<DataNodeStr>(str.substr(index, 1))
            ));

            return true;
        } else if(TypeIs(rhs, GeneralDataNode::TypeList)) { // str[list<int>]
            auto & str = std::dynamic_pointer_cast<DataNodeStr>(lhs.value.rval.data)->value;
            auto & list = std::dynamic_pointer_cast<DataNodeList>(rhs.value.rval.data)->value;
            auto resultStr = "";

            for(auto & gdn : list) {
                AssertTypeIs(gdn, GeneralDataNode::TypeInt, machine, "access");
                auto index = std::dynamic_pointer_cast<DataNodeInt>(gdn.data)->value;

                if(index < 0 || index >= str.length()) {
                    machine->ReportError("access: index out of range.");
                }
                resultStr += str[index];
            }

            machine->Push(GeneralDataNode(
                GeneralDataNode::TypeString, 
                std::make_shared<DataNodeStr>(resultStr)
            ));

            return true;
        } else {
            machine->ReportError("access: must be str[int] | str[list<int>]");
        }
    } else if(TypeIs(lhs, GeneralDataNode::TypeDict)) {
        AssertTypeIs(rhs, GeneralDataNode::TypeString, machine, "access");

        auto & dict = std::dynamic_pointer_cast<DataNodeDict>(lhs.value.rval.data)->value;
        auto & name = std::dynamic_pointer_cast<DataNodeStr>(rhs.value.rval.data)->value;
        auto iter = dict.find(name);

        if(iter == dict.end()) {
            machine->ReportError("access: attribute doesn't exist.");
        }
        machine->Push(iter->second);

        return true;
    } else {
        machine->ReportError("access: type wrong.");
    }
    
    return true;
}

// void AccessListWithInt(Value & lhs, Value & rhs) {

// }
