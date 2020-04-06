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
        int64_t codePointer = 0;

        // Environment for normal executing
        std::string filename;
        size_t lineNoInFile;

        std::shared_ptr<ScopeDirectory> scopeDirectory;
        std::stack<std::string> currentScopePathStack;

        // Environment for Function call
        std::map<std::string, GeneralDataNode> bindingPour;
        std::stack<std::vector<GeneralDataNode>> precallStack;
        std::weak_ptr<DataNodeDict> thisDict;

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

            ForLoopFrame(const std::string & name, GeneralDataNode & iteratee)
                : iteratorName(name), iteratee(iteratee) {}
        };
        std::stack<ForLoopFrame> forloopStack;

        void Execute();
        void ExecuteSingleStep();

        Executor()
            : scopeDirectory(std::make_shared<ScopeDirectory>()) { 
                currentScopePathStack.push("/"); 
                IdentifyFilename();
            }
        Executor(const Executor & exe);
        Executor operator=(const Executor & exe);

    private:
        void IdentifyFilename();

        bool ExecuteInstruction(const Instruction & inst);

        bool uadd()     {return true;}
        bool usub()     {return true;}

        bool add()      {return true;}
        bool sub()      {return true;}
        bool mul()      {return true;}
        bool div()      {return true;}
        bool rem()      {return true;}

        bool lt()       {return true;}
        bool lte()      {return true;}
        bool gt()       {return true;}
        bool gte()      {return true;}

        bool eq()       {return true;}
        bool ne()       {return true;}

        bool bnot()     {return true;}
        bool band()     {return true;}
        bool bxor()     {return true;}
        bool bor()      {return true;}

        bool lnot()     {return true;}
        bool land()     {return true;}
        bool lor()      {return true;}

        bool dcopy()    {return true;}
        bool copy()     {return true;}
        bool wref()     {return true;}
        bool opderef()  {return true;}
        bool fcderef()  {return true;}

        bool access()   {return true;}
        bool accessL()  {return true;}
        bool ithis();                               // [x]

        bool func();                                // [x]
        bool precall();                             // [x]
        bool arg();                                 // [x]
        bool call();                                // [x]

        bool assign();                              // [x]
        bool ret();                                 // [x]
        bool endp();                                // [x]
        bool endps();                               // [x]

        bool immN();                                // [x]
        bool immL();                                // [x]
        bool immD();                                // [x]

        bool pop();                                 // [x]

        bool accid(const std::string & arg)     {return true;}
        bool accidL(const std::string & arg)    {return true;}

        bool immI(int64_t arg);                     // [x]
        bool immF(double arg);                      // [x]
        bool immB(bool arg);                        // [x]
        bool immS(const std::string & arg);         // [x]

        bool proc(int64_t arg);                     // [x]
        bool param(const std::string & arg);        // [x]
        bool arrparam(const std::string & arg);     // [x]

        bool bind(const std::string & arg);         // [x]
        bool name(const std::string & arg);         // [x]
        bool get(const std::string & arg);          // [x]
        bool getL(const std::string & arg);         // [x]
        bool set(const std::string & arg);          // [x]

        bool jmp(int64_t arg);                      // [x]
        bool jfalse(int64_t arg);                   // [x]
        bool next(int64_t arg);                     // [x]
        bool iter(const std::string & arg);         // [x]

        bool scope(const std::string & arg);        // [x]

        bool file(const std::string & arg);         // [x]
        bool line(int64_t arg);                     // [x]

        bool codePointerAlreadyMoved = false;
    };

}

}
