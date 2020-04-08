#include "Executor.hpp"
#include "Machine.hpp"
#include "TypeUtil.hpp"

#include <iostream>
#include <cassert>

using namespace ws::vm;

// ---------------------------- ACCID & ACCIDL ----------------------------
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

// ---------------------------- ACCESS ----------------------------

static void AccessListWithInt(Value & lhs, Value & rhs, Machine * machine);
static void AccessStrWithInt(Value & lhs, Value & rhs, Machine * machine);
static void AccessStrWithList(Value & lhs, Value & rhs, Machine * machine);
static void AccessDictWithStr(Value & lhs, Value & rhs, Machine * machine);

bool Executor::access() {
    auto rhs = machine->Pop();
    auto lhs = machine->Pop();

    AssertRVal(lhs, machine, "access");
    AssertRVal(rhs, machine, "access");

    // 1. list[int]
    if(TypeIs(lhs, GeneralDataNode::TypeList)) {    
        AssertTypeIs(rhs, GeneralDataNode::TypeInt, machine, "access");
        AccessListWithInt(lhs, rhs, machine);

        return true;
    } 

    // 2. str[int] | str[list[int]]
    if(TypeIs(lhs, GeneralDataNode::TypeString)) {   
        if(TypeIs(rhs, GeneralDataNode::TypeInt)) {     
            // str[int]
            AccessStrWithInt(lhs, rhs, machine);

            return true;
        } 
        
        if(TypeIs(rhs, GeneralDataNode::TypeList)) { 
            // str[list<int>]
            AccessStrWithList(lhs, rhs, machine);

            return true;
        }
        
        machine->ReportError("access: must be str[int] | str[list<int>]");
    } 
    
    // 3. dict[str]
    if(TypeIs(lhs, GeneralDataNode::TypeDict)) {
        AssertTypeIs(rhs, GeneralDataNode::TypeString, machine, "access");
        AccessDictWithStr(lhs, rhs, machine);

        return true;
    }
    
    machine->ReportError("access: type error.");
    return true;
}

static void AccessListWithInt(Value & lhs, Value & rhs, Machine * machine) {
    auto & list = std::dynamic_pointer_cast<DataNodeList>(lhs.value.rval.data)->value;
    auto index = std::dynamic_pointer_cast<DataNodeInt>(rhs.value.rval.data)->value;

    if(index < 0 || index >= list.size()) {
        machine->ReportError("access: index out of range.");
    }

    machine->Push(list[index]);
}

static void AccessStrWithInt(Value & lhs, Value & rhs, Machine * machine) {
    auto & str = std::dynamic_pointer_cast<DataNodeStr>(lhs.value.rval.data)->value;
    auto index = std::dynamic_pointer_cast<DataNodeInt>(rhs.value.rval.data)->value;

    if(index < 0 || index >= str.length()) {
        machine->ReportError("access: index out of range.");
    }

    machine->Push(GeneralDataNode(
        GeneralDataNode::TypeString, 
        std::make_shared<DataNodeStr>(str.substr(index, 1))
    ));
}

static void AccessStrWithList(Value & lhs, Value & rhs, Machine * machine) {
    auto & str = std::dynamic_pointer_cast<DataNodeStr>(lhs.value.rval.data)->value;
    auto & list = std::dynamic_pointer_cast<DataNodeList>(rhs.value.rval.data)->value;
    std::string resultStr = "";

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
}

static void AccessDictWithStr(Value & lhs, Value & rhs, Machine * machine) {
    auto & dict = std::dynamic_pointer_cast<DataNodeDict>(lhs.value.rval.data)->value;
    auto & name = std::dynamic_pointer_cast<DataNodeStr>(rhs.value.rval.data)->value;
    auto iter = dict.find(name);

    if(iter == dict.end()) {
        machine->ReportError("access: attribute doesn't exist.");
    }
    machine->Push(iter->second);
}

// ---------------------------- ACCESSL ----------------------------

static void AccessLvalListWithInt(Value & lhs, Value & rhs, Machine * machine);
static void AccessLvalDictWithStr(Value & lhs, Value & rhs, Machine * machine);

bool Executor::accessL() {
    auto rhs = machine->Pop();
    auto lhs = machine->Pop();

    AssertRVal(lhs, machine, "accessL");
    AssertRVal(rhs, machine, "accessL");

    // 1. list [int]
    if(TypeIs(lhs, GeneralDataNode::TypeList)) {
        AssertTypeIs(rhs, GeneralDataNode::TypeInt, machine, "accessL");
        AccessLvalListWithInt(lhs, rhs, machine);

        return true;
    }

    // 2. dict [str]
    if(TypeIs(lhs, GeneralDataNode::TypeDict)) {
        AssertTypeIs(rhs, GeneralDataNode::TypeString, machine, "accessL");
        AccessLvalDictWithStr(lhs, rhs, machine);

        return true;
    }

    machine->ReportError("accessL: type error.");

    return true;
}

static void AccessLvalListWithInt(Value & lhs, Value & rhs, Machine * machine) {
    auto & list = std::dynamic_pointer_cast<DataNodeList>(lhs.value.rval.data)->value;
    auto index = std::dynamic_pointer_cast<DataNodeInt>(rhs.value.rval.data)->value;

    if(index < 0) {
        machine->ReportError("accessL: index out of range.");
    }

    if(index > list.size()) {
        list.resize(index + 20);
    }

    machine->Push(&list[index]);
}

static void AccessLvalDictWithStr(Value & lhs, Value & rhs, Machine * machine) {
    auto & dict = std::dynamic_pointer_cast<DataNodeDict>(lhs.value.rval.data)->value;
    auto & name = std::dynamic_pointer_cast<DataNodeStr>(rhs.value.rval.data)->value;

    machine->Push(&dict[name]);
}
