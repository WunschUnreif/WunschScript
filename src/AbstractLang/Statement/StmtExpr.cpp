#include "StmtExpr.hpp"

using namespace ws::asl;

void StatementExpression::Execute(Environment & env) {
    auto _ = expr->Eval(env);
}
