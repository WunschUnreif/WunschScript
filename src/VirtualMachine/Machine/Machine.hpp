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

        bool currentWorkerFinished = false;

        Machine() {}
        Machine(Executor & initialExecutor);

        void Run();
        bool SingleStep();

        size_t GetNextExecutorID() { return metaExecutors.size(); }

        void ReportError(const std::string & content);

        const Value & Top();
        Value Pop();
        void Push(Value & val);

    };

}

}
