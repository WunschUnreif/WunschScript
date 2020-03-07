#ifndef __WS_ASL_SCOPE_HPP__
#define __WS_ASL_SCOPE_HPP__

#include <memory>
#include <map>
#include <vector>

#include "GeneralDataNode.hpp"

namespace ws {

namespace asl {

    struct Scope {
        std::weak_ptr<Scope> parent;
        std::map<std::string, GeneralDataNode> content;
        std::vector<std::shared_ptr<Scope>> children;

        /// whether the search can go to its parent node.
        /// this is set to false for every file's root scope.
        /// useful when importing another script in the 
        /// current script to preventing unexpected scope overlap.
        bool enableTraceup = true;
    };

}

}

#endif // !__WS_ASL_SCOPE_HPP__
/**
 * 
*/