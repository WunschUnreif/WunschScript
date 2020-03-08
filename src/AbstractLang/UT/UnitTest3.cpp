#include <iostream>
#include <memory>
#include <exception>

#include <cassert>
#include <cstdlib>

#include "AbstractLang.hpp"
#include "UTTool.hpp"

using namespace ws::asl;

std::shared_ptr<Scope> rootScope;
Environment env;

// var factorial = (n) => {
//     if n == 1 || n == 0 {
//         return 1;
//     } else {
//         return n * factorial(n - 1);
//     }
// };

// var rs1 = factorial(0);

// var rs2 = factorial(1);

// var rs3 = factorial(10);

void init() {
    rootScope = std::make_shared<Scope>();
    rootScope->enableTraceup = false;
    env.currentScope = rootScope;
}

void dodeffactorial() {
    auto condExpr = GenLogiOrExpr(
        GenEqExpr(GenIDExpr("n"), GenIntLiteralExpr(1)),
        GenEqExpr(GenIDExpr("n"), GenIntLiteralExpr(0))
    );

    auto thenBr = std::make_shared<StatementReturn>();
    thenBr->expr = GenIntLiteralExpr(1);
    // thenBr->expr = GenNilLiteralExpr(); // uncomment this for error test
    thenBr->info->content = "return 1;";

    auto recur = std::make_shared<ExpressionFuncCall>();
    recur->funcObj = GenIDExpr("factorial");
    recur->params.push_back(GenMinusExpr(GenIDExpr("n"), GenIntLiteralExpr(1)));

    auto elseBr = std::make_shared<StatementReturn>();
    elseBr->expr = GenMultExpr(
        GenIDExpr("n"),
        recur
    );
    elseBr->info->content = "return n * factorial(n - 1);";

    auto ifStmt = std::make_shared<StatementCondition>();
    ifStmt->cond = condExpr;
    ifStmt->info->content = "if n == 0 || n == 1 { return nil; } else { return n * factorial(n - 1); }";

    ifStmt->thenBranch = std::make_shared<StatementBlock>();
    ifStmt->thenBranch->lexScope = std::make_shared<Scope>();
    rootScope->children.push_back(ifStmt->thenBranch->lexScope);
    ifStmt->thenBranch->lexScope->parent = rootScope;
    ifStmt->thenBranch->body.push_back(thenBr);

    ifStmt->elseBranch = std::make_shared<StatementBlock>();
    ifStmt->elseBranch->lexScope = std::make_shared<Scope>();
    rootScope->children.push_back(ifStmt->elseBranch->lexScope);
    ifStmt->elseBranch->lexScope->parent = rootScope;
    ifStmt->elseBranch->body.push_back(elseBr);

    auto stmtBlock = std::make_shared<StatementBlock>();
    stmtBlock->lexScope = std::make_shared<Scope>();
    rootScope->children.push_back(stmtBlock->lexScope);
    stmtBlock->lexScope->parent = rootScope;
    stmtBlock->body.push_back(ifStmt);

    ifStmt->thenBranch->lexScope->parent = stmtBlock->lexScope;
    ifStmt->elseBranch->lexScope->parent = stmtBlock->lexScope;

    auto funcNode = std::make_shared<DataNodeFunc>();
    funcNode->paramNames.push_back("n");
    funcNode->body = stmtBlock;
    
    auto funcGDN = GeneralDataNode();
    funcGDN.type = GeneralDataNode::TypeFunc;
    funcGDN.data = funcNode;

    auto funcLitExpr = std::make_shared<ExpressionLiteral>();
    funcLitExpr->value = funcGDN;

    auto deffactorial = std::make_shared<StatementVariableDefine>();
    deffactorial->id = "factorial";
    deffactorial->expr = funcLitExpr;

    deffactorial->Execute(env);

    std::cout << 
    "var factorial = (n) => {\n"
    "   if n == 1 || n == 0 {\n"
    "       return 1;\n"
    "   } else {\n"
    "       return n * factorial(n - 1);\n"
    "   }\n"
    "};" 
    << std::endl;
    std::cout << "\t==> " << GenIDExpr("factorial")->Eval(env).ToString() << std::endl;
}

void call(int64_t param) {
    auto funccall = std::make_shared<ExpressionFuncCall>();
    funccall->funcObj = GenIDExpr("factorial");
    funccall->params.push_back(GenIntLiteralExpr(param));

    auto stmt4 = std::make_shared<StatementVariableDefine>();
    stmt4->id = "rs" + std::to_string(param);
    stmt4->expr = funccall;

    stmt4->Execute(env);

    // get result;
    std::cout << "var rs" + std::to_string(param) + " = factorial(" + std::to_string(param) + ");" << std::endl;
    std::cout << "\t==> " << GenIDExpr("rs" + std::to_string(param))->Eval(env).ToString() << std::endl;
}

int main() {
    init();

    dodeffactorial();

    // try{
        call(0);
        call(1);
        call(10);
    // } catch(std::runtime_error & e) {
    //     std::cerr << e.what() << std::endl;
    //     exit(0);
    // }

    return 0;
}
