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
        /// for dict literal, the values should be eval dynamically
        std::dynamic_pointer_cast<DataNodeList>(value.data)->value.clear();
        
        for(auto gen : std::dynamic_pointer_cast<DataNodeList>(value.data)->generator) {
            std::dynamic_pointer_cast<DataNodeList>(value.data)->value.push_back(gen->Eval(env));
        }

        return value.DeepCopy();
    } else {
        return value.DeepCopy();
    }
}
