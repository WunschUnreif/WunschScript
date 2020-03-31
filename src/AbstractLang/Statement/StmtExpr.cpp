#include "StmtExpr.hpp"

using namespace ws::asl;

bool StatementExpression::InnerExecute(Environment & env) {
    auto _ = expr->Eval(env);
    return true;
}

int64_t StatementExpression::GenByteCode(vm::ByteCodeBuilder & builder) {
    int64_t length = StatementBase::GenByteCode(builder);

    length += expr->GenByteCode(builder);

    builder.Append(vm::OpCode::POP);
    length += vm::OpCodeSize;

    return length;
}
