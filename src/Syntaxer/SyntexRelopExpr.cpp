#include <memory>

#include <cassert>

#include "AbstractLang.hpp"
#include "Syntaxer.hpp"

using namespace ws;
using namespace asl;

antlrcpp::Any syn::ParseTreeVisitor::visitCompareExpr(WunschParser::CompareExprContext * ctx) {
    auto expr = std::make_shared<ExpressionCompare>();

    expr->lhs = visit(ctx->expr(0)).as<std::shared_ptr<ExpressionBase>>();
    expr->rhs = visit(ctx->expr(1)).as<std::shared_ptr<ExpressionBase>>();

    if(ctx->op->getText() == "<") {
        expr->op = ExpressionCompare::CompareLess;
    } else if(ctx->op->getText() == "<=") {
        expr->op = ExpressionCompare::CompareLessEq;
    } else if(ctx->op->getText() == ">") {
        expr->op = ExpressionCompare::CompareGreater;
    } else {
         expr->op = ExpressionCompare::CompareGreaterEq;
    }

    return std::dynamic_pointer_cast<ExpressionBase>(expr);
}

antlrcpp::Any syn::ParseTreeVisitor::visitEqualExpr(WunschParser::EqualExprContext * ctx) {
    auto expr = std::make_shared<ExpressionEqual>();

    expr->lhs = visit(ctx->expr(0)).as<std::shared_ptr<ExpressionBase>>();
    expr->rhs = visit(ctx->expr(1)).as<std::shared_ptr<ExpressionBase>>();
    expr->op = ctx->op->getText() == "=="  ? ExpressionEqual::TestEqual : ExpressionEqual::TestUnequal;

    return std::dynamic_pointer_cast<ExpressionBase>(expr);
}
