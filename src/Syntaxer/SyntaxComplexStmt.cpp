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

    if(ctx->stmtBlock().size() == 2) {
        stmt->elseBranch = visit(ctx->stmtBlock(1)).as<std::shared_ptr<StatementBlock>>();
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
