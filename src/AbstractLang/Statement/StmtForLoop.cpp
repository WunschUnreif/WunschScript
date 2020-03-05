#include <exception>

#include "StmtForLoop.hpp"

using namespace ws::asl;

bool StatementForLoop::InnerExecute(Environment & env) {
    /// evaluate the iterable
    auto iterableObj = toIter->Eval(env);

    /// for list iteration, iter over elements
    if(iterableObj.type == GeneralDataNode::DataType::TypeList) {
        for(auto currGDN : std::dynamic_pointer_cast<DataNodeList>(iterableObj.data)->value) {
            /// bind the iterator
            loopBody->lexScope->content[iteratorName] = currGDN;

            /// execute the loop body
            auto permitContinue = loopBody->Execute(env);

            if(!permitContinue) return false;
        }

        return true;
    }

    /// for dict iteration, iter over keys
    if(iterableObj.type == GeneralDataNode::DataType::TypeDict) {
        for(auto currKV : std::dynamic_pointer_cast<DataNodeDict>(iterableObj.data)->value) {
            /// generate a temp str node
            auto keyStrNode = std::make_shared<DataNodeStr>();
            keyStrNode->value = currKV.first;

            /// generate a temp str GDN
            GeneralDataNode keyStrGDN;
            keyStrGDN.type = GeneralDataNode::DataType::TypeString;
            keyStrGDN.data = keyStrNode;

            /// bind the iterator
            loopBody->lexScope->content[iteratorName] = keyStrGDN;

            /// execute the loop body
            auto permitContinue = loopBody->Execute(env);

            if(!permitContinue) return false;
        }

        return true;
    }

    /// if the expression is not list or dict, do as an var def in local scope
    loopBody->lexScope->content[iteratorName] = iterableObj;
    return loopBody->Execute(env);
}