#include <sstream>

#include "Machine.hpp"

using namespace ws::vm;

Machine::Machine(Executor & initialExecutor) {
    metaExecutors.emplace_back(initialExecutor);
    metaExecutors[0].executorID = 0;

    workerExecutors.emplace(metaExecutors[0]);
}

void Machine::Run() {
    while(!workerExecutors.empty()) {
        workerExecutors.top().Execute();
    }
}

void Machine::ReportError(const std::string & content) {
    std::string error = "[ERROR] " + content + "\n";

    size_t frameNum = 0;
    while(!workerExecutors.empty()) {
        auto exe = workerExecutors.top();
        workerExecutors.pop();

        error += "\tFrame " + std::to_string(frameNum) + ": ";
        error += exe.filename + ":" + std::to_string(exe.lineNoInFile) 
                + " ->" + std::to_string(exe.codePointer) + "@" + std::to_string(exe.executorID);
        error += "\n";

        ++frameNum;
    }

    throw std::runtime_error(error);
}

const Value & Machine::Top() {
    if(valueStack.empty()) {
        ReportError("Check on empty value stack.");
    }

    return valueStack.top();
}

Value Machine::Pop() {
    if(valueStack.empty()) {
        ReportError("Pop on empty value stack.");
    }
    
    auto top = valueStack.top();
    valueStack.pop();

    return top;
}

void Machine::Push(Value & val) {
    valueStack.emplace(val);
}
