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

#pragma once

#ifndef __WS_ASL_STATEMENT_H__
#define __WS_ASL_STATEMENT_H__

namespace ws {

namespace asl {

    struct Environment;

    /**
     * @brief Abstract class for statement node.
     * 
     */
    struct StatementBase {
        
        virtual ~StatementBase() = 0;

        enum StatementType {
            StatementExpression,
            StatementVariableDefinition,
            StatementAssignment,
            StatementConditional,
            StatementWhileLoop, 
            StatementForLoop,
            StatementReturn
        } type;

        virtual void execute(const Environment & env) = 0;
    };

} // namespace al

} // namespace ws

#endif // __WS_ASL_STATEMENT_H__
