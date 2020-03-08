#include <memory>

#include "AbstractLang.hpp"
#include "Syntaxer.hpp"

using namespace ws;
using namespace asl;

antlrcpp::Any syn::ParseTreeVisitor::visitDecInteger(WunschParser::DecIntegerContext * context) {
    /// allocate storage
    auto intNode = std::make_shared<DataNodeInt>();

    /// parse the decimal
    intNode->value = std::stoll(context->DEC_INT()->getText(), nullptr, 10);

    /// generate GDN for value
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeInt;
    result.data = intNode;

    /// should return an expression
    auto exprLit = std::make_shared<ExpressionLiteral>();
    exprLit->value = result;

    return exprLit;
}

antlrcpp::Any syn::ParseTreeVisitor::visitOctInteger(WunschParser::OctIntegerContext * context) {
    /// allocate storage
    auto intNode = std::make_shared<DataNodeInt>();

    /// parse the octal
    intNode->value = std::stoll(context->OCT_INT()->getText(), nullptr, 8);

    /// generate GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeInt;
    result.data = intNode;

    /// should return an expression
    auto exprLit = std::make_shared<ExpressionLiteral>();
    exprLit->value = result;

    return exprLit;
}

antlrcpp::Any syn::ParseTreeVisitor::visitHexInteger(WunschParser::HexIntegerContext * context) {
    /// allocate storage
    auto intNode = std::make_shared<DataNodeInt>();

    /// parse the hex
    intNode->value = std::stoll(context->HEX_INT()->getText(), nullptr, 16);

    /// generate GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeInt;
    result.data = intNode;

    /// should return an expression
    auto exprLit = std::make_shared<ExpressionLiteral>();
    exprLit->value = result;

    return exprLit;
}

antlrcpp::Any syn::ParseTreeVisitor::visitFloatLiteral(WunschParser::FloatLiteralContext * ctx) {
    /// allocate storage
    auto floatNode = std::make_shared<DataNodeFloat>();

    /// parse the float
    floatNode->value = std::stod(ctx->FLOAT()->getText());

    /// generate GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeFloat;
    result.data = floatNode;

    /// should return an expression
    auto exprLit = std::make_shared<ExpressionLiteral>();
    exprLit->value = result;

    return exprLit;
}

antlrcpp::Any syn::ParseTreeVisitor::visitBoolLiteral(WunschParser::BoolLiteralContext * ctx) {
    /// allocate storage
    auto boolNode = std::make_shared<DataNodeBool>();

    /// parse the boolean
    boolNode->value = ctx->BOOLEANLIT()->getText() == "true" ? true : false;

    /// generate GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeBool;
    result.data = boolNode;

    /// should return an expression
    auto exprLit = std::make_shared<ExpressionLiteral>();
    exprLit->value = result;

    return exprLit;
}

antlrcpp::Any syn::ParseTreeVisitor::visitNilLiteral(WunschParser::NilLiteralContext * ctx) {
    /// allocate storage
    auto nilNode = std::make_shared<DataNodeNil>();

    /// generate GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeNil;
    result.data = nilNode;

    /// should return an expression
    auto exprLit = std::make_shared<ExpressionLiteral>();
    exprLit->value = result;

    return exprLit;
}
