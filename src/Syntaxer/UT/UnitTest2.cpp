/**
 * @file UnitTest1.cpp
 * @author WunschUnreif (wunschunreif@sjtu.edu.cn)
 * @brief Test on literal parsing
 * @version 0.1
 * @date 2020-03-07
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#include <iostream>
#include <fstream>
#include <vector>

#include "WunschLexer.h"
#include "WunschParser.h"

#include "Syntaxer.hpp"

#include "AbstractLang.hpp"

using namespace ws::syn;
using namespace ws::asl;
using namespace std;

Environment env;

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

int main(int argc, char ** argv) {
    for(int i = 1; i < argc; ++i) {
        std::ifstream ifs(argv[i]);
        antlr4::ANTLRInputStream input(ifs);

        WunschLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);

        tokens.fill();

        WunschParser parser(&tokens);

        auto prog = parser.program();

        ParseTreeVisitor visitor;
        auto runnable = visitor.visit(prog).as<std::shared_ptr<Program>>();

        runnable->rootScope->contentStack.top()["print"] = makeprint();

        runnable->Execute();
    }

    return 0;
}
