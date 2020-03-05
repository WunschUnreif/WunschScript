#pragma once 

#include <string>
#include <memory>

#include "AbstractLang.hpp"

using namespace ws::asl;

std::shared_ptr<ExpressionBase> GenIntLiteralExpr(int64_t x);
std::shared_ptr<ExpressionBase> GenNilLiteralExpr();
std::shared_ptr<ExpressionBase> GenIDExpr(const std::string & id);
std::shared_ptr<ExpressionBase> GenDotExpr(const std::string & dict, const std::string & dot);
std::shared_ptr<ExpressionBase> GenAddExpr(std::shared_ptr<ExpressionBase> lhs, std::shared_ptr<ExpressionBase> rhs);
std::shared_ptr<ExpressionBase> GenMinusExpr(std::shared_ptr<ExpressionBase> lhs, std::shared_ptr<ExpressionBase> rhs);
std::shared_ptr<ExpressionBase> GenMultExpr(std::shared_ptr<ExpressionBase> lhs, std::shared_ptr<ExpressionBase> rhs);
std::shared_ptr<ExpressionBase> GenModExpr(std::shared_ptr<ExpressionBase> lhs, std::shared_ptr<ExpressionBase> rhs);
std::shared_ptr<ExpressionBase> GenLogiOrExpr(std::shared_ptr<ExpressionBase> lhs, std::shared_ptr<ExpressionBase> rhs);
std::shared_ptr<ExpressionBase> GenEqExpr(std::shared_ptr<ExpressionBase> lhs, std::shared_ptr<ExpressionBase> rhs);
std::shared_ptr<ExpressionBase> GenCompExpr(std::shared_ptr<ExpressionBase> lhs, std::shared_ptr<ExpressionBase> rhs, ExpressionCompare::CompareOp op);
