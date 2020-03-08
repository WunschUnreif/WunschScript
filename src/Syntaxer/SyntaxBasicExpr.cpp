#include <memory>

#include <cassert>

#include "AbstractLang.hpp"
#include "Syntaxer.hpp"

using namespace ws;
using namespace asl;

antlrcpp::Any syn::ParseTreeVisitor::visitThisExpr(WunschParser::ThisExprContext * ctx) {
    auto thisexpr = std::make_shared<ExpressionThis>();
    
    return std::dynamic_pointer_cast<ExpressionBase>(thisexpr);
}

antlrcpp::Any syn::ParseTreeVisitor::visitIdExpr(WunschParser::IdExprContext * ctx) {
    auto idexpr = std::make_shared<ExpressionID>();

    idexpr->identifier = ctx->ID()->getText();
    
    return std::dynamic_pointer_cast<ExpressionBase>(idexpr);
}

antlrcpp::Any syn::ParseTreeVisitor::visitBracketExpr(WunschParser::BracketExprContext * ctx) {
    return visit(ctx->expr());
}

antlrcpp::Any syn::ParseTreeVisitor::visitDeepCopyExpr(WunschParser::DeepCopyExprContext * ctx) {
    auto deepcopyExpr = std::make_shared<ExpressionDeepCopy>();

    deepcopyExpr->ref = visit(ctx->expr()).as<std::shared_ptr<ExpressionBase>>();

    return std::dynamic_pointer_cast<ExpressionBase>(deepcopyExpr);
}

antlrcpp::Any syn::ParseTreeVisitor::visitMemberAccessExpr(WunschParser::MemberAccessExprContext * ctx) {
    auto membAccExpr = std::make_shared<ExpressionMemberAccess>();

    membAccExpr->lhs = visit(ctx->expr()).as<std::shared_ptr<ExpressionBase>>();
    membAccExpr->id = ctx->ID()->getText();

    return std::dynamic_pointer_cast<ExpressionBase>(membAccExpr);
}

antlrcpp::Any syn::ParseTreeVisitor::visitBracoAccessExpr(WunschParser::BracoAccessExprContext * ctx) {
    auto membAccExpr = std::make_shared<ExpressionMemberAccessCalaulated>();

    membAccExpr->lhs = visit(ctx->expr(0)).as<std::shared_ptr<ExpressionBase>>();
    membAccExpr->rhs = visit(ctx->expr(1)).as<std::shared_ptr<ExpressionBase>>();

    return std::dynamic_pointer_cast<ExpressionBase>(membAccExpr);
}

antlrcpp::Any syn::ParseTreeVisitor::visitExprList(WunschParser::ExprListContext * ctx) {
    /// this rule should be bypassed.
    assert(false && "Rule node [exprList] shouldn't be visited directly!");

    return nullptr;
}

antlrcpp::Any syn::ParseTreeVisitor::visitFuncallExpr(WunschParser::FuncallExprContext * ctx) {
    auto funcCallExpr = std::make_shared<ExpressionFuncCall>();

    funcCallExpr->funcObj = visit(ctx->expr()).as<std::shared_ptr<ExpressionBase>>();

    for(auto exprCtx : ctx->exprList()->expr()) {
        funcCallExpr->params.push_back(visit(exprCtx).as<std::shared_ptr<ExpressionBase>>());
    }

    return std::dynamic_pointer_cast<ExpressionBase>(funcCallExpr);
}

