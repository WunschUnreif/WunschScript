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

    /**
     * @brief Abstract class for statement node.
     * 
     */
    struct StatementBase {
        
        virtual ~StatementBase() = 0;

        std::string filename;
        size_t line;
        size_t character;
        std::string contentString;

        virtual void Execute(Environment & env) = 0;
    };


    struct StatementBlock {
        std::shared_ptr<Scope> lexScope;
        std::vector<std::shared_ptr<StatementBase>> body;
    };

} // namespace al

} // namespace ws

#endif // __WS_ASL_STATEMENT_H__
