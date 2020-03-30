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

void ExpressionID::SetValue(Environment & env, GeneralDataNode target) {
    auto success = env.SetDataNode(identifier, target);

    /// in case the identifier is not found in the scope
    if(!success) {
        env.ReportError(std::runtime_error("Identifier " + identifier + " is not defined in the current scope."));
    }
}

int64_t ExpressionID::GenByteCode(vm::ByteCodeBuilder & builder) {
    builder.Append(vm::OpCode::GET, identifier);
    return vm::OpCodeSize + sizeof(int64_t);
}

int64_t ExpressionID::GenByteCodeLval(vm::ByteCodeBuilder & builder) {
    builder.Append(vm::OpCode::GETL, identifier);
    return vm::OpCodeSize + sizeof(int64_t);
}
