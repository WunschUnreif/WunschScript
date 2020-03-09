#include <memory>

#include <cassert>

#include "AbstractLang.hpp"
#include "Syntaxer.hpp"

using namespace ws;
using namespace asl;

antlrcpp::Any syn::ParseTreeVisitor::visitStmtBlock(WunschParser::StmtBlockContext * ctx) {
    /// create a new lexical scope
    auto scope = std::make_shared<Scope>();

    scope->parent = lexScopeStack.top();
    lexScopeStack.top()->children.push_back(scope);

    /// push the scope node
    lexScopeStack.push(scope);

    /// create the stmt block object
    auto block = std::make_shared<StatementBlock>();

    block->lexScope = scope;
    
    /// parse the body
    for(auto stmtContext : ctx->stmt()) {
        block->body.push_back(visit(stmtContext).as<std::shared_ptr<StatementBase>>());
    }

    /// pop the scope node
    lexScopeStack.pop();

    return block;
}
