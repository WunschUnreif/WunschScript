#include <iostream>

#include "Bytecode/Opcode.hpp"
#include "Bytecode/Instruction.hpp"
#include "Bytecode/ByteCode.hpp"
#include "Bytecode/CodeBuilder.hpp"

using namespace ws::vm;

ByteCodeBuilder builder;

int main() {

    std::cout << "start" << std::endl;

    builder.Append(ws::vm::FILE, std::string("test"));
    builder.Append(IMMI, 10LL);
    builder.Append(SET, std::string("x"));
    builder.Append(GET, std::string("range"));
    builder.Append(PROC, 38LL);
    builder.Append(GET, std::string("x"));
    builder.Append(GET, std::string("i"));
    builder.Append(ADD);
    builder.Append(SET, std::string("x"));
    builder.Append(ENDPS);

    std::cout << builder.bytecode.ToString() << std::endl;

    return 0;

}
