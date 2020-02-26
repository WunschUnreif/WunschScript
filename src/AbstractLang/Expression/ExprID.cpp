#include <exception>

#include "ExprID.hpp"

using namespace ws::asl;

GeneralDataNode ExpressionID::Eval(Environment & env, bool asLval) {
    GeneralDataNode node = env.GetDataNode(identifier);

    /// in case the identifier is not found in the scope
    if(node.data == nullptr) {
        env.ReportError(std::runtime_error("Identifier " + identifier + " is not defined in the current scope."));
        return GeneralDataNode();
    }

    return node;
}
