#include <exception>
#include <iostream>

#include "Scope.hpp"

using namespace ws::vm;

Value Scope::GetRValue(const std::string & name) {
    if(bindingStack.empty()) {
        return Value(GeneralDataNode());
    }

    auto iter = bindingStack.top().find(name);

    if(iter == bindingStack.top().end()) {
        return Value(GeneralDataNode());
    }

    return Value(iter->second);
}

Value Scope::GetLValue(const std::string & name) {
    if(bindingStack.empty()) {
        return Value(GeneralDataNode());
    }

    return Value(&bindingStack.top()[name]);
}

bool Scope::Contains(const std::string & name) {
    return bindingStack.empty() ? false : bindingStack.top().find(name) != bindingStack.top().end();
}


ScopeDirectory::ScopeDirectory() {
    PushScope("/");
}

void ScopeDirectory::PushScope(const std::string & path) {
    scopeMap[path].bindingStack.push(std::map<std::string, GeneralDataNode>());
}

void ScopeDirectory::PopScope(const std::string & path) {
    auto & scope = scopeMap[path];
    
    if(scope.bindingStack.empty()) {
        throw std::runtime_error("Cannot pop an empty scope stack.");
    }

    scope.bindingStack.pop();
}

Value ScopeDirectory::Access(const std::string & path, const std::string & name, bool asLval) {
    std::string_view currentPath = path;

    while(currentPath.length() > 0) {  // while currentPath != ""
        auto scopeIter = scopeMap.find(currentPath);
        
        // check existance of current scope
        if(scopeIter != scopeMap.end()) {
            // current scope contains the name?
            if(scopeIter->second.Contains(name)) {
                return asLval ? 
                    (scopeIter->second.GetLValue(name)) : 
                    (scopeIter->second.GetRValue(name));
            }
        }

        // go to the parent scope
        currentPath = GetParentPath(currentPath);
    }

    return Value(GeneralDataNode());
}

void ScopeDirectory::Bind(const std::string & path, const std::string & name, GeneralDataNode & node) {
    auto scopeIter = scopeMap.find(path);

    if(scopeIter == scopeMap.end() || scopeIter->second.bindingStack.empty()) {
        throw std::runtime_error("scope path doesn't exist.");
    }

    scopeIter->second.bindingStack.top()[name] = node;
}

std::string_view ScopeDirectory::GetParentPath(std::string_view path) {
    if(path == "/") {
        return "";
    }

    auto lastSlashPos = path.find_last_of("/", path.length() - 2);

    return path.substr(0, lastSlashPos + 1);
}

void ScopeDirectory::InsertName(const std::string & path, const std::string & name) {
    auto scopeIter = scopeMap.find(path);
        
    // check existance of current scope
    if(scopeIter == scopeMap.end() || scopeIter->second.bindingStack.empty()) {
        throw std::runtime_error("Cannot insert name to a scope which doesn't exist.");
    }

    const auto & _ = scopeIter->second.bindingStack.top()[name];
}

void ScopeDirectory::PourBindings(const std::string & path, std::map<std::string, GeneralDataNode> pour) {
    auto scopeIter = scopeMap.find(path);

    if(scopeIter == scopeMap.end() || scopeIter->second.bindingStack.empty()) {
        throw std::runtime_error("Cannot pour bindings into a scope which doesn't exists.");
    }

    auto & targetScope = scopeIter->second.bindingStack.top();

    for(auto & kv : pour) {
        targetScope[kv.first] = kv.second;
    }
}
