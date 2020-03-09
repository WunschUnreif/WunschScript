#include <iostream>
#include <memory>
#include <string>

#include "AbstractLang.hpp"
#include "Syntaxer.hpp"

using namespace ws;
using namespace asl;

antlrcpp::Any syn::ParseTreeVisitor::visitProgram(WunschParser::ProgramContext * ctx) {
    auto program = std::make_shared<Program>();

    /// make the root scope
    auto rootScope = std::make_shared<Scope>();

    program->rootScope = rootScope;
    program->env.currentScope = rootScope;

    lexScopeStack.push(rootScope);

    /// parse the content
    for(auto stmtCtx : ctx->stmt()) {
        program->statements.push_back(visit(stmtCtx).as<std::shared_ptr<StatementBase>>());
    }

    return program;
}

antlrcpp::Any syn::ParseTreeVisitor::visitStmt(WunschParser::StmtContext * ctx) {
    if(ctx->expr()) {
        auto stmt = std::make_shared<StatementExpression>();
        stmt->expr = visit(ctx->expr()).as<std::shared_ptr<ExpressionBase>>();
        FillStmtInfo(stmt, ctx);
        return std::dynamic_pointer_cast<StatementBase>(stmt);
    } 
    else if(ctx->varDef())      {   return visit(ctx->varDef());        }
    else if(ctx->assignment())  {   return visit(ctx->assignment());    }
    else if(ctx->condStmt())    {   return visit(ctx->condStmt());      }
    else if(ctx->whileStmt())   {   return visit(ctx->whileStmt());     }
    else if(ctx->forStmt())     {   return visit(ctx->forStmt());       }
    else { return visit(ctx->returnStmt()); }
}
