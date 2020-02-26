
// Generated from Wunsch.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "WunschParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by WunschParser.
 */
class  WunschListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterProgram(WunschParser::ProgramContext *ctx) = 0;
  virtual void exitProgram(WunschParser::ProgramContext *ctx) = 0;

  virtual void enterStmt(WunschParser::StmtContext *ctx) = 0;
  virtual void exitStmt(WunschParser::StmtContext *ctx) = 0;

  virtual void enterBinNotExpr(WunschParser::BinNotExprContext *ctx) = 0;
  virtual void exitBinNotExpr(WunschParser::BinNotExprContext *ctx) = 0;

  virtual void enterLogiAndExpr(WunschParser::LogiAndExprContext *ctx) = 0;
  virtual void exitLogiAndExpr(WunschParser::LogiAndExprContext *ctx) = 0;

  virtual void enterMultdivExpr(WunschParser::MultdivExprContext *ctx) = 0;
  virtual void exitMultdivExpr(WunschParser::MultdivExprContext *ctx) = 0;

  virtual void enterBracketExpr(WunschParser::BracketExprContext *ctx) = 0;
  virtual void exitBracketExpr(WunschParser::BracketExprContext *ctx) = 0;

  virtual void enterAddMinExpr(WunschParser::AddMinExprContext *ctx) = 0;
  virtual void exitAddMinExpr(WunschParser::AddMinExprContext *ctx) = 0;

  virtual void enterLogiNotExpr(WunschParser::LogiNotExprContext *ctx) = 0;
  virtual void exitLogiNotExpr(WunschParser::LogiNotExprContext *ctx) = 0;

  virtual void enterBracoAccessExpr(WunschParser::BracoAccessExprContext *ctx) = 0;
  virtual void exitBracoAccessExpr(WunschParser::BracoAccessExprContext *ctx) = 0;

  virtual void enterBinOrExpr(WunschParser::BinOrExprContext *ctx) = 0;
  virtual void exitBinOrExpr(WunschParser::BinOrExprContext *ctx) = 0;

  virtual void enterBinXorExpr(WunschParser::BinXorExprContext *ctx) = 0;
  virtual void exitBinXorExpr(WunschParser::BinXorExprContext *ctx) = 0;

  virtual void enterFuncallExpr(WunschParser::FuncallExprContext *ctx) = 0;
  virtual void exitFuncallExpr(WunschParser::FuncallExprContext *ctx) = 0;

  virtual void enterFunDefLiteral(WunschParser::FunDefLiteralContext *ctx) = 0;
  virtual void exitFunDefLiteral(WunschParser::FunDefLiteralContext *ctx) = 0;

  virtual void enterLiteralExpr(WunschParser::LiteralExprContext *ctx) = 0;
  virtual void exitLiteralExpr(WunschParser::LiteralExprContext *ctx) = 0;

  virtual void enterLogiOrExpr(WunschParser::LogiOrExprContext *ctx) = 0;
  virtual void exitLogiOrExpr(WunschParser::LogiOrExprContext *ctx) = 0;

  virtual void enterBinAndExpr(WunschParser::BinAndExprContext *ctx) = 0;
  virtual void exitBinAndExpr(WunschParser::BinAndExprContext *ctx) = 0;

  virtual void enterMemberAccessExpr(WunschParser::MemberAccessExprContext *ctx) = 0;
  virtual void exitMemberAccessExpr(WunschParser::MemberAccessExprContext *ctx) = 0;

  virtual void enterUnaryPMExpr(WunschParser::UnaryPMExprContext *ctx) = 0;
  virtual void exitUnaryPMExpr(WunschParser::UnaryPMExprContext *ctx) = 0;

  virtual void enterIdExpr(WunschParser::IdExprContext *ctx) = 0;
  virtual void exitIdExpr(WunschParser::IdExprContext *ctx) = 0;

  virtual void enterCompareExpr(WunschParser::CompareExprContext *ctx) = 0;
  virtual void exitCompareExpr(WunschParser::CompareExprContext *ctx) = 0;

  virtual void enterEqualExpr(WunschParser::EqualExprContext *ctx) = 0;
  virtual void exitEqualExpr(WunschParser::EqualExprContext *ctx) = 0;

  virtual void enterLiteral(WunschParser::LiteralContext *ctx) = 0;
  virtual void exitLiteral(WunschParser::LiteralContext *ctx) = 0;

  virtual void enterDecInteger(WunschParser::DecIntegerContext *ctx) = 0;
  virtual void exitDecInteger(WunschParser::DecIntegerContext *ctx) = 0;

  virtual void enterOctInteger(WunschParser::OctIntegerContext *ctx) = 0;
  virtual void exitOctInteger(WunschParser::OctIntegerContext *ctx) = 0;

  virtual void enterHexInteger(WunschParser::HexIntegerContext *ctx) = 0;
  virtual void exitHexInteger(WunschParser::HexIntegerContext *ctx) = 0;

  virtual void enterFloatLiteral(WunschParser::FloatLiteralContext *ctx) = 0;
  virtual void exitFloatLiteral(WunschParser::FloatLiteralContext *ctx) = 0;

  virtual void enterBoolLiteral(WunschParser::BoolLiteralContext *ctx) = 0;
  virtual void exitBoolLiteral(WunschParser::BoolLiteralContext *ctx) = 0;

  virtual void enterStringLiteral(WunschParser::StringLiteralContext *ctx) = 0;
  virtual void exitStringLiteral(WunschParser::StringLiteralContext *ctx) = 0;

  virtual void enterListLiteral(WunschParser::ListLiteralContext *ctx) = 0;
  virtual void exitListLiteral(WunschParser::ListLiteralContext *ctx) = 0;

  virtual void enterDictLiteral(WunschParser::DictLiteralContext *ctx) = 0;
  virtual void exitDictLiteral(WunschParser::DictLiteralContext *ctx) = 0;

  virtual void enterNilLiteral(WunschParser::NilLiteralContext *ctx) = 0;
  virtual void exitNilLiteral(WunschParser::NilLiteralContext *ctx) = 0;

  virtual void enterImmediateVarDef(WunschParser::ImmediateVarDefContext *ctx) = 0;
  virtual void exitImmediateVarDef(WunschParser::ImmediateVarDefContext *ctx) = 0;

  virtual void enterPlainVarDef(WunschParser::PlainVarDefContext *ctx) = 0;
  virtual void exitPlainVarDef(WunschParser::PlainVarDefContext *ctx) = 0;

  virtual void enterExprAssign(WunschParser::ExprAssignContext *ctx) = 0;
  virtual void exitExprAssign(WunschParser::ExprAssignContext *ctx) = 0;

  virtual void enterFuncDef(WunschParser::FuncDefContext *ctx) = 0;
  virtual void exitFuncDef(WunschParser::FuncDefContext *ctx) = 0;

  virtual void enterIdList(WunschParser::IdListContext *ctx) = 0;
  virtual void exitIdList(WunschParser::IdListContext *ctx) = 0;

  virtual void enterStmtBlock(WunschParser::StmtBlockContext *ctx) = 0;
  virtual void exitStmtBlock(WunschParser::StmtBlockContext *ctx) = 0;

  virtual void enterExprList(WunschParser::ExprListContext *ctx) = 0;
  virtual void exitExprList(WunschParser::ExprListContext *ctx) = 0;

  virtual void enterCondStmt(WunschParser::CondStmtContext *ctx) = 0;
  virtual void exitCondStmt(WunschParser::CondStmtContext *ctx) = 0;

  virtual void enterWhileStmt(WunschParser::WhileStmtContext *ctx) = 0;
  virtual void exitWhileStmt(WunschParser::WhileStmtContext *ctx) = 0;

  virtual void enterForStmt(WunschParser::ForStmtContext *ctx) = 0;
  virtual void exitForStmt(WunschParser::ForStmtContext *ctx) = 0;

  virtual void enterReturnStmt(WunschParser::ReturnStmtContext *ctx) = 0;
  virtual void exitReturnStmt(WunschParser::ReturnStmtContext *ctx) = 0;


};

