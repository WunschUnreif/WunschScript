#pragma once 

#include <memory>
#include <string>
#include <stack>
#include <iterator>
#include <deque>

#include "DataNode.hpp"
#include "ByteCode.hpp"
#include "Scope.hpp"

namespace ws {

namespace vm {

    struct Executor {

        size_t executorID;

        std::shared_ptr<ByteCode> bytecode;
        size_t codePointer;

        // Environment for normal executing
        std::string filename;
        size_t lineNoInFile;

        std::shared_ptr<ScopeDirectory> scopeDirectory;
        std::string currentScopePath;

        // Environment for Function call
        std::map<std::string, GeneralDataNode> bindingPour;
        std::weak_ptr<DataNodeDict> thisDict;

        // Environment for For-Loop
        struct ForLoopFrame {
            std::string iteratorName;
            GeneralDataNode iteratee;

            bool iteratingDict = false;
            decltype (DataNodeDict::value)::iterator dictIterator;

            bool iteratingList = false;
            decltype (DataNodeList::value)::iterator listIterator;
        };
        std::stack<ForLoopFrame> forloopStack;

        void Execute();

    };

}

}
