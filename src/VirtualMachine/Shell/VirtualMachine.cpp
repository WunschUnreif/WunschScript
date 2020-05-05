#include <iostream>
#include <fstream>
#include <sstream>
#include <map>

#include <getopt.h>
#include <ctime>

#include "Machine.hpp"
#include "Executor.hpp"
#include "ByteCode.hpp"
#include "CodeBuilder.hpp"

using namespace ws::vm;

int RunForSource(std::string & filename);
int RunForBytecode(std::string & filename);

int main(int argc, char** argv) {
    std::string srcFilename, bytecodeFilename;
    
    char opt;
    while((opt = getopt(argc, argv, "s::b::")) != -1) {
        switch(opt) {
            case 's':
                srcFilename = optarg;
                break;
            case 'b':
                bytecodeFilename = optarg;
                break;
            default:
                std::cerr << "Error: unrecognized option -" << opt << std::endl;
                return 1;
        }
    }

    if(srcFilename == "" && bytecodeFilename == "") {
        std::cerr << "Usage: " << std::endl
                << "\twsvm -b <bytecode.wsc>" << std::endl
                << "or" << std::endl
                << "\twsvm -s <source.ws>" << std::endl;
        return 1;
    }

    if(srcFilename != "" && bytecodeFilename != "") {
        std::cerr << "Error: only 1 source file can be specifyed!" << std::endl;
        return 1;
    }

    if(srcFilename != "") {
        return RunForSource(srcFilename);
    } else {
        return RunForBytecode(bytecodeFilename);
    }

    return 0;
}

void RunBytecode(std::shared_ptr<ByteCode> bc) {
    Executor exe;
    exe.bytecode = bc;
    Machine mach(exe);

    auto start = clock();
    mach.Run();
    auto end = clock();

    extern std::map<OpCode, long> instTime;
    extern std::map<OpCode, long> instCount;

    double tot = 0;
    for(auto & t : instTime) {
        std::cout << GetOpName(t.first) << "\t-> " 
                  << t.second << '\t' << instCount[t.first] << '\t'
                  << t.second / double(instCount[t.first]) << std::endl;
        tot += double(t.second) / CLOCKS_PER_SEC;
    }

    std::cout << tot << std::endl;
    std::cout << double(end - start) / CLOCKS_PER_SEC << std::endl;
}

int RunForSource(std::string & filename) {
    std::cout << "Not support..." << std::endl;

    return 0;
}

int RunForBytecode(std::string & filename) {
    auto file = std::ifstream(filename);
    if(!file.is_open()) {
        std::cerr << "ERROR: file not exist: " << filename << std::endl;
        return 1;
    }

    auto code = std::make_shared<ByteCode>(file);

    RunBytecode(code);

    return 0;
}
