#include <iostream>
#include <cassert>

#include "Executor.hpp"
#include "Machine.hpp"

using namespace ws::vm;

Executor::Executor(const Executor & exe):
    machine(exe.machine),
    executorID(exe.executorID),
    bytecode(exe.bytecode),
    filename(exe.filename),
    scopeDirectory(exe.scopeDirectory)
{
    currentScopePathStack.push("/");
    IdentifyFilename();
}

Executor Executor::operator=(const Executor & exe) {
    return Executor(exe);
}

void Executor::IdentifyFilename() {
    if(!bytecode) {
        filename = "<unknown>";
    } else {
        auto firstInst = bytecode->GetInstructionAt(0);
        if(firstInst.opcode == FILE) {
            filename = firstInst.argString;
        } else {
            filename = "<unknown>";
        }
    }
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

void Executor::ExecuteSingleStep() {
    auto inst = bytecode->GetInstructionAt(codePointer);
    
    std::cout << "->" << codePointer << "@" << executorID << " of " 
                << filename << ":" << lineNoInFile << std::endl;
    std::cout << "\t" << inst.ToString(codePointer) << std::endl;

    machine->PrintStack();

    ExecuteInstruction(inst);

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

    codePointerAlreadyMoved = false;

    bool retval;

    switch(inst.opcode) {
    case UADD: retval = uadd(); break;
    case USUB: retval = usub(); break;

    case ADD: retval = add(); break;
    case SUB: retval = sub(); break;
    case MUL: retval = mul(); break;
    case DIV: retval = div(); break;
    case REM: retval = rem(); break;

    case LT: retval = lt(); break;
    case LTE: retval = lte(); break;
    case GT: retval = gt(); break;
    case GTE: retval = gte(); break;

    case EQ: retval = eq(); break;
    case NE: retval = ne(); break;

    case BNOT: retval = bnot(); break;
    case BAND: retval = band(); break;
    case BXOR: retval = bxor(); break;
    case BOR: retval = bor(); break;

    case LNOT: retval = lnot(); break;
    case LAND: retval = land(); break;
    case LOR: retval = lor(); break;

    case DCOPY: retval = dcopy(); break;
    case COPY: retval = copy(); break;
    case WREF: retval = wref(); break;
    case OPDEREF: retval = opderef(); break;
    case FCDEREF: retval = fcderef(); break;

    case ACCESS: retval = access(); break;
    case ACCESSL: retval = accessL(); break;
    case THIS: retval = ithis(); break;

    case FUNC: retval = func(); break;
    case PRECALL: retval = precall(); break;
    case ARG: retval = arg(); break;
    case CALL: retval = call(); break;

    case ASSIGN: retval = assign(); break;
    case RET: retval = ret(); break;
    case ENDP: retval = endp(); break;
    case ENDPS: retval = endps(); break;

    case IMMN: retval = immN(); break;
    case IMML: retval = immL(); break;
    case IMMD: retval = immD(); break;

    case POP: retval = pop(); break;


    case ACCID: retval = accid(argS); break;
    case ACCIDL: retval = accidL(argS); break;

    case IMMI: retval = immI(argI); break;
    case IMMF: retval = immF(argF); break;
    case IMMB: retval = immB(argB); break;
    case IMMS: retval = immS(argS); break;

    case PROC: retval = proc(argI); break;
    case PARAM: retval = param(argS); break;
    case ARRPARAM: retval = arrparam(argS); break;

    case BIND: retval = bind(argS); break;
    case NAME: retval = name(argS); break;
    case GET: retval = get(argS); break;
    case GETL: retval = getL(argS); break;
    case SET: retval = set(argS); break;

    case JFALSE: retval = jfalse(argI); break;
    case JMP: retval = jmp(argI); break;
    case NEXT: retval = next(argI); break;
    case ITER: retval = iter(argS); break;

    case SCOPE: retval = scope(argS); break;

    case FILE: retval = file(argS); break;
    case LINE: retval = line(argI); break;

    default: machine->ReportError("Unknown opcode."); retval = false; break;
    }

    if(!codePointerAlreadyMoved) {
        codePointer += OpCodeHasArgument(inst.opcode) ? 
                        OpCodeSize + OpArgSize :
                        OpCodeSize;
    }

    return retval;
}
