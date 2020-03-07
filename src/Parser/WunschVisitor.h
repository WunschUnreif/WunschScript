
// Generated from Wunsch.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "WunschParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by WunschParser.
 */
class  WunschVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by WunschParser.
   */
    virtual antlrcpp::Any visitProgram(WunschParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitStmt(WunschParser::StmtContext *context) = 0;

    virtual antlrcpp::Any visitThisExpr(WunschParser::ThisExprContext *context) = 0;

    virtual antlrcpp::Any visitDeepCopyExpr(WunschParser::DeepCopyExprContext *context) = 0;

    virtual antlrcpp::Any visitBinNotExpr(WunschParser::BinNotExprContext *context) = 0;

    virtual antlrcpp::Any visitLogiAndExpr(WunschParser::LogiAndExprContext *context) = 0;

    virtual antlrcpp::Any visitMultdivExpr(WunschParser::MultdivExprContext *context) = 0;

    virtual antlrcpp::Any visitBracketExpr(WunschParser::BracketExprContext *context) = 0;

    virtual antlrcpp::Any visitAddMinExpr(WunschParser::AddMinExprContext *context) = 0;

    virtual antlrcpp::Any visitLogiNotExpr(WunschParser::LogiNotExprContext *context) = 0;

    virtual antlrcpp::Any visitBracoAccessExpr(WunschParser::BracoAccessExprContext *context) = 0;

    virtual antlrcpp::Any visitBinOrExpr(WunschParser::BinOrExprContext *context) = 0;

    virtual antlrcpp::Any visitBinXorExpr(WunschParser::BinXorExprContext *context) = 0;

    virtual antlrcpp::Any visitFuncallExpr(WunschParser::FuncallExprContext *context) = 0;

    virtual antlrcpp::Any visitFunDefLiteral(WunschParser::FunDefLiteralContext *context) = 0;

    virtual antlrcpp::Any visitLiteralExpr(WunschParser::LiteralExprContext *context) = 0;

    virtual antlrcpp::Any visitLogiOrExpr(WunschParser::LogiOrExprContext *context) = 0;

    virtual antlrcpp::Any visitBinAndExpr(WunschParser::BinAndExprContext *context) = 0;

    virtual antlrcpp::Any visitMemberAccessExpr(WunschParser::MemberAccessExprContext *context) = 0;

    virtual antlrcpp::Any visitUnaryPMExpr(WunschParser::UnaryPMExprContext *context) = 0;

    virtual antlrcpp::Any visitIdExpr(WunschParser::IdExprContext *context) = 0;

    virtual antlrcpp::Any visitCompareExpr(WunschParser::CompareExprContext *context) = 0;

    virtual antlrcpp::Any visitEqualExpr(WunschParser::EqualExprContext *context) = 0;

    virtual antlrcpp::Any visitLiteral(WunschParser::LiteralContext *context) = 0;

    virtual antlrcpp::Any visitDecInteger(WunschParser::DecIntegerContext *context) = 0;

    virtual antlrcpp::Any visitOctInteger(WunschParser::OctIntegerContext *context) = 0;

    virtual antlrcpp::Any visitHexInteger(WunschParser::HexIntegerContext *context) = 0;

    virtual antlrcpp::Any visitFloatLiteral(WunschParser::FloatLiteralContext *context) = 0;

    virtual antlrcpp::Any visitBoolLiteral(WunschParser::BoolLiteralContext *context) = 0;

    virtual antlrcpp::Any visitStringLiteral(WunschParser::StringLiteralContext *context) = 0;

    virtual antlrcpp::Any visitListLiteral(WunschParser::ListLiteralContext *context) = 0;

    virtual antlrcpp::Any visitDictLiteral(WunschParser::DictLiteralContext *context) = 0;

    virtual antlrcpp::Any visitNilLiteral(WunschParser::NilLiteralContext *context) = 0;

    virtual antlrcpp::Any visitImmediateVarDef(WunschParser::ImmediateVarDefContext *context) = 0;

    virtual antlrcpp::Any visitPlainVarDef(WunschParser::PlainVarDefContext *context) = 0;

    virtual antlrcpp::Any visitExprAssign(WunschParser::ExprAssignContext *context) = 0;

    virtual antlrcpp::Any visitFixedFunc(WunschParser::FixedFuncContext *context) = 0;

    virtual antlrcpp::Any visitArrTailFunc(WunschParser::ArrTailFuncContext *context) = 0;

    virtual antlrcpp::Any visitIdList(WunschParser::IdListContext *context) = 0;

    virtual antlrcpp::Any visitStmtBlock(WunschParser::StmtBlockContext *context) = 0;

    virtual antlrcpp::Any visitExprList(WunschParser::ExprListContext *context) = 0;

    virtual antlrcpp::Any visitCondStmt(WunschParser::CondStmtContext *context) = 0;

    virtual antlrcpp::Any visitWhileStmt(WunschParser::WhileStmtContext *context) = 0;

    virtual antlrcpp::Any visitForStmt(WunschParser::ForStmtContext *context) = 0;

    virtual antlrcpp::Any visitReturnStmt(WunschParser::ReturnStmtContext *context) = 0;


};

