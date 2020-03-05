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

    struct ExecutionInformation;

    struct Environment {
        /// Lexical scope of program.
        std::shared_ptr<Scope> currentScope;

        /// Parameter stack for recursive function call.
        std::stack<Scope> paramStack;

        /// Stack for 'this' in function call
        std::stack<std::weak_ptr<DataNodeDict>> thisStack;

        /// Stack for storing return values
        std::stack<GeneralDataNode> returnStack;

        /// Stack for execution information
        std::stack<std::weak_ptr<ExecutionInformation>> infoStack;

        GeneralDataNode GetDataNode(const std::string & name);
        bool SetDataNode(const std::string & name, GeneralDataNode target);

        void ReportError(const std::runtime_error & error);

    protected:
        std::string GetInfoStackString();
    };

}

}

#endif // !__WS_ASL_ENVIRONMENT_HPP__

