#include "Console.hpp"

using namespace ws::asl;
using namespace ws::sup;

GeneralDataNode ws::sup::PrintImpl(std::vector<GeneralDataNode> params, Environment & env) {
    for(auto gdn : params) {
        std::cout << gdn.data->ToString();
    }

    std::cout << std::endl;

    return GeneralDataNodeFactory::MakeNilGDN();
}

GeneralDataNode ws::sup::ReadImpl(std::vector<GeneralDataNode> params, Environment & env) {
    // print prompt
    if(!params.empty()) {
        std::cout << params[0].data->ToString();
        std::flush(std::cout);
    }

    // read a string
    std::string str;
    std::cin >> str;

    // construct return val
    auto strGDN = GeneralDataNodeFactory::MakeStrGDN(str);

    return strGDN;
}

GeneralDataNode ws::sup::ReadLineImpl(std::vector<GeneralDataNode> params, Environment & env) {
    // print prompt
    if(!params.empty()) {
        std::cout << params[0].data->ToString();
        std::flush(std::cout);
    }

    // read whole line
    std::string str;
    std::getline(std::cin, str);

    // construct return val
    auto strGDN = GeneralDataNodeFactory::MakeStrGDN(str);

    return strGDN;
}
