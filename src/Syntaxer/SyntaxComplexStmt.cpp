#include <iostream>
#include <memory>
#include <string>

#include "AbstractLang.hpp"
#include "Syntaxer.hpp"

using namespace ws;
using namespace asl;

antlrcpp::Any syn::ParseTreeVisitor::visitCondStmt(WunschParser::CondStmtContext * ctx) {
    auto stmt = std::make_shared<StatementCondition>();

    stmt->cond = visit(ctx->expr()).as<std::shared_ptr<ExpressionBase>>();
    stmt->thenBranch = visit(ctx->stmtBlock(0)).as<std::shared_ptr<StatementBlock>>();

    if(ctx->elbr) {
        // else {...}
        stmt->elseBranch = visit(ctx->elbr).as<std::shared_ptr<StatementBlock>>();
    } else if(ctx->elif) {
        // else if(...) ...
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
        block->body.push_back(visit(ctx->elif).as<std::shared_ptr<StatementBase>>());

        /// pop the scope node
        lexScopeStack.pop();

        stmt->elseBranch = block;
    }

    FillStmtInfo(stmt, ctx);

    return std::dynamic_pointer_cast<StatementBase>(stmt);
}

antlrcpp::Any syn::ParseTreeVisitor::visitWhileStmt(WunschParser::WhileStmtContext * ctx) {
    auto stmt = std::make_shared<StatementWhileLoop>();

    stmt->cond = visit(ctx->expr()).as<std::shared_ptr<ExpressionBase>>();
    stmt->loopBody = visit(ctx->stmtBlock()).as<std::shared_ptr<StatementBlock>>();

    FillStmtInfo(stmt, ctx);
    
    return std::dynamic_pointer_cast<StatementBase>(stmt);
}

antlrcpp::Any syn::ParseTreeVisitor::visitForStmt(WunschParser::ForStmtContext * ctx) {
    auto stmt = std::make_shared<StatementForLoop>();

    stmt->iteratorName = ctx->ID()->getText();
    stmt->toIter = visit(ctx->expr()).as<std::shared_ptr<ExpressionBase>>();
    stmt->loopBody = visit(ctx->stmtBlock()).as<std::shared_ptr<StatementBlock>>();

    FillStmtInfo(stmt, ctx);
    
    return std::dynamic_pointer_cast<StatementBase>(stmt);
}

antlrcpp::Any syn::ParseTreeVisitor::visitReturnStmt(WunschParser::ReturnStmtContext * ctx) {
    auto stmt = std::make_shared<StatementReturn>();

    stmt->expr = visit(ctx->expr()).as<std::shared_ptr<ExpressionBase>>();

    FillStmtInfo(stmt, ctx);
    
    return std::dynamic_pointer_cast<StatementBase>(stmt);
}
