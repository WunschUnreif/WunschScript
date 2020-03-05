#include <iostream>
#include "Statement.hpp"

using namespace ws::asl;

bool StatementBase::Execute(Environment & env) {
    env.infoStack.push(info);
    auto permitContinue = this->InnerExecute(env);
    env.infoStack.pop();

    return permitContinue;
} 

bool StatementBlock::Execute(Environment & env) {
    /// save the environment
    auto lastScope = env.currentScope;
    /// load scope of this block
    env.currentScope = lexScope;

    auto permitContinue = true;

    for(auto stmt : body) {
        if(stmt->Execute(env) == false) {
            permitContinue = false;
            break;
        }
    }

    /// restore the environment
    env.currentScope = lastScope;

    return permitContinue;
}
