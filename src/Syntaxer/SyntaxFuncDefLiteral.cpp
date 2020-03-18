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
    for(auto idContext : ctx->idList(0)->ID()) {
        funcNode->paramNames.push_back(idContext->getText());
    }

    /// parse the capture list
    if(ctx->cap) {
        for(auto idContext : ctx->cap->ID()) {
            funcNode->captureIDs.push_back(idContext->getText());
        }
    }

    if(ctx->body) {
        /// the function has body
        /// fill the body
        funcNode->body = visit(ctx->stmtBlock()).as<std::shared_ptr<StatementBlock>>();
    } else {
        /// the function has a single expression as the result
        /// generate a block to store the return stmt
        funcNode->body = std::make_shared<StatementBlock>();

        /// create a new lexical scope
        auto scope = std::make_shared<Scope>();
        scope->parent = lexScopeStack.top();
        lexScopeStack.top()->children.push_back(scope);

        /// bind the scope
        funcNode->body->lexScope = scope;

        /// push the scope
        lexScopeStack.push(scope);

        /// parse the expr
        auto expr = visit(ctx->expr()).as<std::shared_ptr<ExpressionBase>>();

        /// create a return statement
        auto returnStmt = std::make_shared<StatementReturn>();
        returnStmt->expr = expr;
        FillStmtInfo(returnStmt, ctx->expr());

        /// add the stmt
        funcNode->body->body.push_back(returnStmt);

        /// pop the scope
        lexScopeStack.pop();
    }
    
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
    if(ctx->param) {
        for(auto idContext : ctx->param->ID()) {
            funcNode->paramNames.push_back(idContext->getText());
        }
    }

    /// parse the capture list
    if(ctx->cap) {
        for(auto idContext : ctx->cap->ID()) {
            funcNode->captureIDs.push_back(idContext->getText());
        }
    }

    /// parse the arr name
    funcNode->arrName = ctx->ID()->getText();
    funcNode->withArrTail = true;

    if(ctx->body) {
        /// the function has body
        /// fill the body
        funcNode->body = visit(ctx->stmtBlock()).as<std::shared_ptr<StatementBlock>>();
    } else {
        /// the function has a single expression as the result
        /// generate a block to store the return stmt
        funcNode->body = std::make_shared<StatementBlock>();

        /// create a new lexical scope
        auto scope = std::make_shared<Scope>();
        scope->parent = lexScopeStack.top();
        lexScopeStack.top()->children.push_back(scope);

        /// bind the scope
        funcNode->body->lexScope = scope;

        /// push the scope
        lexScopeStack.push(scope);

        /// parse the expr
        auto expr = visit(ctx->expr()).as<std::shared_ptr<ExpressionBase>>();

        /// create a return statement
        auto returnStmt = std::make_shared<StatementReturn>();
        returnStmt->expr = expr;
        FillStmtInfo(returnStmt, ctx->expr());

        /// add the stmt
        funcNode->body->body.push_back(returnStmt);

        /// pop the scope
        lexScopeStack.pop();
    }

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
