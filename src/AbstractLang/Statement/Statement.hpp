/**
 * @file Statement.hpp
 * @author WunschUnreif (wunschunreif@sjtu.edu.cn)
 * @brief Abstraction for statement node.
 * @version 0.0.1
 * @date 2020-02-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#ifndef __WS_ASL_STATEMENT_H__
#define __WS_ASL_STATEMENT_H__

#include <string>
#include <memory>

#include "Environment.hpp"
#include "Scope.hpp"

namespace ws {

namespace asl {

    struct Environment;
    struct Scope;

    struct ExecutionInformation  {
        std::string file;
        size_t line;
        size_t character;
        std::string content;
    };

    /**
     * @brief Abstract class for statement node.
     * 
     */
    struct StatementBase {
        
        virtual ~StatementBase() {};

        std::shared_ptr<ExecutionInformation> info = std::make_shared<ExecutionInformation>();

        /// with wrappers for execution information
        virtual bool Execute(Environment & env);

        virtual bool InnerExecute(Environment & env) = 0;
    };


    struct StatementBlock {
        std::shared_ptr<Scope> lexScope;
        std::vector<std::shared_ptr<StatementBase>> body;

        bool Execute(Environment & env);
    };

} // namespace al

} // namespace ws

#endif // __WS_ASL_STATEMENT_H__
