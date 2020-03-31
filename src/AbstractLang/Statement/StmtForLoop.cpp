#include <exception>

#include "StmtForLoop.hpp"

using namespace ws::asl;

bool StatementForLoop::InnerExecute(Environment & env) {
    /// evaluate the iterable
    auto iterableObj = toIter->Eval(env);

    /// for list iteration, iter over elements
    if(iterableObj.type == GeneralDataNode::DataType::TypeList) {
        for(auto currGDN : std::dynamic_pointer_cast<DataNodeList>(iterableObj.data)->value) {
            /// bind the iterator
            std::map<std::string, GeneralDataNode> pour;
            pour[iteratorName] = currGDN;

            /// execute the loop body
            auto permitContinue = loopBody->Execute(env, &pour);

            if(!permitContinue) return false;
        }

        return true;
    }

    /// for dict iteration, iter over keys
    if(iterableObj.type == GeneralDataNode::DataType::TypeDict) {
        for(auto currKV : std::dynamic_pointer_cast<DataNodeDict>(iterableObj.data)->value) {
            /// generate a temp str node
            auto keyStrNode = std::make_shared<DataNodeStr>();
            keyStrNode->value = currKV.first;

            /// generate a temp str GDN
            GeneralDataNode keyStrGDN;
            keyStrGDN.type = GeneralDataNode::DataType::TypeString;
            keyStrGDN.data = keyStrNode;

            /// bind the iterator
            std::map<std::string, GeneralDataNode> pour;
            pour[iteratorName] = keyStrGDN;

            /// execute the loop body
            auto permitContinue = loopBody->Execute(env, &pour);

            if(!permitContinue) return false;
        }

        return true;
    }

    /// if the expression is not list or dict, do as an var def in local scope
    std::map<std::string, GeneralDataNode> pour;
    pour[iteratorName] = iterableObj;
    return loopBody->Execute(env, &pour);
}

int64_t StatementForLoop::GenByteCode(vm::ByteCodeBuilder & builder) {
    int64_t length = StatementBase::GenByteCode(builder);

    length += toIter->GenByteCode(builder);         // yield toIter.codegen

    auto jmp = builder.Append(vm::JMP, 2 * (vm::OpCodeSize + vm::OpArgSize));   // yield `jmp -> loop body`
    length += vm::OpCodeSize + vm::OpArgSize;

    auto proc = builder.Append(vm::PROC, 0LL);      // yield `proc ...`
    length += vm::OpCodeSize + vm::OpArgSize;

    builder.Append(vm::SCOPE, loopBody->lexScope->GetPath()); // yield `scope /0/1/...`
    length += vm::OpCodeSize + vm::OpArgSize;

    builder.Append(vm::ITER, iteratorName);         // yield `iter i`
    length += vm::OpCodeSize + vm::OpArgSize;

    int64_t innerLength = 0;
    for(auto stmt : loopBody->body) {               // gen code for inner stuff
        innerLength += stmt->GenByteCode(builder);  
    }
    length += innerLength;

    builder.Append(vm::NEXT, -innerLength);         // yield `next ...`
    length += vm::OpCodeSize + vm::OpArgSize;

    // proc contains: 1. proc... 2. scope... 3. iter ... 4. iterBody 5. next ... 6. endps
    builder.ChangeArgumentForCode(proc, 4 * (vm::OpCodeSize + vm::OpArgSize) + vm::OpCodeSize + innerLength);

    builder.Append(vm::OpCode::ENDPS); // the ending
    length += vm::OpCodeSize;

    return length;
}
