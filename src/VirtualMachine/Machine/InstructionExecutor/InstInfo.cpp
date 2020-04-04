#include "Executor.hpp"
#include "Machine.hpp"

using namespace ws::vm;

bool Executor::file(const std::string & arg) {
    filename = arg;
    return true;
}

bool Executor::line(int64_t arg) {
    lineNoInFile = arg;
    return true;
}
