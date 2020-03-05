#include <exception>

#include "StmtWhileLoop.hpp"

using namespace ws::asl;

bool StatementWhileLoop::InnerExecute(Environment & env) {
    bool permitContinue = true;

    while(permitContinue) {
        /// evaluate the condition
        auto condResult = cond->Eval(env);

        /// the result must be a bool
        if(condResult.type != GeneralDataNode::DataType::TypeBool) {
            env.ReportError(std::runtime_error("Condition of while statement must be a bool."));
            return true;
        }

        /// test condition
        if(std::dynamic_pointer_cast<DataNodeBool>(condResult.data)->value == false) {
            break;
        }

        /// execute the loop body
        permitContinue = loopBody->Execute(env);
    }

    return permitContinue;
}
