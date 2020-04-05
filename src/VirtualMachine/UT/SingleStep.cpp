#include <iostream>
#include <fstream>

#include <Machine.hpp>
#include <Executor.hpp>
#include <ByteCode.hpp>

using namespace ws::vm;

int main(int argc, char * argv[]) {
    auto file = std::ifstream(argv[1]);
    auto code = std::make_shared<ByteCode>(file);

    std::cout << "code prepared" << std::endl;

    Executor exe;
    exe.bytecode = code;

    std::cout << "exe prepared" << std::endl;

    Machine mach(exe);

    std::cout << "mach prepared" << std::endl;

    while(mach.SingleStep()) {
        std::cin.get();
    }
}
