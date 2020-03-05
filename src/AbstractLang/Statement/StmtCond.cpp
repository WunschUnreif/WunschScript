#include <exception>

#include "StmtCond.hpp"

using namespace ws::asl;

bool StatementCondition::InnerExecute(Environment & env) {
    /// evaluate the condition
    auto condResult = cond->Eval(env);

    /// the result must be a bool
    if(condResult.type != GeneralDataNode::DataType::TypeBool) {
        env.ReportError(std::runtime_error("Condition of if statement must be a bool."));
        return true;
    }

    auto condVal = std::dynamic_pointer_cast<DataNodeBool>(condResult.data)->value;

    if(condVal) {
        return thenBranch->Execute(env);
    } else {
        return elseBranch == nullptr ? true : elseBranch->Execute(env);
    }
}