#include <cassert>

#include "Executor.hpp"
#include "Machine.hpp"

using namespace ws::vm;

Executor::Executor(const Executor & exe):
    machine(exe.machine),
    executorID(exe.executorID),
    bytecode(exe.bytecode),
    codePointer(exe.codePointer),
    filename(exe.filename),
    lineNoInFile(exe.lineNoInFile),
    scopeDirectory(exe.scopeDirectory),
    currentScopePath(exe.currentScopePath) 
{}

Executor Executor::operator=(const Executor & exe) {
    return Executor(exe);
}

void Executor::Execute() {
    bool canContinue = true;

    while(canContinue && codePointer >= 0 && codePointer < bytecode->GetAddressUpperBound()) {
        auto inst = bytecode->GetInstructionAt(codePointer);

        canContinue = ExecuteInstruction(inst);
    }

    if(codePointer < 0) {
        machine->ReportError("Negative code pointer.");
    }

    if(codePointer >= bytecode->GetAddressUpperBound()) {
        auto & exe = machine->workerExecutors.top();

        assert(&exe == this);
        machine->workerExecutors.pop();
    }
}

bool Executor::ExecuteInstruction(const Instruction & inst) {
    int64_t argI = inst.argument.argInt;
    bool argB    = inst.argument.argBool;
    double argF  = inst.argument.argFloat;
    const std::string & argS = inst.argString;

    switch(inst.opcode) {
    case UADD: return uadd();
    case USUB: return usub();

    case ADD: return add();
    case SUB: return sub();
    case MUL: return mul();
    case DIV: return div();
    case REM: return rem();

    case LT: return lt();
    case LTE: return lte();
    case GT: return gt();
    case GTE: return gte();

    case EQ: return eq();
    case NE: return ne();

    case BNOT: return bnot();
    case BAND: return band();
    case BXOR: return bxor();
    case BOR: return bor();

    case LNOT: return lnot();
    case LAND: return land();
    case LOR: return lor();

    case DCOPY: return dcopy();
    case COPY: return copy();
    case WREF: return wref();
    case OPDEREF: return opderef();
    case FCDEREF: return fcderef();

    case ACCESS: return access();
    case ACCESSL: return accessL();
    case THIS: return ithis();

    case FUNC: return func();
    case PRECALL: return precall();
    case ARG: return arg();
    case CALL: return call();

    case ASSIGN: return assign();
    case RET: return ret();
    case ENDP: return endp();
    case ENDPS: return endps();

    case IMMN: return immN();
    case IMML: return immL();
    case IMMD: return immD();

    case POP: return pop();


    case ACCID: return accid(argS);
    case ACCIDL: return accidL(argS);

    case IMMI: return immI(argI);
    case IMMF: return immF(argF);
    case IMMB: return immB(argB);
    case IMMS: return immS(argS);

    case PROC: return proc(argI);
    case PARAM: return param(argS);
    case ARRPARAM: return arrparam(argS);

    case BIND: return bind(argS);
    case NAME: return name(argS);
    case GET: return get(argS);
    case GETL: return getL(argS);
    case SET: return set(argS);

    case JFALSE: return jfalse(argI);
    case JMP: return jmp(argI);
    case NEXT: return next(argI);
    case ITER: return iter(argS);

    case SCOPE: return scope(argS);

    case FILE: return file(argS);
    case LINE: return line(argI);

    default: machine->ReportError("Unknown opcode."); return false;
    }
}
