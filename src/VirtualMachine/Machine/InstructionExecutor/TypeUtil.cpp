#include "TypeUtil.hpp"

using namespace ws;
using namespace ws::vm;

void vm::AssertLVal(Value & val, Machine * mach, const std::string & inst) {
    if(!val.isLval) {
        mach->ReportError(inst + ": expect left value.");
    }
}

void vm::AssertRVal(Value & val, Machine * mach, const std::string & inst) {
    if(val.isLval) {
        mach->ReportError(inst + ": expect right value.");
    }
}

GeneralDataNode::DataType vm::TypeOf(Value & val) {
    return val.isLval ? val.value.lval->type : val.value.rval.type;
}

bool vm::TypeIs(Value & val, GeneralDataNode::DataType expect) {
    return TypeOf(val) == expect;
}

void vm::AssertTypeIs(Value & val, GeneralDataNode::DataType expect, Machine * mach, const std::string & inst) {
    if(!TypeIs(val, expect)) {
        mach->ReportError(inst + ": type assertion failed.");
    }
}
