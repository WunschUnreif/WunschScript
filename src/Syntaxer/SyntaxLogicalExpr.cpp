#include <memory>

#include <cassert>

#include "AbstractLang.hpp"
#include "Syntaxer.hpp"

using namespace ws;
using namespace asl;

antlrcpp::Any syn::ParseTreeVisitor::visitLogiNotExpr(WunschParser::LogiNotExprContext * ctx) {
    auto expr = std::make_shared<ExpressionLogicalNot>();

    expr->rhs = visit(ctx->expr()).as<std::shared_ptr<ExpressionBase>>();

    return std::dynamic_pointer_cast<ExpressionBase>(expr);
}

antlrcpp::Any syn::ParseTreeVisitor::visitLogiAndExpr(WunschParser::LogiAndExprContext * ctx) {
    auto expr = std::make_shared<ExpressionLogicalBinaryOp>();

    expr->lhs = visit(ctx->expr(0)).as<std::shared_ptr<ExpressionBase>>();
    expr->rhs = visit(ctx->expr(1)).as<std::shared_ptr<ExpressionBase>>();
    expr->op = ExpressionLogicalBinaryOp::LogicalAnd;

    return std::dynamic_pointer_cast<ExpressionBase>(expr);
}

antlrcpp::Any syn::ParseTreeVisitor::visitLogiOrExpr(WunschParser::LogiOrExprContext * ctx) {
    auto expr = std::make_shared<ExpressionLogicalBinaryOp>();

    expr->lhs = visit(ctx->expr(0)).as<std::shared_ptr<ExpressionBase>>();
    expr->rhs = visit(ctx->expr(1)).as<std::shared_ptr<ExpressionBase>>();
    expr->op = ExpressionLogicalBinaryOp::LogicalOr;

    return std::dynamic_pointer_cast<ExpressionBase>(expr);
}
