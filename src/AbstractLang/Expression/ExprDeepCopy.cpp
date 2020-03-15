#include "ExprDeepCopy.hpp"

using namespace ws::asl;

GeneralDataNode ExpressionDeepCopy::Eval(Environment & env, bool asLval) {
    /// can only be right value 
    if(asLval) {
        env.ReportError(std::runtime_error("Deepcopy cannot serve as left value."));
        return GeneralDataNode();
    }

    /// evaluate and then copy. 
    auto copy = ref->Eval(env);
    return copy.DeepCopy();
}

GeneralDataNode ExpressionDeepCopyModify::Eval(Environment & env, bool asLval) {
    /// can only be right value 
    if(asLval) {
        env.ReportError(std::runtime_error("Deepcopy with modifying cannot serve as left value."));
        return GeneralDataNode();
    }

    auto copy = ref->Eval(env);

    /// modification can only apply for dict
    if(copy.type != GeneralDataNode::DataType::TypeDict) {
        env.ReportError(std::runtime_error("Deepcopy with modifying can only apply to dict."));
        return GeneralDataNode();
    }

    copy = copy.DeepCopy();

    /// apply the modifications
    auto dictNode = std::dynamic_pointer_cast<DataNodeDict>(copy.data);
    for(size_t i = 0; i < keyToMod.size(); ++i) {
        dictNode->value[keyToMod[i]] = valToMod[i]->Eval(env);
    }

    return copy;
}
