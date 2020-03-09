#include "WunschLexer.h"
#include "WunschParser.h"

#include "Syntaxer.hpp"

#include "TreeDiagram.hpp"

using namespace ws::asl;
using namespace ws::syn;
using namespace ws::td;

enum Color {
    DEFAULT,
    RED, 
    GREEN,
    YELLOW
};

std::string GetColor(Color c) {
    switch(c) {
        case DEFAULT: return "\033[0m";
        case GREEN: return "\033[32m";
        case RED: return "\033[31m";
        case YELLOW: return "\033[33m";
    }
    return "";
}

class ParsetreeErrorListener : public antlr4::BaseErrorListener {
    void syntaxError(
        antlr4::Recognizer *recognizer, 
        antlr4::Token * offendingSymbol, 
        size_t line, 
        size_t charPositionInLine,
        const std::string &msg, 
        std::exception_ptr e
    ) override {
        std::cerr << GetColor(RED) << "Syntex Error Detected at " << line << ":" << charPositionInLine
                << std::endl 
                << msg << GetColor(DEFAULT) << std::endl;
    }
};

TreeDiagram::TreeDiagram(const std::string & code, const std::string & filename) {
    /// input stream
    antlr4::ANTLRInputStream inputStream(code);

    /// lexer
    WunschLexer lexer(&inputStream);

    antlr4::CommonTokenStream tokens(&lexer);
    tokens.fill();

    /// error handle
    ParsetreeErrorListener errorListener;

    /// parser
    WunschParser parser(&tokens);

    parser.removeErrorListeners();
    parser.addErrorListener(&errorListener);

    auto progContext = parser.program();

    /// if error:
    auto errornum = parser.getNumberOfSyntaxErrors();

    std::cout << GetColor(YELLOW) << "Syntax Error: " << errornum << GetColor(DEFAULT) << std::endl;
    if(errornum > 0) {
        throw std::runtime_error("Syntax errors.");
    }

    /// syntaxer
    ParseTreeVisitor visitor;
    visitor.filename = filename;
    prog = visitor.visit(progContext).as<std::shared_ptr<Program>>();

    /// system support
    LoadSystemFunctions(prog->env.currentScope);
}

GeneralDataNode TreeDiagram::ExecuteAndExtract() {
    GeneralDataNode resultDict;
    resultDict.type = GeneralDataNode::DataType::TypeDict;
    resultDict.data = std::make_shared<DataNodeDict>();

    auto dictNode = std::dynamic_pointer_cast<DataNodeDict>(resultDict.data);

    try {
        prog->Execute();

        auto & scope = prog->env.currentScope->contentStack.top();
        for(auto kv : scope) {
            dictNode->value[kv.first] = kv.second;
        }
    } catch (std::runtime_error & e) {
        std::cerr << GetColor(YELLOW) << e.what() << GetColor(DEFAULT) << std::endl;
    }

    return resultDict;
}


__attribute__((weak)) 
void LoadSystemFunctions(std::shared_ptr<ws::asl::Scope> rootScope) {

}

