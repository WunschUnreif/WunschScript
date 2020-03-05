#include <iostream>
#include <memory>

#include <cassert>

#include "AbstractLang.hpp"
#include "UTTool.hpp"

using namespace ws::asl;

std::shared_ptr<Scope> rootScope;
Environment env;

// var sum = (n) => {
//     var s = 0;
//     while n > 0 {
//         s = s + n;
//         n = n - 1;
//     }
//     return s
// };

// var rs1 = sum(0);

// var rs2 = sum(1);

// var rs3 = sum(100);

void init() {
    rootScope = std::make_shared<Scope>();
    rootScope->enableTraceup = false;
    env.currentScope = rootScope;
}

void dodefsum() {
    /// var s = 0
    auto stmt1 = std::make_shared<StatementVariableDefine>();
    stmt1->id = "s";
    stmt1->expr = GenIntLiteralExpr(0);

    /// s = s + n;
    auto stmt2_1 = std::make_shared<StatementAssignment>();
    stmt2_1->lhs = GenIDExpr("s");
    stmt2_1->rhs = GenAddExpr(GenIDExpr("s"), GenIDExpr("n"));

    /// n = n - 1;
    auto stmt2_2 = std::make_shared<StatementAssignment>();
    stmt2_2->lhs = GenIDExpr("n");
    stmt2_2->rhs = GenMinusExpr(GenIDExpr("n"), GenIntLiteralExpr(1));

    /// n > 0
    auto cond = GenCompExpr(GenIDExpr("n"), GenIntLiteralExpr(0), ExpressionCompare::CompareGreater);

    /// while ...
    auto stmt2 = std::make_shared<StatementWhileLoop>();
    stmt2->cond = cond;
    stmt2->loopBody = std::make_shared<StatementBlock>();

    stmt2->loopBody->lexScope = std::make_shared<Scope>();

    stmt2->loopBody->body.push_back(stmt2_1);
    stmt2->loopBody->body.push_back(stmt2_2);

    /// return s
    auto stmt3 = std::make_shared<StatementReturn>();
    stmt3->expr = GenIDExpr("s");

    /// (n) => {...}
    auto stmtBlock = std::make_shared<StatementBlock>();
    stmtBlock->lexScope = std::make_shared<Scope>();
    rootScope->children.push_back(stmtBlock->lexScope);
    stmtBlock->lexScope->parent = rootScope;
    stmtBlock->body.push_back(stmt1);
    stmtBlock->body.push_back(stmt2);
    stmtBlock->body.push_back(stmt3);

    stmtBlock->lexScope->children.push_back(stmt2->loopBody->lexScope);
    stmt2->loopBody->lexScope->parent = stmtBlock->lexScope;

    auto funcNode = std::make_shared<DataNodeFunc>();
    funcNode->paramNames.push_back("n");
    funcNode->body = stmtBlock;
    
    auto funcGDN = GeneralDataNode();
    funcGDN.type = GeneralDataNode::TypeFunc;
    funcGDN.data = funcNode;

    auto funcLitExpr = std::make_shared<ExpressionLiteral>();
    funcLitExpr->value = funcGDN;

    /// var sum = ...
    auto func = std::make_shared<StatementVariableDefine>();
    func->id = "sum";
    func->expr = funcLitExpr;

    func->Execute(env);

    std::cout << 
    "var sum = (n) => {\n"
    "    var s = 0;\n"
    "    while n > 0 {\n"
    "        s = s + n;\n"
    "        n = n - 1;\n"
    "    }\n"
    "    return s\n"
    "};\n"
    << "\t==> " << GenIDExpr("sum")->Eval(env).ToString() << std::endl;
}

void call(int64_t param) {
    auto funccall = std::make_shared<ExpressionFuncCall>();
    funccall->funcObj = GenIDExpr("sum");
    funccall->params.push_back(GenIntLiteralExpr(param));

    auto stmt4 = std::make_shared<StatementVariableDefine>();
    stmt4->id = "rs" + std::to_string(param);
    stmt4->expr = funccall;

    stmt4->Execute(env);

    // get result;
    std::cout << "var rs" + std::to_string(param) + " = sum(" + std::to_string(param) + ");" << std::endl;
    std::cout << "\t==> " << GenIDExpr("rs" + std::to_string(param))->Eval(env).ToString() << std::endl;
}


int main() {
    init();

    dodefsum();
    call(0);
    call(1);
    call(100);

    return 0;
}
