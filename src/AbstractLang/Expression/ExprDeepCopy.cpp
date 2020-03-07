#include "ExprDeepCopy.hpp"

using namespace ws::asl;

GeneralDataNode ExpressionDeepCopy::Eval(Environment & env, bool asLval) {
    /// can only be right value 
    if(asLval) {
        env.ReportError(std::runtime_error("Deepcopy cannot serve as left value."));
        return GeneralDataNode();
    }

    /// evaluate and then copy. 
    /// TODO: optimize for non ID-expr situations.
    auto copy = ref->Eval(env);
    return copy.DeepCopy();
}