#include "UTTool.hpp"

std::shared_ptr<ExpressionBase> GenIntLiteralExpr(int64_t x) {
    auto literal = std::make_shared<ExpressionLiteral>();
    literal->value = GeneralDataNode();
    literal->value.type = GeneralDataNode::TypeInt;
    literal->value.data = std::make_shared<DataNodeInt>();
    std::dynamic_pointer_cast<DataNodeInt>(literal->value.data)->value = x;
    return literal;
}

std::shared_ptr<ExpressionBase> GenNilLiteralExpr() {
    auto literal = std::make_shared<ExpressionLiteral>();
    literal->value = GeneralDataNode();
    literal->value.type = GeneralDataNode::TypeNil;
    literal->value.data = std::make_shared<DataNodeNil>();
    return literal;
}

std::shared_ptr<ExpressionBase> GenIDExpr(const std::string & id) {
    auto expr = std::make_shared<ExpressionID>();
    expr->identifier = id;
    return expr;
}

std::shared_ptr<ExpressionBase> GenDotExpr(const std::string & dict, const std::string & dot) {
    auto expr = std::make_shared<ExpressionMemberAccess>();
    expr->lhs = GenIDExpr(dict);
    expr->id = dot;
    return expr;
}

std::shared_ptr<ExpressionBase> GenAddExpr(std::shared_ptr<ExpressionBase> lhs, std::shared_ptr<ExpressionBase> rhs) {
    auto expr = std::make_shared<ExpressionAdd>();
    expr->lhs = lhs;
    expr->rhs = rhs;
    return expr;
}

std::shared_ptr<ExpressionBase> GenMinusExpr(std::shared_ptr<ExpressionBase> lhs, std::shared_ptr<ExpressionBase> rhs) {
    auto expr = std::make_shared<ExpressionMinus>();
    expr->lhs = lhs;
    expr->rhs = rhs;
    return expr;
}

std::shared_ptr<ExpressionBase> GenMultExpr(std::shared_ptr<ExpressionBase> lhs, std::shared_ptr<ExpressionBase> rhs) {
    auto expr = std::make_shared<ExpressionMultiply>();
    expr->lhs = lhs;
    expr->rhs = rhs;
    return expr;
}

std::shared_ptr<ExpressionBase> GenModExpr(std::shared_ptr<ExpressionBase> lhs, std::shared_ptr<ExpressionBase> rhs) {
    auto expr = std::make_shared<ExpressionDivMod>();
    expr->lhs = lhs;
    expr->rhs = rhs;
    expr->op = ExpressionDivMod::opMod;
    return expr;
}

std::shared_ptr<ExpressionBase> GenLogiOrExpr(std::shared_ptr<ExpressionBase> lhs, std::shared_ptr<ExpressionBase> rhs) {
    auto expr = std::make_shared<ExpressionLogicalBinaryOp>();
    expr->lhs = lhs;
    expr->rhs = rhs;
    expr->op = ExpressionLogicalBinaryOp::LogicalOr;
    return expr;
}

std::shared_ptr<ExpressionBase> GenEqExpr(std::shared_ptr<ExpressionBase> lhs, std::shared_ptr<ExpressionBase> rhs) {
    auto expr = std::make_shared<ExpressionEqual>();
    expr->lhs = lhs;
    expr->rhs = rhs;
    expr->op = ExpressionEqual::TestEqual;
    return expr;
}

std::shared_ptr<ExpressionBase> GenCompExpr(std::shared_ptr<ExpressionBase> lhs, std::shared_ptr<ExpressionBase> rhs, ExpressionCompare::CompareOp op) {
    auto expr = std::make_shared<ExpressionCompare>();
    expr->lhs = lhs;
    expr->rhs = rhs;
    expr->op = op;
    return expr;
}
