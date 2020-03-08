#include <memory>

#include <cassert>

#include "AbstractLang.hpp"
#include "Syntaxer.hpp"

using namespace ws;
using namespace asl;

antlrcpp::Any syn::ParseTreeVisitor::visitBinNotExpr(WunschParser::BinNotExprContext * ctx) {
    auto expr = std::make_shared<ExpressionBinaryNot>();

    expr->rhs = visit(ctx->expr()).as<std::shared_ptr<ExpressionBase>>();

    return std::dynamic_pointer_cast<ExpressionBase>(expr);
}

antlrcpp::Any syn::ParseTreeVisitor::visitBinAndExpr(WunschParser::BinAndExprContext * ctx) {
    auto expr = std::make_shared<ExpressionBinaryBinaryOp>();

    expr->lhs = visit(ctx->expr(0)).as<std::shared_ptr<ExpressionBase>>();
    expr->rhs = visit(ctx->expr(1)).as<std::shared_ptr<ExpressionBase>>();
    expr->op = ExpressionBinaryBinaryOp::BinaryAnd;

    return std::dynamic_pointer_cast<ExpressionBase>(expr);
}

antlrcpp::Any syn::ParseTreeVisitor::visitBinOrExpr(WunschParser::BinOrExprContext * ctx) {
    auto expr = std::make_shared<ExpressionBinaryBinaryOp>();

    expr->lhs = visit(ctx->expr(0)).as<std::shared_ptr<ExpressionBase>>();
    expr->rhs = visit(ctx->expr(1)).as<std::shared_ptr<ExpressionBase>>();
    expr->op = ExpressionBinaryBinaryOp::BinaryOr;

    return std::dynamic_pointer_cast<ExpressionBase>(expr);
}

antlrcpp::Any syn::ParseTreeVisitor::visitBinXorExpr(WunschParser::BinXorExprContext * ctx) {
    auto expr = std::make_shared<ExpressionBinaryBinaryOp>();

    expr->lhs = visit(ctx->expr(0)).as<std::shared_ptr<ExpressionBase>>();
    expr->rhs = visit(ctx->expr(1)).as<std::shared_ptr<ExpressionBase>>();
    expr->op = ExpressionBinaryBinaryOp::BinaryXor;

    return std::dynamic_pointer_cast<ExpressionBase>(expr);
}
