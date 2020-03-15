#include <exception>
#include <iostream>

#include <cassert>

#include "ExprFuncCall.hpp"
#include "GeneralDataNodeFactory.hpp"

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

    if(funcStorage->withArrTail) {
        /// handle params with array tail
        /// assure the parameters number
        if(funcStorage->paramNames.size() > params.size()) {
            env.ReportError(std::runtime_error("Argument number wrong, expecting at least " + 
                                                std::to_string(funcStorage->paramNames.size()) + 
                                                ", got " + std::to_string(params.size()) + "."));
            return GeneralDataNode();
        }
    } else {
        /// handle fixed params
        /// assure the parameters number
        if(funcStorage->paramNames.size() != params.size()) {
            env.ReportError(std::runtime_error("Argument number wrong, expecting " + 
                                                std::to_string(funcStorage->paramNames.size()) + 
                                                ", got " + std::to_string(params.size()) + "."));
            return GeneralDataNode();
        }
    }

    /// bind the parameters
    std::map<std::string, GeneralDataNode> pour;

    /// fixed param part
    for(size_t i = 0; i < funcStorage->paramNames.size(); ++i) {
        auto currParam = params[i]->Eval(env);
        auto currName = funcStorage->paramNames[i];

        pour[currName] = currParam;
    }

    /// array param part
    if(funcStorage->withArrTail) {
        /// generate a list for extra params
        GeneralDataNode listGDN;
        listGDN.type = GeneralDataNode::DataType::TypeList;
        listGDN.data = std::make_shared<DataNodeList>();
        auto listNode = std::dynamic_pointer_cast<DataNodeList>(listGDN.data);

        /// calculate the param values
        for(size_t i = funcStorage->paramNames.size(); i < params.size(); ++i) {
            auto currParam = params[i]->Eval(env);
            listNode->value.push_back(currParam);
        }

        /// bind the array
        pour[funcStorage->arrName] = listGDN;
    }

    /// Prepare the environment
    env.thisStack.push(funcStorage->thisDict);

    /// push a nil flag to the return stack, also as default return value
    auto nilFlag = GeneralDataNodeFactory::MakeNilGDN();

    env.returnStack.push(nilFlag);

    /// execute
    funcStorage->body->Execute(env, &pour);

    /// retrive the result
    auto result = env.returnStack.top(); 
    env.returnStack.pop();

    /// restore the environment
    env.thisStack.pop();

    return result;
}
