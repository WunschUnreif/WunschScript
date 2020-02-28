#ifndef __WS_ASL_ENVIRONMENT_HPP__
#define __WS_ASL_ENVIRONMENT_HPP__

#include <stack>
#include <exception>

#include "Scope.hpp"
#include "DataNode.hpp"
#include "GeneralDataNode.hpp"

namespace ws {

namespace asl {

    struct DataNodeDict;

    struct Environment {
        /// Lexical scope of program.
        std::shared_ptr<Scope> currentScope;

        /// Parameter stack for recursive function call.
        std::stack<Scope> paramStack;

        /// Stack for 'this' in function call
        std::stack<std::weak_ptr<DataNodeDict>> thisStack;

        GeneralDataNode GetDataNode(const std::string & name);

        void ReportError(const std::runtime_error & error);
    };

}

}

#endif // !__WS_ASL_ENVIRONMENT_HPP__

