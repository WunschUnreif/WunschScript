#include <exception>

#include "ExprBin.hpp"

using namespace ws::asl;

GeneralDataNode ExpressionBinaryNot::Eval(Environment & env, bool asLval) {
    /// logical not expression can not serve as left value
    if(asLval) {
        env.ReportError(std::runtime_error("Cannot evaluate binary not as left value."));
        return GeneralDataNode();
    }

    /// evaluate the right hand expression
    auto rhsResult = rhs->Eval(env);
    
    /// the result should be a int
    if(rhsResult.type != GeneralDataNode::DataType::TypeInt) {
        env.ReportError(std::runtime_error("Cannot do binary not on non-int value."));
        return GeneralDataNode();
    }

    /// generate a temp GDN for result storage
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeInt;
    result.data = std::make_shared<DataNodeInt>();

    /// fill in the value which inverts the rhs result
    std::dynamic_pointer_cast<DataNodeInt>(result.data)->value = ~std::dynamic_pointer_cast<DataNodeInt>(rhsResult.data)->value;

    return result;
}

GeneralDataNode ExpressionBinaryBinaryOp::Eval(Environment & env, bool asLval) {
    /// logical not expression can not serve as left value
    if(asLval) {
        env.ReportError(std::runtime_error("Cannot evaluate binary and/or/xor as left value."));
        return GeneralDataNode();
    }

    /// evaluate input expressions
    auto lhsResult = lhs->Eval(env);
    auto rhsResult = rhs->Eval(env);
    
    /// the results should be int
    if(lhsResult.type != GeneralDataNode::DataType::TypeInt || rhsResult.type != GeneralDataNode::DataType::TypeInt) {
        env.ReportError(std::runtime_error("Cannot do binary and/or/xor on non-int value."));
        return GeneralDataNode();
    }

    /// generate a temp GDN for result storage
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeInt;
    result.data = std::make_shared<DataNodeBool>();

    /// fill in the value
    switch(op) {
    case BinaryAnd:
        std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = 
            std::dynamic_pointer_cast<DataNodeBool>(lhsResult.data)->value &
            std::dynamic_pointer_cast<DataNodeBool>(rhsResult.data)->value;
        break;

    case BinaryOr:
        std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = 
            std::dynamic_pointer_cast<DataNodeBool>(lhsResult.data)->value ||
            std::dynamic_pointer_cast<DataNodeBool>(rhsResult.data)->value;
        break;

    case BinaryXor:
        std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = 
            std::dynamic_pointer_cast<DataNodeBool>(lhsResult.data)->value ^
            std::dynamic_pointer_cast<DataNodeBool>(rhsResult.data)->value;
        break;
    }
    
    return result;
}
