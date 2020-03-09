#include <memory>

#include <cassert>

#include "AbstractLang.hpp"
#include "Syntaxer.hpp"

using namespace ws;
using namespace asl;

antlrcpp::Any syn::ParseTreeVisitor::visitUnaryPMExpr(WunschParser::UnaryPMExprContext * ctx) {
    auto expr = std::make_shared<ExpressionUnaryPM>();

    expr->rhs = visit(ctx->expr()).as<std::shared_ptr<ExpressionBase>>();
    expr->op = ctx->op->getText() == "+" ? ExpressionUnaryPM::UnaryPlus : ExpressionUnaryPM::UnaryMinus;

    return std::dynamic_pointer_cast<ExpressionBase>(expr);
}

antlrcpp::Any syn::ParseTreeVisitor::visitAddMinExpr(WunschParser::AddMinExprContext * ctx) {
    if(ctx->op->getText() == "+") {
        auto expr = std::make_shared<ExpressionAdd>();

        expr->lhs = visit(ctx->expr(0)).as<std::shared_ptr<ExpressionBase>>();
        expr->rhs = visit(ctx->expr(1)).as<std::shared_ptr<ExpressionBase>>();

        return std::dynamic_pointer_cast<ExpressionBase>(expr);
    } else {
        auto expr = std::make_shared<ExpressionMinus>();

        expr->lhs = visit(ctx->expr(0)).as<std::shared_ptr<ExpressionBase>>();
        expr->rhs = visit(ctx->expr(1)).as<std::shared_ptr<ExpressionBase>>();

        return std::dynamic_pointer_cast<ExpressionBase>(expr);
    }
}

antlrcpp::Any syn::ParseTreeVisitor::visitMultdivExpr(WunschParser::MultdivExprContext * ctx) {
    if(ctx->op->getText() == "*") {
        auto expr = std::make_shared<ExpressionMultiply>();

        expr->lhs = visit(ctx->expr(0)).as<std::shared_ptr<ExpressionBase>>();
        expr->rhs = visit(ctx->expr(1)).as<std::shared_ptr<ExpressionBase>>();

        return std::dynamic_pointer_cast<ExpressionBase>(expr);
    } else {
        auto expr = std::make_shared<ExpressionDivMod>();

        expr->lhs = visit(ctx->expr(0)).as<std::shared_ptr<ExpressionBase>>();
        expr->rhs = visit(ctx->expr(1)).as<std::shared_ptr<ExpressionBase>>();
        expr->op = ctx->op->getText() == "/" ? ExpressionDivMod::OpDivide : ExpressionDivMod::opMod;

        return std::dynamic_pointer_cast<ExpressionBase>(expr);
    }
}
