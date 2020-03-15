
// Generated from Wunsch.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "WunschVisitor.h"


/**
 * This class provides an empty implementation of WunschVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  WunschBaseVisitor : public WunschVisitor {
public:

  virtual antlrcpp::Any visitProgram(WunschParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmt(WunschParser::StmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitThisExpr(WunschParser::ThisExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeepCopyExpr(WunschParser::DeepCopyExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinNotExpr(WunschParser::BinNotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogiAndExpr(WunschParser::LogiAndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMultdivExpr(WunschParser::MultdivExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBracketExpr(WunschParser::BracketExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAddMinExpr(WunschParser::AddMinExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeepCopyModifyExpr(WunschParser::DeepCopyModifyExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogiNotExpr(WunschParser::LogiNotExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBracoAccessExpr(WunschParser::BracoAccessExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinOrExpr(WunschParser::BinOrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinXorExpr(WunschParser::BinXorExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFuncallExpr(WunschParser::FuncallExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunDefLiteral(WunschParser::FunDefLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteralExpr(WunschParser::LiteralExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLogiOrExpr(WunschParser::LogiOrExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBinAndExpr(WunschParser::BinAndExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMemberAccessExpr(WunschParser::MemberAccessExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnaryPMExpr(WunschParser::UnaryPMExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdExpr(WunschParser::IdExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompareExpr(WunschParser::CompareExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitEqualExpr(WunschParser::EqualExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral(WunschParser::LiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDecInteger(WunschParser::DecIntegerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitOctInteger(WunschParser::OctIntegerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitHexInteger(WunschParser::HexIntegerContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFloatLiteral(WunschParser::FloatLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitBoolLiteral(WunschParser::BoolLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStringLiteral(WunschParser::StringLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitListLiteral(WunschParser::ListLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDictLiteral(WunschParser::DictLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNilLiteral(WunschParser::NilLiteralContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitImmediateVarDef(WunschParser::ImmediateVarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPlainVarDef(WunschParser::PlainVarDefContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprAssign(WunschParser::ExprAssignContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFixedFunc(WunschParser::FixedFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArrTailFunc(WunschParser::ArrTailFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIdList(WunschParser::IdListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStmtBlock(WunschParser::StmtBlockContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprList(WunschParser::ExprListContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondStmt(WunschParser::CondStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhileStmt(WunschParser::WhileStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForStmt(WunschParser::ForStmtContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitReturnStmt(WunschParser::ReturnStmtContext *ctx) override {
    return visitChildren(ctx);
  }


};

