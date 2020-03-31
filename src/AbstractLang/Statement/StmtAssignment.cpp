#include <exception>

#include "StmtAssignment.hpp"

using namespace ws::asl;

bool StatementAssignment::InnerExecute(Environment & env) {
    /// evaluate the rhs exression
    auto value = rhs->Eval(env);

    /// set the left hand side
    lhs->SetValue(env, value);

    return true;
}

int64_t StatementAssignment::GenByteCode(vm::ByteCodeBuilder & builder) {
    int64_t length = StatementBase::GenByteCode(builder);

    length += lhs->GenByteCodeLval(builder);
    length += rhs->GenByteCode(builder);

    builder.Append(vm::OpCode::ASSIGN);
    length += vm::OpCodeSize;

    return length;
}
