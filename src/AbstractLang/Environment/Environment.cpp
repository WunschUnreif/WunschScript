#include "Environment.hpp"

ws::asl::GeneralDataNode ws::asl::Environment::GetDataNode(const std::string & name) {
    /// 1. check the parameter scope
    if(!paramStack.empty()) {
        ws::asl::Scope scope = paramStack.top();
        if(scope.content.find(name) != scope.content.end()) {
            return scope.content[name];
        }
    }

    /// 2. find in the lexical scope
    auto currentScopeNode = currentScope;
    while(currentScopeNode != nullptr) {
        if(currentScopeNode->content.find(name) != currentScope->content.end()) {
            return currentScopeNode->content[name];
        }
        if(currentScopeNode->enableTraceup) {
            currentScopeNode = currentScopeNode->parent.lock();
        } else {
            return GeneralDataNode();
        }
    }

    return GeneralDataNode();
}

void ws::asl::Environment::ReportError(const std::runtime_error & error) {
    /// Temporary handling method
    throw error;
}