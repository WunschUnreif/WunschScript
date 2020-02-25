#pragma once 

#ifndef __WS_ASL_DATA_NODE_HPP__
#define __WS_ASL_DATA_NODE_HPP__

#include <string>
#include <deque>
#include <map>

#include <cstdint>

#include "DataNodeBase.hpp"

namespace ws {

namespace asl {

    /**
     * @brief Data node for `nil` type
     * Nothing is stored.
     */
    struct DataNodeNil final : public DataNodeBase {};

    /**
     * @brief Data node for `bool` type.
     */
    struct DataNodeBool final : public DataNodeBase {
        bool value;
    };

    /**
     * @brief Data node for `int` type.
     */
    struct DataNodeInt final : public DataNodeBase {
        int64_t value;
    };

    /**
     * @brief Data node for `float` type.
     */
    struct DataNodeFloat final : public DataNodeBase {
        double value;
    };

    /**
     * @brief Data node for `str` type.
     */
    struct DataNodeStr final : public DataNodeBase {
        std::string value;
    };

    /**
     * @brief Data node for `list` type.
     */
    struct DataNodeList final : public DataNodeBase {
        std::deque<std::shared_ptr<DataNodeBase>> value;
    };

    /**
     * @brief Data node for `dict` type.
     */
    struct DataNodeDict final : public DataNodeBase {
        std::map<std::string, std::shared_ptr<DataNodeBase>> value;
    };

}

}

#endif //__WS_ASL_DATA_NODE_HPP__
