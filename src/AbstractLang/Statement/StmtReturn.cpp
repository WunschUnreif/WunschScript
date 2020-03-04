#include <exception>

#include "StmtReturn.hpp"

using namespace ws::asl;

bool StatementReturn::Execute(Environment & env) {
    /// evaluate the rhs exression
    auto value = expr->Eval(env);

    /// fill the result
    env.returnStack.push(value);

    /// forbid continue execution
    return false;
}
