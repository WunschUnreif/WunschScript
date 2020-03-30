#include <exception>

#include "ExprAddMinus.hpp"

using namespace ws::asl;

/* ---------------- Implelentation for add ---------------- */

GeneralDataNode ExpressionAdd::Eval(Environment & env, bool asLval) {
    /// add expression can not serve as left value
    if(asLval) {
        env.ReportError(std::runtime_error("Cannot evaluate add as left value."));
        return GeneralDataNode();
    }

    /// evaluate input expressions
    auto lhsResult = lhs->Eval(env);
    auto rhsResult = rhs->Eval(env);

    /// 1. lhs is list, tread as append
    if(lhsResult.type == GeneralDataNode::DataType::TypeList) {
        return EvalForList(lhsResult, rhsResult);
    }

    /// 2. for int, float, str add, the type should be same
    if(lhsResult.type != rhsResult.type) {
        env.ReportError(std::runtime_error("Cannot evaluate add for different typed value."));
        return GeneralDataNode();
    }

    /// forward the evaluation
    if(lhsResult.type == GeneralDataNode::DataType::TypeInt) {
        return EvalForInt(lhsResult, rhsResult);
    }
    if(lhsResult.type == GeneralDataNode::DataType::TypeFloat) {
        return EvalForFloat(lhsResult, rhsResult);
    }
    if(lhsResult.type == GeneralDataNode::DataType::TypeString) {
        return EvalForString(lhsResult, rhsResult);
    }

    /// 3. otherwise, error
    env.ReportError(std::runtime_error("Cannot evaluate add for non-[int|float|str] value."));
    return GeneralDataNode();
}

GeneralDataNode ExpressionAdd::EvalForInt(GeneralDataNode lhsResult, GeneralDataNode rhsResult) {
    /// Create a temp GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeInt;
    result.data = std::make_shared<DataNodeInt>();

    std::dynamic_pointer_cast<DataNodeInt>(result.data)->value = 
        std::dynamic_pointer_cast<DataNodeInt>(lhsResult.data)->value + 
        std::dynamic_pointer_cast<DataNodeInt>(rhsResult.data)->value;

    return result;
}

GeneralDataNode ExpressionAdd::EvalForFloat(GeneralDataNode lhsResult, GeneralDataNode rhsResult) {
    /// Create a temp GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeFloat;
    result.data = std::make_shared<DataNodeFloat>();

    std::dynamic_pointer_cast<DataNodeFloat>(result.data)->value = 
        std::dynamic_pointer_cast<DataNodeFloat>(lhsResult.data)->value + 
        std::dynamic_pointer_cast<DataNodeFloat>(rhsResult.data)->value;

    return result;
}

GeneralDataNode ExpressionAdd::EvalForString(GeneralDataNode lhsResult, GeneralDataNode rhsResult) {
    /// Create a temp GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeString;
    result.data = std::make_shared<DataNodeStr>();

    std::dynamic_pointer_cast<DataNodeStr>(result.data)->value = 
        std::dynamic_pointer_cast<DataNodeStr>(lhsResult.data)->value + 
        std::dynamic_pointer_cast<DataNodeStr>(rhsResult.data)->value;

    return result;
}

GeneralDataNode ExpressionAdd::EvalForList(GeneralDataNode lhsResult, GeneralDataNode rhsResult) {
    /// Create a temp GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeList;
    result.data = std::make_shared<DataNodeList>();

    /// shallow copy
    std::dynamic_pointer_cast<DataNodeList>(result.data)->value = 
        std::dynamic_pointer_cast<DataNodeList>(lhsResult.data)->value;

    std::dynamic_pointer_cast<DataNodeList>(result.data)->value.push_back(rhsResult);

    return result;
}

int64_t ExpressionAdd::GenByteCode(vm::ByteCodeBuilder & builder) {
    int64_t length = 0;
    length += lhs->GenByteCode(builder);
    length += rhs->GenByteCode(builder);

    builder.Append(vm::OpCode::ADD);
    length += vm::OpCodeSize;

    return length;
}

/* ---------------- Implelentation for add ---------------- */

/* ---------------- Implelentation for minus ---------------- */

GeneralDataNode ExpressionMinus::Eval(Environment & env, bool asLval) {
    /// add expression can not serve as left value
    if(asLval) {
        env.ReportError(std::runtime_error("Cannot evaluate minus as left value."));
        return GeneralDataNode();
    }

    /// evaluate input expressions
    auto lhsResult = lhs->Eval(env);
    auto rhsResult = rhs->Eval(env);

    /// 2. for int, float minus, the type should be same
    if(lhsResult.type != rhsResult.type) {
        env.ReportError(std::runtime_error("Cannot evaluate minus for different typed value."));
        return GeneralDataNode();
    }

    /// forward the evaluation
    if(lhsResult.type == GeneralDataNode::DataType::TypeInt) {
        return EvalForInt(lhsResult, rhsResult);
    }
    if(lhsResult.type == GeneralDataNode::DataType::TypeFloat) {
        return EvalForFloat(lhsResult, rhsResult);
    }

    /// 3. otherwise, error
    env.ReportError(std::runtime_error("Cannot evaluate minus for non-[int|float] value."));
    return GeneralDataNode();
}

GeneralDataNode ExpressionMinus::EvalForInt(GeneralDataNode lhsResult, GeneralDataNode rhsResult) {
    /// Create a temp GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeInt;
    result.data = std::make_shared<DataNodeInt>();

    std::dynamic_pointer_cast<DataNodeInt>(result.data)->value = 
        std::dynamic_pointer_cast<DataNodeInt>(lhsResult.data)->value - 
        std::dynamic_pointer_cast<DataNodeInt>(rhsResult.data)->value;

    return result;
}

GeneralDataNode ExpressionMinus::EvalForFloat(GeneralDataNode lhsResult, GeneralDataNode rhsResult) {
    /// Create a temp GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeFloat;
    result.data = std::make_shared<DataNodeFloat>();

    std::dynamic_pointer_cast<DataNodeFloat>(result.data)->value = 
        std::dynamic_pointer_cast<DataNodeFloat>(lhsResult.data)->value - 
        std::dynamic_pointer_cast<DataNodeFloat>(rhsResult.data)->value;

    return result;
}

int64_t ExpressionMinus::GenByteCode(vm::ByteCodeBuilder & builder) {
    int64_t length = 0;
    length += lhs->GenByteCode(builder);
    length += rhs->GenByteCode(builder);

    builder.Append(vm::OpCode::SUB);
    length += vm::OpCodeSize;

    return length;
}

/* ---------------- Implelentation for minus ---------------- */
