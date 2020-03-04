#include <exception>

#include "StmtAssignment.hpp"

using namespace ws::asl;

bool StatementAssignment::Execute(Environment & env) {
    /// evaluate the rhs exression
    auto value = rhs->Eval(env);

    /// set the left hand side
    lhs->SetValue(env, value);

    return true;
}
