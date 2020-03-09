#include <iostream>

#include "Environment.hpp"

ws::asl::GeneralDataNode ws::asl::Environment::GetDataNode(const std::string & name) {
    /// 1. check the parameter scope
    if(!paramStack.empty()) {
        ws::asl::Scope & scope = paramStack.top();

        auto contentIt = scope.contentStack.top().find(name);
        if(contentIt != scope.contentStack.top().end()) {
            return contentIt->second;
        }
    }

    /// 2. find in the lexical scope
    auto currentScopeNode = currentScope;
    while(currentScopeNode != nullptr) {
        /// search in the current scope
        auto contentIt = currentScopeNode->contentStack.top().find(name);
        if(contentIt != currentScopeNode->contentStack.top().end()) {
            return contentIt->second;
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

        auto contentIt = scope.contentStack.top().find(name);
        if(contentIt != scope.contentStack.top().end()) {
            contentIt->second = target;
            return true;
        }
    }

    /// 2. find in the lexical scope
    auto currentScopeNode = currentScope;
    while(currentScopeNode != nullptr) {
        /// search in the current scope
        auto contentIt = currentScopeNode->contentStack.top().find(name);
        if(contentIt != currentScopeNode->contentStack.top().end()) {
            contentIt->second = target;
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
    throw std::runtime_error(
        std::string("Runtime error: ") + 
        error.what() + 
        "\nTraceback: \n" + 
        GetInfoStackString()
    );
}

std::string ws::asl::Environment::GetInfoStackString() {
    auto depth = infoStack.size();
    auto infoStackCopy = infoStack;

    std::string result;

    while(depth--) {
        result += "\tFrame #" + std::to_string(depth) + "  " 
                  + infoStackCopy.top().lock()->file + ":"
                  + std::to_string(infoStackCopy.top().lock()->line) + ":"
                  + std::to_string(infoStackCopy.top().lock()->character) + "\n"
                  + "\tEquivalance code: " + infoStackCopy.top().lock()->content + "\n";

        infoStackCopy.pop();
    }

    return result;
}

ws::asl::GeneralDataNode ws::asl::Environment::GetThisDict() {
    /// test if `this` is available in the current environment
    if(thisStack.empty() || thisStack.top().expired()) {
        return GeneralDataNode();
    }

    /// assembly a GDN for `this`
    GeneralDataNode thisGDN;
    thisGDN.type = GeneralDataNode::DataType::TypeDict;
    thisGDN.data = thisStack.top().lock();

    return thisGDN;
}
