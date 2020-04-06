#include <iostream>
#include "Machine/Scope.hpp"
#include "DataRepresentation/DataNode.hpp"
#include "Machine/Executor.hpp"

using namespace ws::vm;

ScopeDirectory dir;

void test1() {
    std::string_view sv = "/1/2/3/4/5/6/7/";

    do {
        std::cout << sv << std::endl;
        sv = dir.GetParentPath(sv);
    } while(sv != "");
}

void test2() {
    dir.InsertName("/", "root_var");
    auto val = dir.Access("/", "root_var", true);
    *val.value.lval = GeneralDataNode(GeneralDataNode::TypeInt, std::make_shared<DataNodeInt>(1));
    
    val = dir.Access("/", "root_var");
    std::cout << val.value.rval.ToString() << std::endl;

    dir.PushScope("/0/");
    val = dir.Access("/0/", "root_var", true);
    *val.value.lval = GeneralDataNode(GeneralDataNode::TypeInt, std::make_shared<DataNodeInt>(2));
    
    val = dir.Access("/0/", "root_var");
    std::cout << val.value.rval.ToString() << std::endl;

    val = dir.Access("/0/1/2/3/", "root_var");
    std::cout << val.value.rval.ToString() << std::endl;
}

int main() {
    test1();
    test2();

    Executor exe;
    std::cout << typeid(exe).name() << std::endl;
}
