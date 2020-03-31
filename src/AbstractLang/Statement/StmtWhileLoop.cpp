#include <exception>

#include "StmtWhileLoop.hpp"

using namespace ws::asl;

bool StatementWhileLoop::InnerExecute(Environment & env) {
    bool permitContinue = true;

    while(permitContinue) {
        /// evaluate the condition
        auto condResult = cond->Eval(env);

        /// the result must be a bool
        if(condResult.type != GeneralDataNode::DataType::TypeBool) {
            env.ReportError(std::runtime_error("Condition of while statement must be a bool."));
            return true;
        }

        /// test condition
        if(std::dynamic_pointer_cast<DataNodeBool>(condResult.data)->value == false) {
            break;
        }

        /// execute the loop body
        permitContinue = loopBody->Execute(env);
    }

    return permitContinue;
}

int64_t StatementWhileLoop::GenByteCode(vm::ByteCodeBuilder & builder) {
    int64_t length = StatementBase::GenByteCode(builder);

    length += cond->GenByteCode(builder);                                   // cond.codegen

    auto jfalse = builder.Append(vm::OpCode::JFALSE, 0LL);                  // yield `jfalse ...`
    length += vm::OpCodeSize + vm::OpArgSize;

    builder.Append(vm::OpCode::JMP, 2 * (vm::OpCodeSize + vm::OpArgSize));  // yield `jmp -> loop body`
    length += vm::OpCodeSize + vm::OpArgSize;

    auto bodyLength = loopBody->GenByteCode(builder);                       // proc ...(loop) ... endps
    length += bodyLength;

    // jump through: 1. jfalse 2. jmp  2. body  3. jmp (back)
    builder.ChangeArgumentForCode(jfalse, 3 * (vm::OpCodeSize + vm::OpArgSize) + bodyLength);
    
    builder.Append(vm::OpCode::JMP, -length);
    length += vm::OpCodeSize + vm::OpArgSize;

    return length;
}
