#include <memory>

#include <cassert>

#include "AbstractLang.hpp"
#include "Syntaxer.hpp"

using namespace ws;
using namespace asl;

antlrcpp::Any syn::ParseTreeVisitor::visitWeakrefExpr(WunschParser::WeakrefExprContext * ctx) {
    auto weakrefExpr = std::make_shared<ExpressionWeakRef>();

    weakrefExpr->ref = visit(ctx->expr()).as<std::shared_ptr<ExpressionBase>>();

    return std::dynamic_pointer_cast<ExpressionBase>(weakrefExpr);
}

antlrcpp::Any syn::ParseTreeVisitor::visitDerefExpr(WunschParser::DerefExprContext * ctx) {
    if(ctx->op->getText() == "?") { /// optional deref
        auto opderefExpr = std::make_shared<ExpressionOptionalDeref>();

        opderefExpr->expr = visit(ctx->expr()).as<std::shared_ptr<ExpressionBase>>();

        return std::dynamic_pointer_cast<ExpressionBase>(opderefExpr);
    } else {                        /// force deref
        auto forceDerefExpr = std::make_shared<ExpressionStrongDeref>();

        forceDerefExpr->expr = visit(ctx->expr()).as<std::shared_ptr<ExpressionBase>>();

        return std::dynamic_pointer_cast<ExpressionBase>(forceDerefExpr);
    }
}
