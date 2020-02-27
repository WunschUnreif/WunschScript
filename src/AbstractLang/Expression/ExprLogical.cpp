#include <exception>

#include "ExprLogical.hpp"

using namespace ws::asl;

GeneralDataNode ExpressionLogicalNot::Eval(Environment & env, bool asLval) {
    /// logical not expression can not serve as left value
    if(asLval) {
        env.ReportError(std::runtime_error("Cannot evaluate logical not as left value."));
        return GeneralDataNode();
    }

    /// evaluate the right hand expression
    auto rhsResult = rhs->Eval(env);
    
    /// the result should be a bool
    if(rhsResult.type != GeneralDataNode::DataType::TypeBool) {
        env.ReportError(std::runtime_error("Cannot do logical not on non-bool value."));
        return GeneralDataNode();
    }

    /// generate a temp GDN for result storage
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeBool;
    result.data = std::make_shared<DataNodeBool>();

    /// fill in the value which inverts the rhs result
    std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = !std::dynamic_pointer_cast<DataNodeBool>(rhsResult.data)->value;

    return result;
}

GeneralDataNode ExpressionLogicalBinaryOp::Eval(Environment & env, bool asLval) {
    /// logical not expression can not serve as left value
    if(asLval) {
        env.ReportError(std::runtime_error("Cannot evaluate logical and/or as left value."));
        return GeneralDataNode();
    }

    /// evaluate input expressions
    auto lhsResult = lhs->Eval(env);
    auto rhsResult = rhs->Eval(env);
    
    /// the results should be bool
    if(lhsResult.type != GeneralDataNode::DataType::TypeBool || rhsResult.type != GeneralDataNode::DataType::TypeBool) {
        env.ReportError(std::runtime_error("Cannot do logical and/or on non-bool value."));
        return GeneralDataNode();
    }

    /// generate a temp GDN for result storage
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeBool;
    result.data = std::make_shared<DataNodeBool>();

    /// fill in the value
    switch(op) {
    case LogicalAnd:
        std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = 
            std::dynamic_pointer_cast<DataNodeBool>(lhsResult.data)->value &&
            std::dynamic_pointer_cast<DataNodeBool>(rhsResult.data)->value;
        break;

    case LogicalOr:
        std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = 
            std::dynamic_pointer_cast<DataNodeBool>(lhsResult.data)->value ||
            std::dynamic_pointer_cast<DataNodeBool>(rhsResult.data)->value;
        break;
    }
    
    return result;
}
