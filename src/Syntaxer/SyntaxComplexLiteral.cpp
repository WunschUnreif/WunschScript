#include <iostream>
#include <memory>
#include <string>

#include "AbstractLang.hpp"
#include "Syntaxer.hpp"

using namespace ws;
using namespace asl;

static char GetEscapeChar(char literal) {
    switch(literal) {
    case '\"' : return '\"';
    case '\'' : return '\'';
    case '\\' : return '\\';
    case 'a'  : return '\a';
    case 'b'  : return '\b';
    case 'f'  : return '\f';
    case 'n'  : return '\n';
    case 'r'  : return '\r';
    case 't'  : return '\t';
    case 'v'  : return '\v';
    case '?'  : return '\?';
    case '0'  : return '\0';
    default   : return literal;
    }
}

antlrcpp::Any syn::ParseTreeVisitor::visitStringLiteral(WunschParser::StringLiteralContext * ctx) {
    std::string result = "";

    for(auto strContext : ctx->STRING()) {
        auto currstr = strContext->getText();
        for(size_t index = 1; index < currstr.length() - 1; ++index) {
            if(currstr[index] != '\\') {
                result += currstr[index];
            } else {
                ++index;
                result += GetEscapeChar(currstr[index]);
            }
        }
    }

    auto strNode = std::make_shared<DataNodeStr>();
    strNode->value = std::move(result);

    GeneralDataNode strGDN;
    strGDN.type = GeneralDataNode::DataType::TypeString;
    strGDN.data = strNode;

    auto literalExpr = std::make_shared<ExpressionLiteral>();
    literalExpr->value = strGDN;

    return literalExpr;
}

antlrcpp::Any syn::ParseTreeVisitor::visitListLiteral(WunschParser::ListLiteralContext * ctx) {
    /// storage for list
    auto listNode = std::make_shared<DataNodeList>();
    
    /// parse the contents and fill in the generators
    for(auto exprContext : ctx->expr()) {
        auto currExpr = visit(exprContext).as<std::shared_ptr<ExpressionBase>>();

        listNode->generator.push_back(currExpr);
    }

    /// assemble GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeList;
    result.data = listNode;

    /// assemble literal expr
    auto literalExpr = std::make_shared<ExpressionLiteral>();
    literalExpr->value = result;

    return literalExpr;
}

antlrcpp::Any syn::ParseTreeVisitor::visitDictLiteral(WunschParser::DictLiteralContext * ctx) {
    /// storage for dict
    auto dictNode = std::make_shared<DataNodeDict>();
    
    /// parse the contents and fill in the generators
    assert(ctx->ID().size() == ctx->expr().size());

    for(size_t index = 0; index < ctx->ID().size(); ++index) {
        dictNode->generator[ctx->ID(index)->getText()] = 
            visit(ctx->expr(index)).as<std::shared_ptr<ExpressionBase>>();
    }

    /// assemble GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeDict;
    result.data = dictNode;

    /// assemble literal expr
    auto literalExpr = std::make_shared<ExpressionLiteral>();
    literalExpr->value = result;

    return literalExpr;
}
