#include "Program.hpp"

using namespace ws::asl;

void Program::Execute() {
    for(auto stmt : statements) {
        stmt->Execute(env);
    }
}
