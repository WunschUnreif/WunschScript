#include "TypeUtil.hpp"

using namespace ws;
using namespace ws::vm;

void vm::AssertLVal(const Value & val, Machine * mach, const std::string & inst) {
    if(!val.isLval) {
        mach->ReportError(inst + ": expect left value.");
    }
}

void vm::AssertRVal(const Value & val, Machine * mach, const std::string & inst) {
    if(val.isLval) {
        mach->ReportError(inst + ": expect right value.");
    }
}

GeneralDataNode::DataType vm::TypeOf(const Value & val) {
    return val.isLval ? val.value.lval->type : val.value.rval.type;
}

bool vm::TypeIs(const Value & val, GeneralDataNode::DataType expect) {
    return TypeOf(val) == expect;
}

void vm::AssertTypeIs(const Value & val, GeneralDataNode::DataType expect, Machine * mach, const std::string & inst) {
    if(!TypeIs(val, expect)) {
        mach->ReportError(inst + ": type assertion failed.");
    }
}
