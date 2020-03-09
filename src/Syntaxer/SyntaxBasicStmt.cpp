#include <memory>

#include <cassert>

#include "AbstractLang.hpp"
#include "Syntaxer.hpp"

using namespace ws;
using namespace asl;

antlrcpp::Any syn::ParseTreeVisitor::visitImmediateVarDef(WunschParser::ImmediateVarDefContext * ctx) {
    auto stmt = std::make_shared<StatementVariableDefine>();

    stmt->id = ctx->ID()->getText();
    stmt->expr = visit(ctx->expr()).as<std::shared_ptr<ExpressionBase>>();

    FillStmtInfo(stmt, ctx);
    
    return std::dynamic_pointer_cast<StatementBase>(stmt);
}

static std::shared_ptr<ExpressionBase> GenNilLiteralExpr() {
    auto literal = std::make_shared<ExpressionLiteral>();
    literal->value = GeneralDataNode();
    literal->value.type = GeneralDataNode::TypeNil;
    literal->value.data = std::make_shared<DataNodeNil>();
    return literal;
}

antlrcpp::Any syn::ParseTreeVisitor::visitPlainVarDef(WunschParser::PlainVarDefContext * ctx) {
    auto stmt = std::make_shared<StatementVariableDefine>();

    stmt->id = ctx->ID()->getText();

    stmt->expr = GenNilLiteralExpr();

    FillStmtInfo(stmt, ctx);

    return std::dynamic_pointer_cast<StatementBase>(stmt);
}

antlrcpp::Any syn::ParseTreeVisitor::visitExprAssign(WunschParser::ExprAssignContext * ctx) {
    auto stmt = std::make_shared<StatementAssignment>();

    stmt->lhs = visit(ctx->expr(0)).as<std::shared_ptr<ExpressionBase>>();
    stmt->rhs = visit(ctx->expr(1)).as<std::shared_ptr<ExpressionBase>>();

    FillStmtInfo(stmt, ctx);

    return std::dynamic_pointer_cast<StatementBase>(stmt);
}
