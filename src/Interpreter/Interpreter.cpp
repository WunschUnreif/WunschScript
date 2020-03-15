#include <iostream>
#include <fstream>
#include <sstream>

#include "TreeDiagram.hpp"
#include "AbstractLang.hpp"

using namespace ws::td;
using namespace ws::asl;

int main(int argc, char ** argv) {
    std::cout << "Wunsch | compiled at " __DATE__ " " __TIME__ << std::endl;
    if(argc != 2) {
        std::cout << "usage: wunsch <src.ws>" << std::endl;
        return 0;
    }

    std::ifstream inputFile(argv[1]);
    
    std::stringstream buffer;  
    buffer << inputFile.rdbuf();  
    std::string code(buffer.str());

    TreeDiagram td(code, argv[1]);
    td.ExecuteAndExtract();

    return 0;
}
