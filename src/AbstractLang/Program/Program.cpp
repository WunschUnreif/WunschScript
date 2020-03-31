#include "Program.hpp"

using namespace ws::asl;

void Program::Execute() {
    for(auto stmt : statements) {
        stmt->Execute(env);
    }
}

int64_t Program::GenByteCode(vm::ByteCodeBuilder & builder) {
    int64_t length = 0;

    builder.Append(vm::OpCode::FILE, filename);
    length += vm::OpCodeSize + vm::OpArgSize;

    for(auto stmt : statements) {
        length += stmt->GenByteCode(builder);
    }

    return length;
}
