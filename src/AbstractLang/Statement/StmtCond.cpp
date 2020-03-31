#include <exception>

#include "StmtCond.hpp"

using namespace ws::asl;

bool StatementCondition::InnerExecute(Environment & env) {
    /// evaluate the condition
    auto condResult = cond->Eval(env);

    /// the result must be a bool
    if(condResult.type != GeneralDataNode::DataType::TypeBool) {
        env.ReportError(std::runtime_error("Condition of if statement must be a bool."));
        return true;
    }

    auto condVal = std::dynamic_pointer_cast<DataNodeBool>(condResult.data)->value;

    if(condVal) {
        return thenBranch->Execute(env);
    } else {
        return elseBranch == nullptr ? true : elseBranch->Execute(env);
    }
}

int64_t StatementCondition::GenByteCode(vm::ByteCodeBuilder & builder) {
    int64_t length = StatementBase::GenByteCode(builder);

    length += cond->GenByteCode(builder);                                   // cond.codegen

    auto jfalse = builder.Append(vm::OpCode::JFALSE, 0LL);                  // yield `jfalse ...`
    length += vm::OpCodeSize + vm::OpArgSize;

    builder.Append(vm::OpCode::JMP, 2 * (vm::OpCodeSize + vm::OpArgSize));  // yield `jmp -> then branch`
    length += vm::OpCodeSize + vm::OpArgSize;

    auto thenBranchLength = thenBranch->GenByteCode(builder);               // proc ...(then) ... endps
    length += thenBranchLength;

    // jfalse: 0. jfalse 1. jmp 2. then branch 3. jmp
    builder.ChangeArgumentForCode(jfalse, 3 * (vm::OpCodeSize + vm::OpArgSize) + thenBranchLength);

    auto jmpAfterThen = builder.Append(vm::OpCode::JMP, 0LL);
    length += vm::OpCodeSize + vm::OpArgSize;

    auto lengthBeforeElse = length;

    if(elseBranch) {
        auto jmp = builder.Append(vm::OpCode::JMP, 0LL);                    // yield `jmp -> else branch`
        length += vm::OpCodeSize + vm::OpArgSize;

        auto elseBranchLength = elseBranch->GenByteCode(builder);           // proc ...(else) ... endps
        length += elseBranchLength;

        builder.ChangeArgumentForCode(jmp, 2 * (vm::OpCodeSize + vm::OpArgSize));
    }

    // jmp after then: 0. jmp 1. generated for else
    builder.ChangeArgumentForCode(jmpAfterThen, (vm::OpCodeSize + vm::OpArgSize) + (length - lengthBeforeElse));

    return length;
}
