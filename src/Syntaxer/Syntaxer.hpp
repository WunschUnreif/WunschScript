#pragma once

#include <stack>
#include <memory>

#include "AbstractLang.hpp"

#include "WunschVisitor.h"

namespace ws {

namespace syn {

    struct ParseTreeVisitor final : public WunschVisitor {

        antlrcpp::Any visitProgram(WunschParser::ProgramContext *context) override; /* [x] */

        antlrcpp::Any visitStmt(WunschParser::StmtContext *context) override;   /* [x] */

        antlrcpp::Any visitThisExpr(WunschParser::ThisExprContext *context) override;   /* [x] */

        antlrcpp::Any visitDeepCopyExpr(WunschParser::DeepCopyExprContext *context) override;   /* [x] */

        antlrcpp::Any visitBinNotExpr(WunschParser::BinNotExprContext *context) override;   /* [x] */

        antlrcpp::Any visitLogiAndExpr(WunschParser::LogiAndExprContext *context) override; /* [x] */

        antlrcpp::Any visitMultdivExpr(WunschParser::MultdivExprContext *context) override; /* [x] */

        antlrcpp::Any visitBracketExpr(WunschParser::BracketExprContext *context) override; /* [x] */

        antlrcpp::Any visitAddMinExpr(WunschParser::AddMinExprContext *context) override;   /* [x] */

        antlrcpp::Any visitLogiNotExpr(WunschParser::LogiNotExprContext *context) override; /* [x] */

        antlrcpp::Any visitBracoAccessExpr(WunschParser::BracoAccessExprContext *context) override; /* [x] */

        antlrcpp::Any visitBinOrExpr(WunschParser::BinOrExprContext *context) override; /* [x] */

        antlrcpp::Any visitBinXorExpr(WunschParser::BinXorExprContext *context) override;   /* [x] */

        antlrcpp::Any visitFuncallExpr(WunschParser::FuncallExprContext *context) override; /* [x] */

        antlrcpp::Any visitFunDefLiteral(WunschParser::FunDefLiteralContext *context) override; /* [x] */

        antlrcpp::Any visitLiteralExpr(WunschParser::LiteralExprContext *context) override; /* [x] */

        antlrcpp::Any visitLogiOrExpr(WunschParser::LogiOrExprContext *context) override;   /* [x] */

        antlrcpp::Any visitBinAndExpr(WunschParser::BinAndExprContext *context) override;  /* [x] */

        antlrcpp::Any visitMemberAccessExpr(WunschParser::MemberAccessExprContext *context) override;   /* [x] */

        antlrcpp::Any visitUnaryPMExpr(WunschParser::UnaryPMExprContext *context) override; /* [x] */

        antlrcpp::Any visitIdExpr(WunschParser::IdExprContext *context) override;   /* [x] */

        antlrcpp::Any visitCompareExpr(WunschParser::CompareExprContext *context); /* [x] */

        antlrcpp::Any visitEqualExpr(WunschParser::EqualExprContext *context); /* [x] */

        antlrcpp::Any visitLiteral(WunschParser::LiteralContext *context) override; /* [x] */

        antlrcpp::Any visitDecInteger(WunschParser::DecIntegerContext *context) override;   /* [x] */

        antlrcpp::Any visitOctInteger(WunschParser::OctIntegerContext *context) override;   /* [x] */

        antlrcpp::Any visitHexInteger(WunschParser::HexIntegerContext *context) override;   /* [x] */

        antlrcpp::Any visitFloatLiteral(WunschParser::FloatLiteralContext *context) override;   /* [x] */

        antlrcpp::Any visitBoolLiteral(WunschParser::BoolLiteralContext *context) override; /* [x] */

        antlrcpp::Any visitStringLiteral(WunschParser::StringLiteralContext *context) override; /* [x] */

        antlrcpp::Any visitListLiteral(WunschParser::ListLiteralContext *context) override; /* [x] */

        antlrcpp::Any visitDictLiteral(WunschParser::DictLiteralContext *context) override; /* [x] */

        antlrcpp::Any visitNilLiteral(WunschParser::NilLiteralContext *context) override;   /* [x] */

        antlrcpp::Any visitImmediateVarDef(WunschParser::ImmediateVarDefContext *context) override; /* [x] */

        antlrcpp::Any visitPlainVarDef(WunschParser::PlainVarDefContext *context) override; /* [x] */

        antlrcpp::Any visitExprAssign(WunschParser::ExprAssignContext *context) override;   /* [x] */

        antlrcpp::Any visitFixedFunc(WunschParser::FixedFuncContext *context) override; /* [x] */

        antlrcpp::Any visitArrTailFunc(WunschParser::ArrTailFuncContext *context) override; /* [x] */

        antlrcpp::Any visitIdList(WunschParser::IdListContext *context) override;   /* [x] */

        antlrcpp::Any visitStmtBlock(WunschParser::StmtBlockContext *context) override; /* [x] */

        antlrcpp::Any visitExprList(WunschParser::ExprListContext *context) override;   /* [x] */

        antlrcpp::Any visitCondStmt(WunschParser::CondStmtContext *context) override;   /* [x] */

        antlrcpp::Any visitWhileStmt(WunschParser::WhileStmtContext *context) override; /* [x] */

        antlrcpp::Any visitForStmt(WunschParser::ForStmtContext *context) override; /* [x] */

        antlrcpp::Any visitReturnStmt(WunschParser::ReturnStmtContext *context) override;   /* [x] */

        antlrcpp::Any visitDeepCopyModifyExpr(WunschParser::DeepCopyModifyExprContext *context) override;  /* [x] */

        antlrcpp::Any visitBr(WunschParser::BrContext * context) override {return nullptr;};

        antlrcpp::Any visitWeakrefExpr(WunschParser::WeakrefExprContext *context) override;  /* [x] */

        antlrcpp::Any visitDerefExpr(WunschParser::DerefExprContext *context) override;  /* [x] */


        std::string filename;

    protected:
        std::stack<std::shared_ptr<ws::asl::Scope>> lexScopeStack;

        void FillStmtInfo(std::shared_ptr<ws::asl::StatementBase> stmt, antlr4::ParserRuleContext * ctx);

    };

}

}