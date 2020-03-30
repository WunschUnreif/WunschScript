#include <exception>
#include <iostream>

#include "ExprCompare.hpp" 

using namespace ws::asl;

GeneralDataNode ExpressionCompare::Eval(Environment & env, bool asLval) {
    /// comparison expression can not serve as left value
    if(asLval) {
        env.ReportError(std::runtime_error("Cannot evaluate comparison as left value."));
        return GeneralDataNode();
    }

    /// evaluate the input expressions
    auto lhsResult = lhs->Eval(env);
    auto rhsResult = rhs->Eval(env);

    /// ensure their type is same
    if(lhsResult.type != rhsResult.type) {
        env.ReportError(std::runtime_error("Cannot evaluate comparison between different type."));
        return GeneralDataNode();
    }

    /// 1. in case comparing int 
    if(lhsResult.type == GeneralDataNode::DataType::TypeInt) {
        return EvalForInt(lhsResult, rhsResult);
    }

    /// 2. in case comparing float
    if(lhsResult.type == GeneralDataNode::DataType::TypeFloat) {
        return EvalForFloat(lhsResult, rhsResult);
    }

    /// 3. in case comparing str
    if(lhsResult.type == GeneralDataNode::DataType::TypeString) {
        return EvalForString(lhsResult, rhsResult);
    }

    /// otherwise, error
    env.ReportError(std::runtime_error("Cannot evaluate comparison between non-[int|float|str] value."));
    return GeneralDataNode();
}

GeneralDataNode ExpressionCompare::EvalForInt(GeneralDataNode lhsIntNode, GeneralDataNode rhsIntNode) {
    /// generate a temp GDN for result
    auto result = GeneralDataNode();
    result.type = GeneralDataNode::DataType::TypeBool;
    result.data = std::make_shared<DataNodeBool>();

    switch(op) {
    case CompareLess:
        std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = 
            std::dynamic_pointer_cast<DataNodeInt>(lhsIntNode.data)->value < 
            std::dynamic_pointer_cast<DataNodeInt>(rhsIntNode.data)->value;
        break;

    case CompareLessEq:
        std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = 
            std::dynamic_pointer_cast<DataNodeInt>(lhsIntNode.data)->value <= 
            std::dynamic_pointer_cast<DataNodeInt>(rhsIntNode.data)->value;
        break;

    case CompareGreaterEq:
        std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = 
            std::dynamic_pointer_cast<DataNodeInt>(lhsIntNode.data)->value >= 
            std::dynamic_pointer_cast<DataNodeInt>(rhsIntNode.data)->value;
        break;

    case CompareGreater:
        std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = 
            std::dynamic_pointer_cast<DataNodeInt>(lhsIntNode.data)->value > 
            std::dynamic_pointer_cast<DataNodeInt>(rhsIntNode.data)->value;
        break;
    }

    return result;
}

GeneralDataNode ExpressionCompare::EvalForFloat(GeneralDataNode lhsFloatNode, GeneralDataNode rhsFloatNode) {
    /// generate a temp GDN for result
    auto result = GeneralDataNode();
    result.type = GeneralDataNode::DataType::TypeBool;
    result.data = std::make_shared<DataNodeBool>();

    switch(op) {
    case CompareLess:
        std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = 
            std::dynamic_pointer_cast<DataNodeFloat>(lhsFloatNode.data)->value < 
            std::dynamic_pointer_cast<DataNodeFloat>(rhsFloatNode.data)->value;
        break;

    case CompareLessEq:
        std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = 
            std::dynamic_pointer_cast<DataNodeFloat>(lhsFloatNode.data)->value <= 
            std::dynamic_pointer_cast<DataNodeFloat>(rhsFloatNode.data)->value;
        break;

    case CompareGreaterEq:
        std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = 
            std::dynamic_pointer_cast<DataNodeFloat>(lhsFloatNode.data)->value >= 
            std::dynamic_pointer_cast<DataNodeFloat>(rhsFloatNode.data)->value;
        break;

    case CompareGreater:
        std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = 
            std::dynamic_pointer_cast<DataNodeFloat>(lhsFloatNode.data)->value > 
            std::dynamic_pointer_cast<DataNodeFloat>(rhsFloatNode.data)->value;
        break;
    }

    return result;
}

GeneralDataNode ExpressionCompare::EvalForString(GeneralDataNode lhsNode, GeneralDataNode rhsNode) {
    /// generate a temp GDN for result
    auto result = GeneralDataNode();
    result.type = GeneralDataNode::DataType::TypeBool;
    result.data = std::make_shared<DataNodeBool>();

    switch(op) {
    case CompareLess:
        std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = 
            std::dynamic_pointer_cast<DataNodeStr>(lhsNode.data)->value < 
            std::dynamic_pointer_cast<DataNodeStr>(rhsNode.data)->value;
        break;

    case CompareLessEq:
        std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = 
            std::dynamic_pointer_cast<DataNodeStr>(lhsNode.data)->value <= 
            std::dynamic_pointer_cast<DataNodeStr>(rhsNode.data)->value;
        break;

    case CompareGreaterEq:
        std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = 
            std::dynamic_pointer_cast<DataNodeStr>(lhsNode.data)->value >= 
            std::dynamic_pointer_cast<DataNodeStr>(rhsNode.data)->value;
        break;

    case CompareGreater:
        std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = 
            std::dynamic_pointer_cast<DataNodeStr>(lhsNode.data)->value > 
            std::dynamic_pointer_cast<DataNodeStr>(rhsNode.data)->value;
        break;
    }

    return result;
}

int64_t ExpressionCompare::GenByteCode(vm::ByteCodeBuilder & builder) {
    int64_t length = 0;

    length += lhs->GenByteCode(builder);
    length += rhs->GenByteCode(builder);

    switch(op) {
    case CompareLess:
        builder.Append(vm::LT);
        break;
    case CompareLessEq:
        builder.Append(vm::LTE);
        break;
    case CompareGreater:
        builder.Append(vm::GT);
        break;
    case CompareGreaterEq:
        builder.Append(vm::GTE);
        break;
    }
    length += vm::OpCodeSize;

    return length;
}
