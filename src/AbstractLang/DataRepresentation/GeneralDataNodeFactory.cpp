#include <memory>

#include "GeneralDataNodeFactory.hpp"

using namespace ws::asl;

GeneralDataNode GeneralDataNodeFactory::MakeNilGDN() {
    GeneralDataNode result;
    result.type = GeneralDataNode::TypeNil;
    result.data = std::make_shared<DataNodeNil>();

    return result;
}

GeneralDataNode GeneralDataNodeFactory::MakeBoolGDN(bool val) {
    GeneralDataNode result;
    result.type = GeneralDataNode::TypeBool;
    result.data = std::make_shared<DataNodeBool>();
    std::dynamic_pointer_cast<DataNodeBool>(result.data)->value = val;

    return result;
}

GeneralDataNode GeneralDataNodeFactory::MakeIntGDN(int64_t val) {
    GeneralDataNode result;
    result.type = GeneralDataNode::TypeInt;
    result.data = std::make_shared<DataNodeInt>();
    std::dynamic_pointer_cast<DataNodeInt>(result.data)->value = val;

    return result;
}

GeneralDataNode GeneralDataNodeFactory::MakeStrGDN(const std::string & val) {
    GeneralDataNode result;
    result.type = GeneralDataNode::TypeString;
    result.data = std::make_shared<DataNodeStr>();
    std::dynamic_pointer_cast<DataNodeStr>(result.data)->value = val;

    return result;
}

GeneralDataNode GeneralDataNodeFactory::PackSystemFunc(
    std::function<GeneralDataNode(std::vector<GeneralDataNode>, Environment &)> val
) {
    GeneralDataNode result;
    result.type = GeneralDataNode::TypeSystemFunc;
    result.data = std::make_shared<DataNodeSystemFunc>();
    std::dynamic_pointer_cast<DataNodeSystemFunc>(result.data)->impl = val;

    return result;
}
