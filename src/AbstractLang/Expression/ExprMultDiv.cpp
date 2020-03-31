#include <exception>
#include <iostream>

#include <cmath>

#include "ExprMultDiv.hpp"

using namespace ws::asl;

/* ---------------- Implelentation for mult ---------------- */

GeneralDataNode ExpressionMultiply::Eval(Environment & env, bool asLval) {
    /// mult expression can not serve as left value
    if(asLval) {
        env.ReportError(std::runtime_error("Cannot evaluate mult as left value."));
        return GeneralDataNode();
    }

    /// evaluate input expressions
    auto lhsResult = lhs->Eval(env);
    auto rhsResult = rhs->Eval(env);

    /// 1. lhs is list, tread as repeat
    if(lhsResult.type == GeneralDataNode::DataType::TypeList && rhsResult.type == GeneralDataNode::DataType::TypeInt) {
        return EvalForList(lhsResult, rhsResult);
    } else if(rhsResult.type == GeneralDataNode::DataType::TypeList && lhsResult.type == GeneralDataNode::DataType::TypeInt) {
        return EvalForList(rhsResult, lhsResult);
    }

    /// 2. for int, float mult, the type should be same
    if(lhsResult.type != rhsResult.type) {
        env.ReportError(std::runtime_error("Cannot evaluate mult for different typed value."));
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
    env.ReportError(std::runtime_error("Cannot evaluate mult for non-[int|float] value."));
    return GeneralDataNode();
}

GeneralDataNode ExpressionMultiply::EvalForInt(GeneralDataNode lhsResult, GeneralDataNode rhsResult) {
    /// Create a temp GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeInt;
    result.data = std::make_shared<DataNodeInt>();

    std::dynamic_pointer_cast<DataNodeInt>(result.data)->value = 
        std::dynamic_pointer_cast<DataNodeInt>(lhsResult.data)->value * 
        std::dynamic_pointer_cast<DataNodeInt>(rhsResult.data)->value;

    return result;
}

GeneralDataNode ExpressionMultiply::EvalForFloat(GeneralDataNode lhsResult, GeneralDataNode rhsResult) {
    /// Create a temp GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeFloat;
    result.data = std::make_shared<DataNodeFloat>();

    std::dynamic_pointer_cast<DataNodeFloat>(result.data)->value = 
        std::dynamic_pointer_cast<DataNodeFloat>(lhsResult.data)->value * 
        std::dynamic_pointer_cast<DataNodeFloat>(rhsResult.data)->value;

    return result;
}

GeneralDataNode ExpressionMultiply::EvalForList(GeneralDataNode lhsResult, GeneralDataNode rhsResult) {
    /// Create a temp GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeList;
    result.data = std::make_shared<DataNodeList>();

    /// repeat the list using shallow copy
    for(int64_t times = 0; times < std::dynamic_pointer_cast<DataNodeInt>(rhsResult.data)->value; ++times) {
        for(auto gdn : std::dynamic_pointer_cast<DataNodeList>(lhsResult.data)->value) {
            std::dynamic_pointer_cast<DataNodeList>(result.data)->value.push_back(gdn);
        }
    }

    return result;
}

int64_t ExpressionMultiply::GenByteCode(vm::ByteCodeBuilder & builder) {
    int64_t length = 0;

    length += lhs->GenByteCode(builder);
    length += rhs->GenByteCode(builder);

    builder.Append(vm::OpCode::MUL);
    length += vm::OpCodeSize;
    
    return length;
}

/* ---------------- Implelentation for mult ---------------- */

/* ---------------- Implelentation for divmod ---------------- */

GeneralDataNode ExpressionDivMod::Eval(Environment & env, bool asLval) {
    /// mult expression can not serve as left value
    if(asLval) {
        env.ReportError(std::runtime_error("Cannot evaluate div/mod as left value."));
        return GeneralDataNode();
    }

    /// evaluate input expressions
    auto lhsResult = lhs->Eval(env);
    auto rhsResult = rhs->Eval(env);

    /// for int, float div/mod, the type should be same
    if(lhsResult.type != rhsResult.type) {
        env.ReportError(std::runtime_error("Cannot evaluate div/mod for different typed value."));
        return GeneralDataNode();
    }

    /// forward the evaluation
    if(lhsResult.type == GeneralDataNode::DataType::TypeInt) {
        auto result =  EvalForInt(lhsResult, rhsResult);
        if(result.type == GeneralDataNode::DataType::TypeUndefined) {
            env.ReportError(std::runtime_error("Divided by zero."));
        }
        return result;
    }
    if(lhsResult.type == GeneralDataNode::DataType::TypeFloat) {
        auto result =  EvalForFloat(lhsResult, rhsResult);
        if(result.type == GeneralDataNode::DataType::TypeUndefined) {
            env.ReportError(std::runtime_error("Float mod is not supported."));
        }
        return result;
    }

    /// otherwise, error
    env.ReportError(std::runtime_error("Cannot evaluate div/mod for non-[int|float] value."));
    return GeneralDataNode();
}

GeneralDataNode ExpressionDivMod::EvalForInt(GeneralDataNode lhsResult, GeneralDataNode rhsResult) {
    /// check divided by 0
    if(std::dynamic_pointer_cast<DataNodeInt>(rhsResult.data)->value == 0) {
        return GeneralDataNode();
    }

    /// Create a temp GDN for result
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeInt;
    result.data = std::make_shared<DataNodeInt>();

    std::dynamic_pointer_cast<DataNodeInt>(result.data)->value = 
        op == OpDivide ? std::dynamic_pointer_cast<DataNodeInt>(lhsResult.data)->value / std::dynamic_pointer_cast<DataNodeInt>(rhsResult.data)->value
           /* OpMod */ : std::dynamic_pointer_cast<DataNodeInt>(lhsResult.data)->value % std::dynamic_pointer_cast<DataNodeInt>(rhsResult.data)->value;

    return result;
}

GeneralDataNode ExpressionDivMod::EvalForFloat(GeneralDataNode lhsResult, GeneralDataNode rhsResult) {
    if(op == OpDivide) {
        /// Create a temp GDN for result
        GeneralDataNode result;
        result.type = GeneralDataNode::DataType::TypeFloat;
        result.data = std::make_shared<DataNodeFloat>();

        /// double divide does not need to consider "/ 0" error.
        std::dynamic_pointer_cast<DataNodeFloat>(result.data)->value = 
            std::dynamic_pointer_cast<DataNodeFloat>(lhsResult.data)->value / 
            std::dynamic_pointer_cast<DataNodeFloat>(rhsResult.data)->value;

        return result;
    } else { 
        /// float mod is not supported
        return GeneralDataNode();
    }
}

int64_t ExpressionDivMod::GenByteCode(vm::ByteCodeBuilder & builder) {
    int64_t length = 0;

    length += lhs->GenByteCode(builder);
    length += rhs->GenByteCode(builder);

    switch(op) {
    case OpDivide:
        builder.Append(vm::OpCode::DIV);
        break;
    case OpMod:
        builder.Append(vm::OpCode::REM);
        break;
    }
    length += vm::OpCodeSize;
    
    return length;
}

/* ---------------- Implelentation for divmod ---------------- */
