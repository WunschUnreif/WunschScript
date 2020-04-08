#include <iostream>
#include <fstream>
#include <sstream>

#include "TreeDiagram.hpp"
#include "AbstractLang.hpp"
#include "ByteCode.hpp"
#include "CodeBuilder.hpp"

using namespace ws::td;
using namespace ws::asl;

int RunImmediately(char ** argv);

int main(int argc, char ** argv) {
    std::cout << "Wunsch | compiled at " __DATE__ " " __TIME__ << std::endl;

    if(argc == 2) {
        return RunImmediately(argv);
    }

    if(argc != 3 || argv[2] != std::string("emit-bc")) {
        std::cout << "usage: wunsch <src.ws> [emit-bc]" << std::endl;
        return 0;
    }

    std::string filename = argv[1];
    std::string_view filenameview(filename);

    if(filenameview.substr(filename.length() - 3, 3) != ".ws") {
        std::cerr << "ERROR: invalid filename." << argv[1];
        return 1;
    }

    auto compiledname = filename + "c";

    std::ifstream inputFile(filename, std::ios::in);
    std::ofstream compiledFile(compiledname, std::ios::app);

    if(!inputFile.is_open()) {
        std::cerr << "ERROR: file not exist: " << argv[1];
        return 1;
    }
    
    std::stringstream buffer;  
    buffer << inputFile.rdbuf();  
    std::string code(buffer.str());

    TreeDiagram td(code, argv[1]);

    ws::vm::ByteCodeBuilder builder;
    td.prog->GenByteCode(builder);

    builder.bytecode.WriteToFile(compiledFile);
    std::cout << builder.bytecode.ToString() << std::endl;

    return 0;
}

int RunImmediately(char ** argv) {
    std::ifstream inputFile(argv[1], std::ios::in);

    if(!inputFile.is_open()) {
        std::cerr << "file not exist: " << argv[1];
    }
    
    std::stringstream buffer;  
    buffer << inputFile.rdbuf();  
    std::string code(buffer.str());

    TreeDiagram td(code, argv[1]);
    td.ExecuteAndExtract();

    return 0;
}
