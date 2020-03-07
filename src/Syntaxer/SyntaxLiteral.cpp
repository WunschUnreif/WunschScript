#include <memory>

#include <cassert>

#include "AbstractLang.hpp"
#include "Syntaxer.hpp"

using namespace ws;
using namespace asl;

antlrcpp::Any syn::ParseTreeVisitor::visitLiteral(WunschParser::LiteralContext * ctx) {
    assert(ctx->children.size() == 1);
    auto chResult = visit(ctx->children[0]);
    return std::dynamic_pointer_cast<ExpressionBase>(chResult.as<std::shared_ptr<ExpressionLiteral>>());
}
