
// Generated from Wunsch.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "WunschListener.h"


/**
 * This class provides an empty implementation of WunschListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  WunschBaseListener : public WunschListener {
public:

  virtual void enterProgram(WunschParser::ProgramContext * /*ctx*/) override { }
  virtual void exitProgram(WunschParser::ProgramContext * /*ctx*/) override { }

  virtual void enterStmt(WunschParser::StmtContext * /*ctx*/) override { }
  virtual void exitStmt(WunschParser::StmtContext * /*ctx*/) override { }

  virtual void enterBinNotExpr(WunschParser::BinNotExprContext * /*ctx*/) override { }
  virtual void exitBinNotExpr(WunschParser::BinNotExprContext * /*ctx*/) override { }

  virtual void enterLogiAndExpr(WunschParser::LogiAndExprContext * /*ctx*/) override { }
  virtual void exitLogiAndExpr(WunschParser::LogiAndExprContext * /*ctx*/) override { }

  virtual void enterMultdivExpr(WunschParser::MultdivExprContext * /*ctx*/) override { }
  virtual void exitMultdivExpr(WunschParser::MultdivExprContext * /*ctx*/) override { }

  virtual void enterBracketExpr(WunschParser::BracketExprContext * /*ctx*/) override { }
  virtual void exitBracketExpr(WunschParser::BracketExprContext * /*ctx*/) override { }

  virtual void enterAddMinExpr(WunschParser::AddMinExprContext * /*ctx*/) override { }
  virtual void exitAddMinExpr(WunschParser::AddMinExprContext * /*ctx*/) override { }

  virtual void enterLogiNotExpr(WunschParser::LogiNotExprContext * /*ctx*/) override { }
  virtual void exitLogiNotExpr(WunschParser::LogiNotExprContext * /*ctx*/) override { }

  virtual void enterBracoAccessExpr(WunschParser::BracoAccessExprContext * /*ctx*/) override { }
  virtual void exitBracoAccessExpr(WunschParser::BracoAccessExprContext * /*ctx*/) override { }

  virtual void enterBinOrExpr(WunschParser::BinOrExprContext * /*ctx*/) override { }
  virtual void exitBinOrExpr(WunschParser::BinOrExprContext * /*ctx*/) override { }

  virtual void enterBinXorExpr(WunschParser::BinXorExprContext * /*ctx*/) override { }
  virtual void exitBinXorExpr(WunschParser::BinXorExprContext * /*ctx*/) override { }

  virtual void enterFuncallExpr(WunschParser::FuncallExprContext * /*ctx*/) override { }
  virtual void exitFuncallExpr(WunschParser::FuncallExprContext * /*ctx*/) override { }

  virtual void enterFunDefLiteral(WunschParser::FunDefLiteralContext * /*ctx*/) override { }
  virtual void exitFunDefLiteral(WunschParser::FunDefLiteralContext * /*ctx*/) override { }

  virtual void enterLiteralExpr(WunschParser::LiteralExprContext * /*ctx*/) override { }
  virtual void exitLiteralExpr(WunschParser::LiteralExprContext * /*ctx*/) override { }

  virtual void enterLogiOrExpr(WunschParser::LogiOrExprContext * /*ctx*/) override { }
  virtual void exitLogiOrExpr(WunschParser::LogiOrExprContext * /*ctx*/) override { }

  virtual void enterBinAndExpr(WunschParser::BinAndExprContext * /*ctx*/) override { }
  virtual void exitBinAndExpr(WunschParser::BinAndExprContext * /*ctx*/) override { }

  virtual void enterMemberAccessExpr(WunschParser::MemberAccessExprContext * /*ctx*/) override { }
  virtual void exitMemberAccessExpr(WunschParser::MemberAccessExprContext * /*ctx*/) override { }

  virtual void enterUnaryPMExpr(WunschParser::UnaryPMExprContext * /*ctx*/) override { }
  virtual void exitUnaryPMExpr(WunschParser::UnaryPMExprContext * /*ctx*/) override { }

  virtual void enterIdExpr(WunschParser::IdExprContext * /*ctx*/) override { }
  virtual void exitIdExpr(WunschParser::IdExprContext * /*ctx*/) override { }

  virtual void enterCompareExpr(WunschParser::CompareExprContext * /*ctx*/) override { }
  virtual void exitCompareExpr(WunschParser::CompareExprContext * /*ctx*/) override { }

  virtual void enterEqualExpr(WunschParser::EqualExprContext * /*ctx*/) override { }
  virtual void exitEqualExpr(WunschParser::EqualExprContext * /*ctx*/) override { }

  virtual void enterLiteral(WunschParser::LiteralContext * /*ctx*/) override { }
  virtual void exitLiteral(WunschParser::LiteralContext * /*ctx*/) override { }

  virtual void enterDecInteger(WunschParser::DecIntegerContext * /*ctx*/) override { }
  virtual void exitDecInteger(WunschParser::DecIntegerContext * /*ctx*/) override { }

  virtual void enterOctInteger(WunschParser::OctIntegerContext * /*ctx*/) override { }
  virtual void exitOctInteger(WunschParser::OctIntegerContext * /*ctx*/) override { }

  virtual void enterHexInteger(WunschParser::HexIntegerContext * /*ctx*/) override { }
  virtual void exitHexInteger(WunschParser::HexIntegerContext * /*ctx*/) override { }

  virtual void enterFloatLiteral(WunschParser::FloatLiteralContext * /*ctx*/) override { }
  virtual void exitFloatLiteral(WunschParser::FloatLiteralContext * /*ctx*/) override { }

  virtual void enterBoolLiteral(WunschParser::BoolLiteralContext * /*ctx*/) override { }
  virtual void exitBoolLiteral(WunschParser::BoolLiteralContext * /*ctx*/) override { }

  virtual void enterStringLiteral(WunschParser::StringLiteralContext * /*ctx*/) override { }
  virtual void exitStringLiteral(WunschParser::StringLiteralContext * /*ctx*/) override { }

  virtual void enterListLiteral(WunschParser::ListLiteralContext * /*ctx*/) override { }
  virtual void exitListLiteral(WunschParser::ListLiteralContext * /*ctx*/) override { }

  virtual void enterDictLiteral(WunschParser::DictLiteralContext * /*ctx*/) override { }
  virtual void exitDictLiteral(WunschParser::DictLiteralContext * /*ctx*/) override { }

  virtual void enterNilLiteral(WunschParser::NilLiteralContext * /*ctx*/) override { }
  virtual void exitNilLiteral(WunschParser::NilLiteralContext * /*ctx*/) override { }

  virtual void enterImmediateVarDef(WunschParser::ImmediateVarDefContext * /*ctx*/) override { }
  virtual void exitImmediateVarDef(WunschParser::ImmediateVarDefContext * /*ctx*/) override { }

  virtual void enterPlainVarDef(WunschParser::PlainVarDefContext * /*ctx*/) override { }
  virtual void exitPlainVarDef(WunschParser::PlainVarDefContext * /*ctx*/) override { }

  virtual void enterIdAssign(WunschParser::IdAssignContext * /*ctx*/) override { }
  virtual void exitIdAssign(WunschParser::IdAssignContext * /*ctx*/) override { }

  virtual void enterExprAssign(WunschParser::ExprAssignContext * /*ctx*/) override { }
  virtual void exitExprAssign(WunschParser::ExprAssignContext * /*ctx*/) override { }

  virtual void enterFuncDef(WunschParser::FuncDefContext * /*ctx*/) override { }
  virtual void exitFuncDef(WunschParser::FuncDefContext * /*ctx*/) override { }

  virtual void enterIdList(WunschParser::IdListContext * /*ctx*/) override { }
  virtual void exitIdList(WunschParser::IdListContext * /*ctx*/) override { }

  virtual void enterStmtBlock(WunschParser::StmtBlockContext * /*ctx*/) override { }
  virtual void exitStmtBlock(WunschParser::StmtBlockContext * /*ctx*/) override { }

  virtual void enterExprList(WunschParser::ExprListContext * /*ctx*/) override { }
  virtual void exitExprList(WunschParser::ExprListContext * /*ctx*/) override { }

  virtual void enterCondStmt(WunschParser::CondStmtContext * /*ctx*/) override { }
  virtual void exitCondStmt(WunschParser::CondStmtContext * /*ctx*/) override { }

  virtual void enterWhileStmt(WunschParser::WhileStmtContext * /*ctx*/) override { }
  virtual void exitWhileStmt(WunschParser::WhileStmtContext * /*ctx*/) override { }

  virtual void enterForStmt(WunschParser::ForStmtContext * /*ctx*/) override { }
  virtual void exitForStmt(WunschParser::ForStmtContext * /*ctx*/) override { }

  virtual void enterReturnStmt(WunschParser::ReturnStmtContext * /*ctx*/) override { }
  virtual void exitReturnStmt(WunschParser::ReturnStmtContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

