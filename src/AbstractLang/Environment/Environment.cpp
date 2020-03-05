#include <iostream>

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
        /// search in the current scope
        if(currentScopeNode->content.find(name) != currentScope->content.end()) {
            return currentScopeNode->content[name];
        }

        /// trace up to parent scopes
        if(currentScopeNode->enableTraceup && !currentScopeNode->parent.expired()) {
            currentScopeNode = currentScopeNode->parent.lock();
        } else {
            return GeneralDataNode();
        }
    }

    return GeneralDataNode();
}

bool ws::asl::Environment::SetDataNode(const std::string & name, ws::asl::GeneralDataNode target) {
    /// 1. check the parameter scope
    if(!paramStack.empty()) {
        ws::asl::Scope & scope = paramStack.top();
        if(scope.content.find(name) != scope.content.end()) {
            scope.content[name] = target;
            return true;
        }
    }

    /// 2. find in the lexical scope
    auto currentScopeNode = currentScope;
    while(currentScopeNode != nullptr) {
        /// search in the current scope
        if(currentScopeNode->content.find(name) != currentScope->content.end()) {
            currentScopeNode->content[name] = target;
            return true;
        }

        /// trace up to parent scopes
        if(currentScopeNode->enableTraceup && !currentScopeNode->parent.expired()) {
            currentScopeNode = currentScopeNode->parent.lock();
        } else {
            return false;
        }
    }

    return false;
}

void ws::asl::Environment::ReportError(const std::runtime_error & error) {
    /// Temporary handling method
    throw error;
}
