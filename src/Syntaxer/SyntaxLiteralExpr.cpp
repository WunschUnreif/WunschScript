#include <memory>

#include <cassert>

#include "AbstractLang.hpp"
#include "Syntaxer.hpp"

using namespace ws;
using namespace asl;

antlrcpp::Any syn::ParseTreeVisitor::visitLiteral(WunschParser::LiteralContext * ctx) {
    /// this rule should be bypassed.
    assert(false && "Rule node [literal] shouldn't be visited directly!");

    return nullptr;
}

antlrcpp::Any syn::ParseTreeVisitor::visitLiteralExpr(WunschParser::LiteralExprContext * ctx) {
    /**
     * literalExpr -> literal -> integerLiteral | floatLiteral | ...
     * so we can bypass rule `literal`.
     */
    assert(ctx->literal()->children.size() == 1);
    return std::dynamic_pointer_cast<ExpressionBase>(
        visit(ctx->literal()->children[0])
        .as<std::shared_ptr<ExpressionLiteral>>()
    );
}
