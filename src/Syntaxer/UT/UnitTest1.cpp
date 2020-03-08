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

#include "WunschLexer.h"
#include "WunschParser.h"

#include "Syntaxer.hpp"

#include "AbstractLang.hpp"

using namespace ws::syn;
using namespace ws::asl;
using namespace std;

Environment env;

int main(int argc, char ** argv) {
    for(int i = 1; i < argc; ++i) {
        std::ifstream ifs(argv[i]);
        antlr4::ANTLRInputStream input(ifs);

        WunschLexer lexer(&input);
        antlr4::CommonTokenStream tokens(&lexer);

        tokens.fill();

        WunschParser parser(&tokens);

        auto literal = parser.expr();

        ParseTreeVisitor visitor;
        auto result = visitor.visit(literal);

        std::cout << result.as<std::shared_ptr<ExpressionBase>>()->Eval(env).ToString() << std::endl;
    }

    return 0;
}
