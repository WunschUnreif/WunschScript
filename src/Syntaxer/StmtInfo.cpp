#include <memory>

#include <cassert>

#include "AbstractLang.hpp"
#include "Syntaxer.hpp"

using namespace ws;
using namespace asl;


void syn::ParseTreeVisitor::FillStmtInfo(std::shared_ptr<StatementBase> stmt, antlr4::ParserRuleContext * ctx) {
    stmt->info->file = filename;
    stmt->info->line = ctx->getStart()->getLine();
    stmt->info->character = ctx->getStart()->getCharPositionInLine();
    stmt->info->content = ctx->getText();
}
