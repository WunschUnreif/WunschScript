#include <iostream>
#include <fstream>

#include "AbstractLang.hpp"

#include "WunschLexer.h"
#include "WunschParser.h"

#include "Syntaxer.hpp"

int main(int argc, char * argv[]) {
    antlr4::ANTLRInputStream inputStream(std::cin);

    /// lexer
    WunschLexer lexer(&inputStream);

    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();

    /// parser
    WunschParser parser(&tokens);

    auto exprContext = parser.program();

    /// if error:
    auto errornum = parser.getNumberOfSyntaxErrors();

    if(errornum > 0) {
        throw std::runtime_error("Syntax errors.");
    }

    /// syntaxer
    ws::syn::ParseTreeVisitor visitor;
    auto prog = visitor.visit(exprContext).as<std::shared_ptr<ws::asl::Program>>();

    ws::vm::ByteCodeBuilder builder;

    auto len = prog->GenByteCode(builder);

    std::cout << "Generated code length = " << len << " Bytes" << std::endl;
    std::cout << builder.bytecode.ToString() << std::endl;

    return 0;
}
