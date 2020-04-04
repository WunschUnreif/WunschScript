#pragma once 

#include <vector>
#include <stack>
#include <string_view>

#include "GeneralDataNode.hpp"
#include "Executor.hpp"

namespace ws {

namespace vm {

    struct Machine {

        std::vector<Executor> metaExecutors;
        std::stack<Executor> workerExecutors;

        std::stack<Value> valueStack;

        Machine() {}
        Machine(Executor & initialExecutor);

        void Run();

        size_t GetNextExecutorID() { return metaExecutors.size(); }

        void ReportError(const std::string & content);

        const Value & Top();
        Value Pop();
        void Push(Value & val);

    };

}

}
