/**
 * @file GeneralDataNode.hpp
 * @author WunschUnreif (wunschunreif@sjtu.edu.cn)
 * @brief General node for data storage of any type.
 * @version 0.1
 * @date 2020-02-25
 * 
 * @copyright Copyright (c) 2020
 * 
 */

#pragma once 

#ifndef __WS_ASL_GENERAL_DATA_NODE_HPP__
#define __WS_ASL_GENERAL_DATA_NODE_HPP__

#include <memory>

#include "DataNodeBase.hpp"

namespace ws {

namespace asl {

    /**
     * @brief A linkage to any type of data.
     * 
     */
    struct GeneralDataNode {

        enum DataType {
            TypeNil, 
            TypeBool,
            TypeInt, 
            TypeFloat,
            TypeString,
            TypeList,
            TypeDict,
            TypeFunc
        } type;

        std::shared_ptr<DataNodeBase> data;
    };

} // namespace asl

} // namespace ws

#endif // !__WS_ASL_GENERAL_DATA_NODE_HPP__
