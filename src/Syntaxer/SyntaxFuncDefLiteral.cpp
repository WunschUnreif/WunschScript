#include <memory>

#include <cassert>

#include "AbstractLang.hpp"
#include "Syntaxer.hpp"

using namespace ws;
using namespace asl;

antlrcpp::Any syn::ParseTreeVisitor::visitFunDefLiteral(WunschParser::FunDefLiteralContext * ctx) {
    return std::dynamic_pointer_cast<ExpressionBase>(visit(ctx->funcDef()).as<std::shared_ptr<ExpressionLiteral>>());
}

antlrcpp::Any syn::ParseTreeVisitor::visitFixedFunc(WunschParser::FixedFuncContext * ctx) {
    /// storage for func object
    auto funcNode = std::make_shared<DataNodeFunc>();
    
    /// parse the param names 
    for(auto idContext : ctx->idList()->ID()) {
        funcNode->paramNames.push_back(idContext->getText());
    }

    /// fill the body
    funcNode->body = visit(ctx->stmtBlock()).as<std::shared_ptr<StatementBlock>>();

    /// generate a GDN
    GeneralDataNode funcGDN;
    funcGDN.type = GeneralDataNode::DataType::TypeFunc;
    funcGDN.data = funcNode;

    /// generate the literal expr;
    auto literalExpr = std::make_shared<ExpressionLiteral>();
    literalExpr->value = funcGDN;

    return literalExpr;
}

antlrcpp::Any syn::ParseTreeVisitor::visitArrTailFunc(WunschParser::ArrTailFuncContext * ctx) {
    /// storage for func object
    auto funcNode = std::make_shared<DataNodeFunc>();
    
    /// parse the fixed param names 
    for(auto idContext : ctx->idList()->ID()) {
        funcNode->paramNames.push_back(idContext->getText());
    }

    /// parse the arr name
    funcNode->arrName = ctx->ID()->getText();
    funcNode->withArrTail = true;

    /// fill the body
    funcNode->body = visit(ctx->stmtBlock()).as<std::shared_ptr<StatementBlock>>();

    /// generate a GDN
    GeneralDataNode funcGDN;
    funcGDN.type = GeneralDataNode::DataType::TypeFunc;
    funcGDN.data = funcNode;

    /// generate the literal expr;
    auto literalExpr = std::make_shared<ExpressionLiteral>();
    literalExpr->value = funcGDN;

    return literalExpr;
}

antlrcpp::Any syn::ParseTreeVisitor::visitIdList(WunschParser::IdListContext * ctx) {
    /// this rule should be bypassed.
    assert(false && "Rule node [idList] shouldn't be visited directly!");

    return nullptr;
}
