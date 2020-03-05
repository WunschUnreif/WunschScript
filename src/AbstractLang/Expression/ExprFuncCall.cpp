#include <exception>
#include <iostream>

#include <cassert>

#include "ExprFuncCall.hpp"

using namespace ws::asl;

GeneralDataNode ExpressionFuncCall::Eval(Environment & env, bool asLval) {
    /// func call expression can not serve as left value
    if(asLval) {
        env.ReportError(std::runtime_error("Cannot evaluate func call as left value."));
        return GeneralDataNode();
    }

    /// evaluate the func object
    auto funcResult = funcObj->Eval(env);

    /// forward evaluation
    if(funcResult.type == GeneralDataNode::DataType::TypeFunc) {
        return EvalForFunc(funcResult, env);
    }
    if(funcResult.type == GeneralDataNode::DataType::TypeSystemFunc) {
        return EvalForSystemFunc(funcResult, env);
    }

    /// otherwise, error
    env.ReportError(std::runtime_error("Cannot call a function which is not a function."));
    return GeneralDataNode();
}

GeneralDataNode ExpressionFuncCall::EvalForSystemFunc(GeneralDataNode func, Environment & env) {
    /// get the function
    auto sysfunc = std::dynamic_pointer_cast<DataNodeSystemFunc>(func.data)->impl;

    /// evaluate the parameters
    std::vector<GeneralDataNode> paramValues;
    for(auto expr : params) {
        paramValues.push_back(expr->Eval(env));
    }

    return sysfunc(paramValues, env);
}

GeneralDataNode ExpressionFuncCall::EvalForFunc(GeneralDataNode func, Environment & env) {
    /// get the function
    auto funcStorage = std::dynamic_pointer_cast<DataNodeFunc>(func.data);

    /// assure the parameters number
    if(funcStorage->paramNames.size() != params.size()) {
        env.ReportError(std::runtime_error("Argument number wrong, expecting " + 
                                            std::to_string(funcStorage->paramNames.size()) + 
                                            ", got " + std::to_string(params.size()) + "."));
        return GeneralDataNode();
    }

    /// bind the parameters
    for(size_t i = 0; i < params.size(); ++i) {
        auto currParam = params[i]->Eval(env);
        auto currName = funcStorage->paramNames[i];

        funcStorage->paramScope.content[currName] = currParam;
    }

    /// Prepare the environment
    auto lastReturnSize = env.returnStack.size();

    env.paramStack.push(funcStorage->paramScope);
    env.thisStack.push(funcStorage->thisDict);

    /// execute
    funcStorage->body->Execute(env);
    
    GeneralDataNode result;
    result.type = GeneralDataNode::DataType::TypeNil;
    result.data = std::make_shared<DataNodeNil>();

    /// function did return something
    if(env.returnStack.size() == lastReturnSize + 1) {
        result = env.returnStack.top(); 
        env.returnStack.pop();
    }

    /// restore the environment
    env.thisStack.pop();
    env.paramStack.pop();

    return result;
}
