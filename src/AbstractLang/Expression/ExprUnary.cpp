#include <exception>

#include "ExprUnary.hpp"

using namespace ws::asl;

GeneralDataNode ExpressionUnaryPM::Eval(Environment & env, bool asLval) {
    /// can only be right value 
    if(asLval) {
        env.ReportError(std::runtime_error("Unary plus/minus cannot serve as left value."));
        return GeneralDataNode();
    }

    /// first evaluate the right hand expression
    auto rhsResult = rhs->Eval(env);

    /// the result should be either int or float
    if(rhsResult.type != GeneralDataNode::DataType::TypeInt && rhsResult.type != GeneralDataNode::DataType::TypeFloat) {
        env.ReportError(std::runtime_error("Cannpt apply unary plus/minus on non-number value."));
        return GeneralDataNode();
    }

    if(rhsResult.type == GeneralDataNode::DataType::TypeInt) {
        /// forward evaluation for int
        return EvalForInt(rhsResult);
    } else {
        /// forward evaluation for float
        return EvalForFloat(rhsResult);
    }
}

GeneralDataNode ExpressionUnaryPM::EvalForInt(GeneralDataNode intResult) {
    /// generate a temp GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeInt;
    result.data = std::make_shared<DataNodeInt>();

    /// fill in the result
    std::dynamic_pointer_cast<DataNodeInt>(result.data)->value = 
        op ==  UnaryPlus     ? +std::dynamic_pointer_cast<DataNodeInt>(intResult.data)->value
            /* UnaryMinus */ : -std::dynamic_pointer_cast<DataNodeInt>(intResult.data)->value;

    return result;
}

GeneralDataNode ExpressionUnaryPM::EvalForFloat(GeneralDataNode floatResult) {
    /// generate a temp GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeFloat;
    result.data = std::make_shared<DataNodeFloat>();

    /// fill in the result
    std::dynamic_pointer_cast<DataNodeFloat>(result.data)->value = 
        op ==  UnaryPlus     ? +std::dynamic_pointer_cast<DataNodeFloat>(floatResult.data)->value
            /* UnaryMinus */ : -std::dynamic_pointer_cast<DataNodeFloat>(floatResult.data)->value;

    return result;
}
