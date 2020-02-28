#include <exception>

#include "ExprEqual.hpp" 

using namespace ws::asl;

GeneralDataNode ExpressionEqual::Eval(Environment & env, bool asLval) {
    /// euqality expression can not serve as left value
    if(asLval) {
        env.ReportError(std::runtime_error("Cannot evaluate equality as left value."));
        return GeneralDataNode();
    }

    /// evaluate the input expressions
    auto lhsResult = lhs->Eval(env);
    auto rhsResult = rhs->Eval(env);

    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeBool;
    result.data = std::make_shared<DataNodeBool>();

    switch (op) {
    case TestEqual   : std::dynamic_pointer_cast<DataNodeBool>(result.data)->value =  lhsResult.IsEqualTo(rhsResult); break;
    case TestUnequal : std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = !lhsResult.IsEqualTo(rhsResult); break;
    }

    return result;
}
