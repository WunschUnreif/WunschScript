#pragma once 

#include <memory>
#include <string>
#include <stack>
#include <iterator>
#include <deque>

#include "DataNode.hpp"
#include "ByteCode/ByteCode.hpp"
#include "Bytecode/Instruction.hpp"
#include "Scope.hpp"

namespace ws {

namespace vm {

    struct Machine;

    struct Executor {

        Machine * machine;

        size_t executorID;

        std::shared_ptr<ByteCode> bytecode;
        int64_t codePointer;

        // Environment for normal executing
        std::string filename;
        size_t lineNoInFile;

        std::shared_ptr<ScopeDirectory> scopeDirectory;
        std::string currentScopePath = "/";

        // Environment for Function call
        std::map<std::string, GeneralDataNode> bindingPour;
        std::weak_ptr<DataNodeDict> thisDict;
        std::stack<std::vector<GeneralDataNode>> precallStack;

        // Environment for For-Loop
        struct ForLoopFrame {
            std::string iteratorName;
            GeneralDataNode iteratee;

            bool iteratingDict = false;
            decltype (DataNodeDict::value)::iterator dictIterator;
            decltype (DataNodeDict::value)::iterator dictEnding;

            bool iteratingList = false;
            decltype (DataNodeList::value)::iterator listIterator;
            decltype (DataNodeList::value)::iterator listEnding;
        };
        std::stack<ForLoopFrame> forloopStack;

        void Execute();

        Executor() {}
        Executor(const Executor & exe);
        Executor operator=(const Executor & exe);

    private:
        bool ExecuteInstruction(const Instruction & inst);

        bool uadd();
        bool usub();

        bool add();
        bool sub();
        bool mul();
        bool div();
        bool rem();

        bool lt();
        bool lte();
        bool gt();
        bool gte();

        bool eq();
        bool ne();

        bool bnot();
        bool band();
        bool bxor();
        bool bor();

        bool lnot();
        bool land();
        bool lor();

        bool dcopy();
        bool copy();
        bool wref();
        bool opderef();
        bool fcderef();

        bool access();
        bool accessL();
        bool ithis();

        bool func();
        bool precall();
        bool arg();
        bool call();

        bool assign();
        bool ret();
        bool endp();
        bool endps();

        bool immN();
        bool immL();
        bool immD();

        bool pop();

        bool accid(const std::string & arg);
        bool accidL(const std::string & arg);

        bool immI(int64_t arg);
        bool immF(double arg);
        bool immB(bool arg);
        bool immS(const std::string & arg);

        bool proc(int64_t arg);
        bool param(const std::string & arg);
        bool arrparam(const std::string & arg);

        bool bind(const std::string & arg);
        bool name(const std::string & arg);
        bool get(const std::string & arg);
        bool getL(const std::string & arg);
        bool set(const std::string & arg);

        bool jmp(int64_t arg);
        bool jfalse(int64_t arg);
        bool next(int64_t arg);
        bool iter(const std::string & arg);

        bool scope(const std::string & arg);

        bool file(const std::string & arg);         // [x]
        bool line(int64_t arg);                     // [x]
    };

}

}
