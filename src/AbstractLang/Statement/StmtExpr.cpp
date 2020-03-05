#include "StmtExpr.hpp"

using namespace ws::asl;

bool StatementExpression::InnerExecute(Environment & env) {
    auto _ = expr->Eval(env);
    return true;
}
