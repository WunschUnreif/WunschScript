#include "StmtExpr.hpp"

using namespace ws::asl;

bool StatementExpression::Execute(Environment & env) {
    auto _ = expr->Eval(env);
    return true;
}
