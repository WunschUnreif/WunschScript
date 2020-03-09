#include <iostream>
#include <fstream>
#include <sstream>

#include "TreeDiagram.hpp"
#include "AbstractLang.hpp"

using namespace ws::td;
using namespace ws::asl;

int main(int argc, char ** argv) {
    if(argc != 2) {
        std::cout << "usage: wunsch <src.ws>" << std::endl;
        return 0;
    }

    std::ifstream inputFile(argv[1]);
    
    std::stringstream buffer;  
    buffer << inputFile.rdbuf();  
    std::string code(buffer.str());

    TreeDiagram td(code);
    td.ExecuteAndExtract();

    return 0;
}

GeneralDataNode GenNil() {
    auto literal = std::make_shared<ExpressionLiteral>();
    literal->value = GeneralDataNode();
    literal->value.type = GeneralDataNode::TypeNil;
    literal->value.data = std::make_shared<DataNodeNil>();
    return literal->value;
}

GeneralDataNode WSFuncPrint(std::vector<GeneralDataNode> params, Environment & env) {
    for(auto gdn : params) {
        std::cout << gdn.data->ToString();
    }

    std::cout << std::endl;

    return GenNil();
}

GeneralDataNode makeprint() {
    GeneralDataNode printnode;
    printnode.type = GeneralDataNode::TypeSystemFunc;
    printnode.data = std::make_shared<DataNodeSystemFunc>();
    std::dynamic_pointer_cast<DataNodeSystemFunc>(printnode.data)->impl = WSFuncPrint;

    return printnode;
}

void LoadSystemFunctions(std::shared_ptr<ws::asl::Scope> rootScope) {
    std::cout << "Loading System Functions" << std::endl;
    rootScope->contentStack.top()["print"] = makeprint();
}
