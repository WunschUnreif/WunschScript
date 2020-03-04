#include <exception>

#include "ExprLiteral.hpp"

using namespace ws::asl;

GeneralDataNode ExpressionLiteral::Eval(Environment & env, bool asLval) {
    if(asLval) {
        env.ReportError(std::runtime_error("Literal cannot be evaluated as left value."));
        return GeneralDataNode();
    }

    /// a literal is immutable, so deep copy is needed
    if(value.type != GeneralDataNode::DataType::TypeDict) {
        return value.DeepCopy();
    } else {
        /// for dict literal, the values should be eval dynamically
        for(auto kv : std::dynamic_pointer_cast<DataNodeDict>(value.data)->generator) {
            std::dynamic_pointer_cast<DataNodeDict>(value.data)->value[kv.first] = kv.second->Eval(env);
        }

        return value.DeepCopy();
    }
}
