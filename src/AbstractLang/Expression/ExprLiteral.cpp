#include <exception>

#include "ExprLiteral.hpp"

using namespace ws::asl;

GeneralDataNode ExpressionLiteral::Eval(Environment & env, bool asLval) {
    if(asLval) {
        env.ReportError(std::runtime_error("Literal cannot be evaluated as left value."));
        return GeneralDataNode();
    }
    return value;
}
