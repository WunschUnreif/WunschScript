#include <exception>

#include <cassert>

#include "StmtReturn.hpp"

using namespace ws::asl;

bool StatementReturn::InnerExecute(Environment & env) {
    /// evaluate the rhs exression
    auto value = expr->Eval(env);

    /// when return executed outside a function
    if(env.returnStack.empty()) {
        env.ReportError(std::runtime_error("`return` cannot execute outside a function."));
    }

    assert(env.returnStack.top().type == GeneralDataNode::DataType::TypeNil);

    /// pop the flag
    env.returnStack.pop();

    /// fill the result
    env.returnStack.push(value);

    /// forbid continue execution
    return false;
}

int64_t StatementReturn::GenByteCode(vm::ByteCodeBuilder & builder) {
    int64_t length = StatementBase::GenByteCode(builder);

    length += expr->GenByteCode(builder);

    builder.Append(vm::OpCode::RET);
    length += vm::OpCodeSize;

    return length;
}
