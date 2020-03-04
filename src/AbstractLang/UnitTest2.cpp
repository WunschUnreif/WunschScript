#include <iostream>
#include <memory>

#include <cassert>

#include "AbstractLang.hpp"

using namespace ws::asl;

std::shared_ptr<Scope> rootScope;
Environment env;

// # test basic expressions
// var x = 1;          # stmt1

// var dict1 = {
//     x : 3,
//     y : 2,
// };                  # stmt 2

// var foo = (dict) => {
//     dict.z = dict.x + dict.y * 5 % 3; # ==> 3 + 2 * 5 % 3 = 4
//     return x;
// };                  # stmt 3

// var rs = foo(dict1);# stmt 4

// # print results: {rs, dict1}

void init() {
    rootScope = std::make_shared<Scope>();
    rootScope->enableTraceup = false;
    env.currentScope = rootScope;
}

std::shared_ptr<ExpressionBase> GenIntLiteralExpr(int64_t x) {
    auto literal = std::make_shared<ExpressionLiteral>();
    literal->value = GeneralDataNode();
    literal->value.type = GeneralDataNode::TypeInt;
    literal->value.data = std::make_shared<DataNodeInt>();
    std::dynamic_pointer_cast<DataNodeInt>(literal->value.data)->value = x;
    return literal;
}

std::shared_ptr<ExpressionBase> GenNilLiteralExpr(int64_t x) {
    auto literal = std::make_shared<ExpressionLiteral>();
    literal->value = GeneralDataNode();
    literal->value.type = GeneralDataNode::TypeNil;
    literal->value.data = std::make_shared<DataNodeNil>();
    return literal;
}

std::shared_ptr<ExpressionBase> GenIDExpr(const std::string & id) {
    auto expr = std::make_shared<ExpressionID>();
    expr->identifier = id;
    return expr;
}

std::shared_ptr<ExpressionBase> GenDotExpr(const std::string & dict, const std::string & dot) {
    auto expr = std::make_shared<ExpressionMemberAccess>();
    expr->lhs = GenIDExpr(dict);
    expr->id = dot;
    return expr;
}

std::shared_ptr<ExpressionBase> GenAddExpr(std::shared_ptr<ExpressionBase> lhs, std::shared_ptr<ExpressionBase> rhs) {
    auto expr = std::make_shared<ExpressionAdd>();
    expr->lhs = lhs;
    expr->rhs = rhs;
    return expr;
}

std::shared_ptr<ExpressionBase> GenMultExpr(std::shared_ptr<ExpressionBase> lhs, std::shared_ptr<ExpressionBase> rhs) {
    auto expr = std::make_shared<ExpressionMultiply>();
    expr->lhs = lhs;
    expr->rhs = rhs;
    return expr;
}

std::shared_ptr<ExpressionBase> GenModExpr(std::shared_ptr<ExpressionBase> lhs, std::shared_ptr<ExpressionBase> rhs) {
    auto expr = std::make_shared<ExpressionDivMod>();
    expr->lhs = lhs;
    expr->rhs = rhs;
    expr->op = ExpressionDivMod::opMod;
    return expr;
}

void dostmt1() {
    // stmt 1
    auto literal1 = GenIntLiteralExpr(1);
    auto stmt1 = std::make_shared<StatementVariableDefine>();
    stmt1->id = "x";
    stmt1->expr = literal1;

    stmt1->Execute(env);

    // get result;
    std::cout << "var x = 1;" << std::endl;
    std::cout << "\t==> " << GenIDExpr("x")->Eval(env).ToString() << std::endl;
}

void dostmt2() {
    auto literal3 = GenAddExpr(GenIDExpr("x"), GenIntLiteralExpr(2));
    auto literal2 = GenIntLiteralExpr(2);
    auto dictNode = std::make_shared<DataNodeDict>();
    dictNode->generator["x"] = literal3;
    dictNode->generator["y"] = literal2;
    auto dictGDN = GeneralDataNode();
    dictGDN.type = GeneralDataNode::TypeDict;
    dictGDN.data = dictNode;

    auto expr = std::make_shared<ExpressionLiteral>();
    expr->value = dictGDN;

    auto stmt2 = std::make_shared<StatementVariableDefine>();
    stmt2->id = "dict1";
    stmt2->expr = expr;

    stmt2->Execute(env);

    // get result;
    std::cout << "var dict1 = {x:x+2, y:2};" << std::endl;
    std::cout << "\t==> " << GenIDExpr("dict1")->Eval(env).ToString() << std::endl;
}

void dostmt3() {
    auto rhs = GenAddExpr(
        GenDotExpr("dict", "x"),
        GenModExpr(
            GenMultExpr(
                GenDotExpr("dict", "y"),
                GenIntLiteralExpr(5)
            ), 
            GenIntLiteralExpr(3)
        )
    );

    auto stmtAssign = std::make_shared<StatementAssignment>();
    stmtAssign->lhs = GenDotExpr("dict", "z");
    stmtAssign->rhs = rhs;

    auto stmtRtn = std::make_shared<StatementReturn>();
    stmtRtn->expr = GenIDExpr("x");

    auto stmtBlock = StatementBlock();
    stmtBlock.lexScope = std::make_shared<Scope>();
    rootScope->children.push_back(stmtBlock.lexScope);
    stmtBlock.lexScope->parent = rootScope;
    stmtBlock.body.push_back(stmtAssign);
    stmtBlock.body.push_back(stmtRtn);

    auto funcNode = std::make_shared<DataNodeFunc>();
    funcNode->paramNames.push_back("dict");
    funcNode->body = std::move(stmtBlock);
    
    auto funcGDN = GeneralDataNode();
    funcGDN.type = GeneralDataNode::TypeFunc;
    funcGDN.data = funcNode;


    auto expr = std::make_shared<ExpressionLiteral>();
    expr->value = funcGDN;

    auto stmt3 = std::make_shared<StatementVariableDefine>();
    stmt3->id = "foo";
    stmt3->expr = expr;

    stmt3->Execute(env);

    // get result;
    std::cout << "var foo = (dict) => {dict.z = dict.x + dict.y * 5 % 3; return x;};" << std::endl;
    std::cout << "\t==> " << GenIDExpr("foo")->Eval(env).ToString() << std::endl;
}

void dostmt4() {
    auto funccall = std::make_shared<ExpressionFuncCall>();
    funccall->funcObj = GenIDExpr("foo");
    funccall->params.push_back(GenIDExpr("dict1"));

    auto stmt4 = std::make_shared<StatementVariableDefine>();
    stmt4->id = "rs";
    stmt4->expr = funccall;

    stmt4->Execute(env);

    // get result;
    std::cout << "var rs = foo(dict1);" << std::endl;
    std::cout << "\t==> " << GenIDExpr("rs")->Eval(env).ToString() << std::endl;
    std::cout << "dict1;\n\t==> " << GenIDExpr("dict1")->Eval(env).ToString() << std::endl;
}

int main() {
    init();
    dostmt1();
    dostmt2();
    dostmt3();
    dostmt4();

    return 0;
}
