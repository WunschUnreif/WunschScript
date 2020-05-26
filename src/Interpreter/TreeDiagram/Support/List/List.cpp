#include "List.hpp"
#include <exception>

using namespace ws;

asl::GeneralDataNode sup::LenImpl(std::vector<asl::GeneralDataNode> params, asl::Environment & env) {
    if(params.size() != 1) {
        env.ReportError(std::runtime_error("System func 'len' takes exactly 1 argument."));
        return asl::GeneralDataNodeFactory::MakeNilGDN();
    }

    if(params[0].type == asl::GeneralDataNode::DataType::TypeList) {
        return asl::GeneralDataNodeFactory::MakeIntGDN(std::dynamic_pointer_cast<asl::DataNodeList>(params[0].data)->value.size());
    }

    if(params[0].type == asl::GeneralDataNode::DataType::TypeDict) {
        return asl::GeneralDataNodeFactory::MakeIntGDN(std::dynamic_pointer_cast<asl::DataNodeDict>(params[0].data)->value.size());
    }

    env.ReportError(std::runtime_error("System func 'len' takes only dict and list object."));
    return asl::GeneralDataNodeFactory::MakeNilGDN();
}

asl::GeneralDataNode GenRangeList(int64_t end, int64_t start = 0, int64_t step = 1) {
    auto listNode = std::make_shared<asl::DataNodeList>();
    for(auto i = start; i < end; i += step) {
        listNode->value.push_back(asl::GeneralDataNodeFactory::MakeIntGDN(i));
    }
    
    auto listGDN = asl::GeneralDataNode();
    listGDN.type = asl::GeneralDataNode::TypeList;
    listGDN.data = listNode;

    return listGDN;
}

asl::GeneralDataNode GenFloatRangeList(double end, double start = 0.0, double step = 1.0) {
    auto listNode = std::make_shared<asl::DataNodeList>();
    for(auto i = start; i < end; i += step) {
        listNode->value.push_back(asl::GeneralDataNodeFactory::MakeFloatGDN(i));
    }
    
    auto listGDN = asl::GeneralDataNode();
    listGDN.type = asl::GeneralDataNode::TypeList;
    listGDN.data = listNode;

    return listGDN;
}

asl::GeneralDataNode sup::RangeImpl(std::vector<asl::GeneralDataNode> params, asl::Environment & env) {
    if(params.size() == 1) {
        if(params[0].type != asl::GeneralDataNode::TypeInt) {
            env.ReportError(std::runtime_error("System func 'range' only takes int as argument."));
            return asl::GeneralDataNodeFactory::MakeNilGDN();
        }
        return GenRangeList(std::dynamic_pointer_cast<asl::DataNodeInt>(params[0].data)->value);
    }

    if(params.size() == 2) {
        if(     params[0].type != asl::GeneralDataNode::TypeInt ||
                params[1].type != asl::GeneralDataNode::TypeInt) {
            env.ReportError(std::runtime_error("System func 'range' only takes int as argument."));
            return asl::GeneralDataNodeFactory::MakeNilGDN();
        }
        return GenRangeList(std::dynamic_pointer_cast<asl::DataNodeInt>(params[1].data)->value, 
                            std::dynamic_pointer_cast<asl::DataNodeInt>(params[0].data)->value);
    }

    if(params.size() == 3) {
        if(     params[0].type != asl::GeneralDataNode::TypeInt ||
                params[1].type != asl::GeneralDataNode::TypeInt ||
                params[2].type != asl::GeneralDataNode::TypeInt) {
            env.ReportError(std::runtime_error("System func 'range' only takes int as argument."));
            return asl::GeneralDataNodeFactory::MakeNilGDN();
        }
        return GenRangeList(std::dynamic_pointer_cast<asl::DataNodeInt>(params[1].data)->value, 
                            std::dynamic_pointer_cast<asl::DataNodeInt>(params[0].data)->value,
                            std::dynamic_pointer_cast<asl::DataNodeInt>(params[2].data)->value);
    }

    env.ReportError(std::runtime_error("System func 'range' takes at most 3 arguments."));
    return asl::GeneralDataNodeFactory::MakeNilGDN();
}

asl::GeneralDataNode sup::FRangeImpl(std::vector<asl::GeneralDataNode> params, asl::Environment & env) {
    if(params.size() == 1) {
        if(params[0].type != asl::GeneralDataNode::TypeFloat) {
            env.ReportError(std::runtime_error("System func 'frange' only takes float as argument."));
            return asl::GeneralDataNodeFactory::MakeNilGDN();
        }
        return GenFloatRangeList(std::dynamic_pointer_cast<asl::DataNodeFloat>(params[0].data)->value);
    }

    if(params.size() == 2) {
        if(     params[0].type != asl::GeneralDataNode::TypeFloat ||
                params[1].type != asl::GeneralDataNode::TypeFloat) {
            env.ReportError(std::runtime_error("System func 'frange' only takes float as argument."));
            return asl::GeneralDataNodeFactory::MakeNilGDN();
        }
        return GenFloatRangeList(std::dynamic_pointer_cast<asl::DataNodeFloat>(params[1].data)->value, 
                            std::dynamic_pointer_cast<asl::DataNodeFloat>(params[0].data)->value);
    }

    if(params.size() == 3) {
        if(     params[0].type != asl::GeneralDataNode::TypeFloat ||
                params[1].type != asl::GeneralDataNode::TypeFloat ||
                params[2].type != asl::GeneralDataNode::TypeFloat) {
            env.ReportError(std::runtime_error("System func 'frange' only takes float as argument."));
            return asl::GeneralDataNodeFactory::MakeNilGDN();
        }
        return GenFloatRangeList(std::dynamic_pointer_cast<asl::DataNodeFloat>(params[1].data)->value, 
                            std::dynamic_pointer_cast<asl::DataNodeFloat>(params[0].data)->value,
                            std::dynamic_pointer_cast<asl::DataNodeFloat>(params[2].data)->value);
    }

    env.ReportError(std::runtime_error("System func 'frange' takes at most 3 arguments."));
    return asl::GeneralDataNodeFactory::MakeNilGDN();
}
