#include <exception>

#include "StmtVarDef.hpp"

using namespace ws::asl;

bool StatementVariableDefine::InnerExecute(Environment & env) {
    /// first forbid use of reserved word
    if(IsReservedWord()) {
        env.ReportError(std::runtime_error("Cannot use reserved word for variable name"));
        return true;
    }

    /// evaluate the rhs exression
    auto value = expr->Eval(env);

    /// update the binding in the current scope
    env.currentScope->contentStack.top()[id] = value;

    return true;
}

bool StatementVariableDefine::IsReservedWord() {
    /// TODO: judge reserved word
    return false;
}

int64_t StatementVariableDefine::GenByteCode(vm::ByteCodeBuilder & builder) {
    int64_t length = StatementBase::GenByteCode(builder);

    builder.Append(vm::OpCode::NAME, id);
    length += vm::OpCodeSize + vm::OpArgSize;

    length += expr->GenByteCode(builder);

    builder.Append(vm::OpCode::SET, id);
    length += vm::OpCodeSize + vm::OpArgSize;

    return length;
}
