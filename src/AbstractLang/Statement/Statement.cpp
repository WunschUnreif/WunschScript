#include <iostream>
#include "Statement.hpp"

using namespace ws::asl;

bool StatementBase::Execute(Environment & env) {
    env.infoStack.push(info);
    env.aliveDictStack.emplace();

    auto permitContinue = this->InnerExecute(env);

    env.aliveDictStack.pop();
    env.infoStack.pop();

    return permitContinue;
} 

int64_t StatementBase::GenByteCode(vm::ByteCodeBuilder & builder) {
    builder.Append(vm::OpCode::LINE, static_cast<int64_t>(info->line));
    return vm::OpCodeSize + vm::OpArgSize;
}

bool StatementBlock::Execute(Environment & env, std::map<std::string, GeneralDataNode> * pour) {
    /// prepare new scope
    lexScope->push();

    if(pour) {
        for(auto kv : *pour) {
            lexScope->contentStack.top()[kv.first] = kv.second;
        }
    }

    /// save the environment
    auto lastScope = env.currentScope;
    /// load scope of this block
    env.currentScope = lexScope;

    auto permitContinue = true;

    for(auto stmt : body) {
        if(stmt->Execute(env) == false) {
            permitContinue = false;
            break;
        }
    }

    /// restore the environment
    env.currentScope = lastScope;

    lexScope->pop();

    return permitContinue;
}

int64_t StatementBlock::GenByteCode(vm::ByteCodeBuilder & builder, bool forFunc) {
    int64_t length = 0;

    auto proc = builder.Append(vm::PROC, 0LL);      // yield `proc ...`
    length += vm::OpCodeSize + vm::OpArgSize;

    builder.Append(vm::SCOPE, lexScope->GetPath()); // yield `scope /0/1/...`
    length += vm::OpCodeSize + vm::OpArgSize;

    int64_t innerLength = 0;
    for(auto stmt : body) {                         // gen code for inner stuff
        innerLength += stmt->GenByteCode(builder);  
    }
    length += innerLength;

    // proc contains: 1. proc... 2. scope... 3. iterBody 4. endp
    builder.ChangeArgumentForCode(proc, 2 * (vm::OpCodeSize + vm::OpArgSize) + innerLength + vm::OpCodeSize);

    builder.Append(forFunc ? vm::OpCode::ENDP : vm::OpCode::ENDPS); // the ending
    length += vm::OpCodeSize;

    return length;
}
