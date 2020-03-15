#pragma once 

#include <string>
#include <map>
#include <vector>
#include <functional>

#include "GeneralDataNode.hpp"
#include "DataNode.hpp"

namespace ws {

namespace asl {

    struct Environment;

    struct GeneralDataNodeFactory {

        static GeneralDataNode MakeNilGDN();
        static GeneralDataNode MakeBoolGDN(bool val);
        static GeneralDataNode MakeIntGDN(int64_t val);
        static GeneralDataNode MakeFloatGDN(double val);
        static GeneralDataNode MakeStrGDN(const std::string & val);

        // static GeneralDataNode MakeListGDN(const std::vector<GeneralDataNode> & val);
        // static GeneralDataNode MakeDictGDN(const std::map<std::string, GeneralDataNode> & val);

        static GeneralDataNode PackSystemFunc(
            std::function<GeneralDataNode(std::vector<GeneralDataNode>, Environment &)> val);

    };

}

}
