#pragma once 

#include <map>
#include <string>
#include <string_view>
#include <stack>
#include <optional>

#include "GeneralDataNode.hpp"

namespace ws {

namespace vm {

    struct Scope {

        std::stack<std::map<std::string, GeneralDataNode>> bindingStack;

        std::string parentPath;

        Value GetRValue(const std::string & name);
        Value GetLValue(const std::string & name);

        bool Contains(const std::string & name);

    };

    struct ScopeDirectory {

        std::map<std::string, Scope, std::less<>> scopeMap;

        Value Access(const std::string & path, const std::string & name, bool asLval=false);
        void Bind(const std::string & path, const std::string & name, GeneralDataNode & node);
        void PushScope(const std::string & path);
        void PopScope(const std::string & path);
        void InsertName(const std::string & path, const std::string & name);
        void PourBindings(const std::string & path, std::map<std::string, GeneralDataNode> pour);

        ScopeDirectory();

        ScopeDirectory(const ScopeDirectory &) = delete;
        ScopeDirectory operator=(const ScopeDirectory &) = delete;

    // private:
        std::string_view GetParentPath(std::string_view path);

    };

}

}
