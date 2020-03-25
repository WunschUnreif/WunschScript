#ifndef __WS_ASL_SCOPE_HPP__
#define __WS_ASL_SCOPE_HPP__

#include <iostream>
#include <memory>
#include <map>
#include <vector>
#include <algorithm>

#include "DataRepresentation/GeneralDataNode.hpp"

namespace ws {

namespace asl {

    struct Scope : public std::enable_shared_from_this<Scope> {
        std::weak_ptr<Scope> parent;
        std::stack<std::map<std::string, GeneralDataNode>> contentStack;
        std::vector<std::shared_ptr<Scope>> children;

        /// whether the search can go to its parent node.
        /// this is set to false for every file's root scope.
        /// useful when importing another script in the 
        /// current script to preventing unexpected scope overlap.
        bool enableTraceup = true;

        Scope() {
            push();
        }

        void push() {
            contentStack.push(std::map<std::string, GeneralDataNode>());
        }

        void pop() {
            contentStack.pop();
        }

        /// Get the path from root scope to the current scope
        std::string GetPath() {
            if(!parent.expired()) {
                auto parentScope = parent.lock();
                auto parentPath = parentScope->GetPath();

                auto numInParent = std::find_if(
                        parentScope->children.begin(), 
                        parentScope->children.end(),
                        [&](std::shared_ptr<Scope> x) { return x.get() == this; }
                    ) - parentScope->children.begin();

                return parentPath + (enableTraceup ? "" : "~") + std::to_string(numInParent) + "/";
            } else {
                return "/";
            }
        }
    };

}

}

#endif // !__WS_ASL_SCOPE_HPP__
