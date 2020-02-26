#include <exception>

#include "ExprMemberAccess.hpp"

using namespace ws::asl;

GeneralDataNode ExpressionMemberAccess::Eval(Environment & env, bool asLval) {
    /// first evaluate the left hand expression
    auto lhsResult = lhs->Eval(env);

    /// the result should be a dict
    if(lhsResult.type != GeneralDataNode::DataType::TypeDict) {
        env.ReportError(std::runtime_error("Trying to access a member from non-dict value."));
        return GeneralDataNode();
    }

    if(!asLval) {
        /// the dict should contain the id if evaluated as rvalue
        auto dict = std::dynamic_pointer_cast<DataNodeDict>(lhsResult.data);
        auto it = dict->value.find(id);

        if(it == dict->value.end()) {
            env.ReportError(std::runtime_error("Key does not exists for the required member access."));
            return GeneralDataNode();
        }

        return it->second;
    } else {
        /// as lval, do not care whether the key exists in the dict, if not, 
        /// an empty GDN will be created for assignment.
        auto dict = std::dynamic_pointer_cast<DataNodeDict>(lhsResult.data);

        return dict->value[id];
    }
}
