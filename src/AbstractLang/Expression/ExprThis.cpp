#include <exception>

#include "ExprThis.hpp"

using namespace ws::asl;

GeneralDataNode ExpressionThis::Eval(Environment & env, bool asLval) {
    if(asLval) {
        env.ReportError(std::runtime_error("`this` cannot be evaluated as left value."));
        return GeneralDataNode();
    }

    auto result = env.GetThisDict();

    if(result.type == GeneralDataNode::DataType::TypeUndefined) {
        env.ReportError(std::runtime_error("`this` isn't available in the context."));
        return GeneralDataNode();
    }

    return result;
}
