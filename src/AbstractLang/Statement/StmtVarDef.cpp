#include <exception>

#include "StmtVarDef.hpp"

using namespace ws::asl;

void StatementVariableDefine::Execute(Environment & env) {
    /// first forbid use of reserved word
    if(IsReservedWord()) {
        env.ReportError(std::runtime_error("Cannot use reserved word for variable name"));
        return;
    }

    /// evaluate the rhs exression
    auto value = expr->Eval(env);

    /// update the binding in the current scope
    env.currentScope->content[id] = value;
}
