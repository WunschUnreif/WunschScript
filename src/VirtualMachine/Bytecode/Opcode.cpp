#include "Opcode.hpp"

using namespace ws::vm;

static const char * opNamesNoArg [] = {
    "uadd",
    "usub",
    "add",
    "sub",
    "mul",
    "div",
    "rem",
    "lt",
    "lte",
    "gt",
    "gte",
    "eq",
    "ne",
    "bnot",
    "band",
    "bxor",
    "bor",
    "lnot",
    "land",
    "lor",
    "dcopy",
    "copy",
    "wref",
    "opderef",
    "fcderef",
    "access",
    "accessL",
    "this",
    "func",
    "precall",
    "arg",
    "call",
    "assign",
    "ret",
    "endp",
    "endps",
    "immN",
    "immL",
    "immD"
};

static const char * opNamesWithArg [] = {
    "accid",
    "accidL",
    "immI",
    "immF",
    "immB",
    "immS",
    "proc",
    "param",
    "arrparam",
    "bind",
    "name",
    "get",
    "set",
    "jfalse",
    "jmp",
    "next",
    "iter",
    "scope",
    "file",
    "line"
};

std::string ws::vm::GetOpName(OpCode code) {
    if(OpCodeHasArgument(code)) {
        return opNamesWithArg[code - 128];
    } else {
        return opNamesNoArg[code];
    }
}

bool ws::vm::OpCodeHasArgument(OpCode code)  { return code & 0x80; }
