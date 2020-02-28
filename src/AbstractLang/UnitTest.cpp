#include <iostream>
#include <memory>

#include <cassert>

#include "AbstractLang.hpp"

using namespace ws::asl;

std::shared_ptr<Scope> rootScope;
Environment env;

/// init 
///     var x = 10;
///     var y = 30;
void init() {
    rootScope = std::make_shared<Scope>();

    env.currentScope = rootScope;

    GeneralDataNode x;
    x.type = GeneralDataNode::TypeInt;
    x.data = std::make_shared<DataNodeInt>();
    std::dynamic_pointer_cast<DataNodeInt>(x.data)->value = 10;

    rootScope->content["x"] = x;

    GeneralDataNode y;
    y.type = GeneralDataNode::TypeInt;
    y.data = std::make_shared<DataNodeInt>();
    std::dynamic_pointer_cast<DataNodeInt>(y.data)->value = 30;

    rootScope->content["y"] = y;

    GeneralDataNode z;
    z.type = GeneralDataNode::TypeInt;
    z.data = std::make_shared<DataNodeInt>();
    std::dynamic_pointer_cast<DataNodeInt>(z.data)->value = 20;

    rootScope->content["z"] = z;
}

void test1() {
    std::clog << "Testing : ``` x; x = 20; ```" << std::endl;

    std::shared_ptr<ExpressionBase> expr = std::make_shared<ExpressionID>();
    std::dynamic_pointer_cast<ExpressionID>(expr)->identifier = "x";

    auto gdn = expr->Eval(env, true);
    assert(gdn.type == GeneralDataNode::TypeInt);

    std::cout << std::dynamic_pointer_cast<DataNodeInt>(gdn.data)->value << std::endl;

    std::dynamic_pointer_cast<DataNodeInt>(gdn.data)->value = 20;

    gdn = expr->Eval(env, false);

    std::cout << std::dynamic_pointer_cast<DataNodeInt>(gdn.data)->value << std::endl;
    std::cout << gdn.ToString() << std::endl;
}

void test2() {
    std::clog << "Testing : ``` x < y; ```" << std::endl;

    std::shared_ptr<ExpressionBase> exprX = std::make_shared<ExpressionID>();
    std::dynamic_pointer_cast<ExpressionID>(exprX)->identifier = "x";

    std::shared_ptr<ExpressionBase> exprY = std::make_shared<ExpressionID>();
    std::dynamic_pointer_cast<ExpressionID>(exprY)->identifier = "y";

    std::shared_ptr<ExpressionBase> exprComp = std::make_shared<ExpressionCompare>();
    std::dynamic_pointer_cast<ExpressionCompare>(exprComp)->op = ExpressionCompare::CompareLess;
    std::dynamic_pointer_cast<ExpressionCompare>(exprComp)->lhs = exprX;
    std::dynamic_pointer_cast<ExpressionCompare>(exprComp)->rhs = exprY;

    auto result = exprComp->Eval(env);

    assert(result.type == GeneralDataNode::TypeBool);

    std::cout << std::dynamic_pointer_cast<DataNodeBool>(result.data)->value << std::endl;
    std::cout << result.ToString() << std::endl;
}

void test3() {
    std::clog << "Testing : ``` x == z; x != z; ```" << std::endl;

    std::shared_ptr<ExpressionBase> exprX = std::make_shared<ExpressionID>();
    std::dynamic_pointer_cast<ExpressionID>(exprX)->identifier = "x";

    std::shared_ptr<ExpressionBase> exprY = std::make_shared<ExpressionID>();
    std::dynamic_pointer_cast<ExpressionID>(exprY)->identifier = "z";

    auto expr1 = std::make_shared<ExpressionEqual>();
    expr1->lhs = exprX;
    expr1->rhs = exprY;
    expr1->op = ExpressionEqual::TestEqual;

    auto expr2 = std::make_shared<ExpressionEqual>();
    expr2->lhs = exprX;
    expr2->rhs = exprY;
    expr2->op = ExpressionEqual::TestUnequal;

    auto gdn1 = expr1->Eval(env);
    auto gdn2 = expr2->Eval(env);

    std::cout << gdn1.ToString() << std::endl;
    std::cout << gdn2.ToString() << std::endl;
}

int main() {
    init();

    test1();
    test2();
    test3();

    return 0;
}
