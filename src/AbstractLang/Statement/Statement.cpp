#include <iostream>
#include "Statement.hpp"

using namespace ws::asl;

bool StatementBase::Execute(Environment & env) {
    env.infoStack.push(info);
    env.aliveDictStack.emplace();

    auto permitContinue = this->InnerExecute(env);

    env.aliveDictStack.pop();
    env.infoStack.pop();

    return permitContinue;
} 

bool StatementBlock::Execute(Environment & env, std::map<std::string, GeneralDataNode> * pour) {
    /// prepare new scope
    lexScope->push();

    if(pour) {
        for(auto kv : *pour) {
            lexScope->contentStack.top()[kv.first] = kv.second;
        }
    }

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

    lexScope->pop();

    return permitContinue;
}
