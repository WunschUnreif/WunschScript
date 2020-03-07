#pragma once

#include "WunschVisitor.h"

namespace ws {

namespace syn {

    struct ParseTreeVisitor final : public WunschVisitor {

        antlrcpp::Any visitProgram(WunschParser::ProgramContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitStmt(WunschParser::StmtContext *context) override { return nullptr; }   /* [ ] */

        antlrcpp::Any visitThisExpr(WunschParser::ThisExprContext *context) override { return nullptr; }   /* [ ] */

        antlrcpp::Any visitDeepCopyExpr(WunschParser::DeepCopyExprContext *context) override { return nullptr; }   /* [ ] */

        antlrcpp::Any visitBinNotExpr(WunschParser::BinNotExprContext *context) override { return nullptr; }   /* [ ] */

        antlrcpp::Any visitLogiAndExpr(WunschParser::LogiAndExprContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitMultdivExpr(WunschParser::MultdivExprContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitBracketExpr(WunschParser::BracketExprContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitAddMinExpr(WunschParser::AddMinExprContext *context) override { return nullptr; }   /* [ ] */

        antlrcpp::Any visitLogiNotExpr(WunschParser::LogiNotExprContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitBracoAccessExpr(WunschParser::BracoAccessExprContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitBinOrExpr(WunschParser::BinOrExprContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitBinXorExpr(WunschParser::BinXorExprContext *context) override { return nullptr; }   /* [ ] */

        antlrcpp::Any visitFuncallExpr(WunschParser::FuncallExprContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitFunDefLiteral(WunschParser::FunDefLiteralContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitLiteralExpr(WunschParser::LiteralExprContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitLogiOrExpr(WunschParser::LogiOrExprContext *context) override { return nullptr; }   /* [ ] */

        antlrcpp::Any visitBinAndExpr(WunschParser::BinAndExprContext *context) override { return nullptr; }   /* [ ] */

        antlrcpp::Any visitMemberAccessExpr(WunschParser::MemberAccessExprContext *context) override { return nullptr; }   /* [ ] */

        antlrcpp::Any visitUnaryPMExpr(WunschParser::UnaryPMExprContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitIdExpr(WunschParser::IdExprContext *context) override { return nullptr; }   /* [ ] */

        antlrcpp::Any visitCompareExpr(WunschParser::CompareExprContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitEqualExpr(WunschParser::EqualExprContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitLiteral(WunschParser::LiteralContext *context) override; /* [x] */

        antlrcpp::Any visitDecInteger(WunschParser::DecIntegerContext *context) override;   /* [x] */

        antlrcpp::Any visitOctInteger(WunschParser::OctIntegerContext *context) override;   /* [x] */

        antlrcpp::Any visitHexInteger(WunschParser::HexIntegerContext *context) override;   /* [x] */

        antlrcpp::Any visitFloatLiteral(WunschParser::FloatLiteralContext *context) override;   /* [x] */

        antlrcpp::Any visitBoolLiteral(WunschParser::BoolLiteralContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitStringLiteral(WunschParser::StringLiteralContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitListLiteral(WunschParser::ListLiteralContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitDictLiteral(WunschParser::DictLiteralContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitNilLiteral(WunschParser::NilLiteralContext *context) override { return nullptr; }   /* [ ] */

        antlrcpp::Any visitImmediateVarDef(WunschParser::ImmediateVarDefContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitPlainVarDef(WunschParser::PlainVarDefContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitExprAssign(WunschParser::ExprAssignContext *context) override { return nullptr; }   /* [ ] */

        antlrcpp::Any visitFixedFunc(WunschParser::FixedFuncContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitArrTailFunc(WunschParser::ArrTailFuncContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitIdList(WunschParser::IdListContext *context) override { return nullptr; }   /* [ ] */

        antlrcpp::Any visitStmtBlock(WunschParser::StmtBlockContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitExprList(WunschParser::ExprListContext *context) override { return nullptr; }   /* [ ] */

        antlrcpp::Any visitCondStmt(WunschParser::CondStmtContext *context) override { return nullptr; }   /* [ ] */

        antlrcpp::Any visitWhileStmt(WunschParser::WhileStmtContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitForStmt(WunschParser::ForStmtContext *context) override { return nullptr; } /* [ ] */

        antlrcpp::Any visitReturnStmt(WunschParser::ReturnStmtContext *context) override { return nullptr; }   /* [ ] */

    };

}

}