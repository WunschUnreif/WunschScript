#pragma once

#include <string>

#include "AbstractLang.hpp"

namespace ws {

namespace td {

    struct TreeDiagram {

        std::shared_ptr<ws::asl::Program> prog;

        TreeDiagram(const std::string & code, const std::string & filename = "<input>");

        ws::asl::GeneralDataNode ExecuteAndExtract();
        
    };

}

}

void LoadSystemFunctions(std::shared_ptr<ws::asl::Scope> rootScope);
