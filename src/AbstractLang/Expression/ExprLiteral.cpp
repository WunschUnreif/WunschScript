#include <exception>

#include "ExprLiteral.hpp"

using namespace ws::asl;

GeneralDataNode ExpressionLiteral::Eval(Environment & env, bool asLval) {
    if(asLval) {
        env.ReportError(std::runtime_error("Literal cannot be evaluated as left value."));
        return GeneralDataNode();
    }

    if(value.type == GeneralDataNode::DataType::TypeDict) {
        /// for dict literal, the values should be eval dynamically
        for(auto kv : std::dynamic_pointer_cast<DataNodeDict>(value.data)->generator) {
            std::dynamic_pointer_cast<DataNodeDict>(value.data)->value[kv.first] = kv.second->Eval(env);
        }

        return value.DeepCopy();
    } else if(value.type == GeneralDataNode::DataType::TypeList) {
        /// for list literal, the values should be eval dynamically
        std::dynamic_pointer_cast<DataNodeList>(value.data)->value.clear();
        
        for(auto gen : std::dynamic_pointer_cast<DataNodeList>(value.data)->generator) {
            std::dynamic_pointer_cast<DataNodeList>(value.data)->value.push_back(gen->Eval(env));
        }

        return value.DeepCopy();
    } else if(value.type == GeneralDataNode::DataType::TypeFunc) {
        /// for func literal, bind the captures
        auto funcNode = std::dynamic_pointer_cast<DataNodeFunc>(value.data);

        funcNode->captureVals.clear();
        for(auto captureID : funcNode->captureIDs) {
            auto captureVal = env.GetDataNode(captureID);

            if(captureVal.type == GeneralDataNode::DataType::TypeUndefined) {
                env.ReportError(std::runtime_error("Capturing " + captureID + ", but undifined in this scope."));
                return GeneralDataNode();
            }

            funcNode->captureVals.push_back(captureVal);
        }

        return value.DeepCopy();
    } else {
        return value.DeepCopy();
    }
}

int64_t ExpressionLiteral::GenByteCode(vm::ByteCodeBuilder & builder) {
    switch(value.type) {
    case GeneralDataNode::DataType::TypeNil:
    case GeneralDataNode::DataType::TypeInt:
    case GeneralDataNode::DataType::TypeFloat:
    case GeneralDataNode::DataType::TypeBool:
    case GeneralDataNode::DataType::TypeString:
        return GenByteCodeForPlainImmediate(builder);

    case GeneralDataNode::DataType::TypeList:
        return GenByteCodeForList(builder);

    case GeneralDataNode::DataType::TypeDict:
        return GenByteCodeForDict(builder);
    
    case GeneralDataNode::DataType::TypeFunc:
        return GenByteCodeForFunc(builder);
    }
}

int64_t ExpressionLiteral::GenByteCodeForPlainImmediate(vm::ByteCodeBuilder & builder) {
    switch(value.type) {
    case GeneralDataNode::DataType::TypeNil:
        builder.Append(vm::OpCode::IMMN);
        return vm::OpCodeSize;

    case GeneralDataNode::DataType::TypeInt:
        builder.Append(vm::OpCode::IMMI, std::dynamic_pointer_cast<DataNodeInt>(value.data)->value);
        return vm::OpCodeSize + vm::OpArgSize;

    case GeneralDataNode::DataType::TypeFloat:
        builder.Append(vm::OpCode::IMMF, std::dynamic_pointer_cast<DataNodeFloat>(value.data)->value);
        return vm::OpCodeSize + vm::OpArgSize;

    case GeneralDataNode::DataType::TypeBool:
        builder.Append(vm::OpCode::IMMB, std::dynamic_pointer_cast<DataNodeBool>(value.data)->value);
        return vm::OpCodeSize + vm::OpArgSize;

    case GeneralDataNode::DataType::TypeString:
        builder.Append(vm::OpCode::IMMS, std::dynamic_pointer_cast<DataNodeStr>(value.data)->value);
        return vm::OpCodeSize + vm::OpArgSize;
    }
    return 0;
}

int64_t ExpressionLiteral::GenByteCodeForList(vm::ByteCodeBuilder & builder) {
    int64_t length = 0;

    builder.Append(vm::OpCode::IMML);               // yield `immL`, top = []
    length += vm::OpCodeSize;

    auto & listGen = std::dynamic_pointer_cast<DataNodeList>(value.data)->generator;

    for(auto expr : listGen) {
        length += expr->GenByteCode(builder);       // push item to the top

        builder.Append(vm::OpCode::ADD);            // top = pop(2) + pop(1) = [..., item]
        length += vm::OpCodeSize;
    }

    return length;
}

int64_t ExpressionLiteral::GenByteCodeForDict(vm::ByteCodeBuilder & builder) {
    int64_t length = 0;

    builder.Append(vm::OpCode::IMMD);               // yield `immD`, top = {}
    length += vm::OpCodeSize;

    auto dictNode = std::dynamic_pointer_cast<DataNodeDict>(value.data);

    for(auto & kv : dictNode->generator) {
        auto & name = kv.first;
        auto   expr = kv.second;

        builder.Append(vm::OpCode::ACCIDL, name);   // yield `accidL key`
        length += vm::OpCodeSize + vm::OpArgSize;

        length += expr->GenByteCode(builder);       // top = val

        builder.Append(vm::OpCode::ASSIGN);         // yield `assign`, {}.key = val
        length += vm::OpCodeSize;
    }

    return length;
}

int64_t ExpressionLiteral::GenByteCodeForFunc(vm::ByteCodeBuilder & builder) {
    int64_t length = 0;

    builder.Append(vm::OpCode::FUNC);               // yield `func`
    length += vm::OpCodeSize;

    auto funcNode = std::dynamic_pointer_cast<DataNodeFunc>(value.data);

    length += funcNode->body->GenByteCode(builder, true); // gen code for body

    // register param names 
    for(auto & paramName : funcNode->paramNames) {
        builder.Append(vm::OpCode::PARAM, paramName);
        length += vm::OpCodeSize + vm::OpArgSize;
    }

    // register arr-param names 
    if(funcNode->withArrTail) {
        builder.Append(vm::OpCode::ARRPARAM, funcNode->arrName);
        length += vm::OpCodeSize + vm::OpArgSize;
    }

    // deal the capture list
    for(auto & capture : funcNode->captureIDs) {
        builder.Append(vm::OpCode::BIND, capture);
        length += vm::OpCodeSize + vm::OpArgSize;
    }

    return length;
}
