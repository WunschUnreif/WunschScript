#ifndef __WS_ASL_DATA_NODE_HPP__
#define __WS_ASL_DATA_NODE_HPP__

#include <string>
#include <deque>
#include <map>
#include <functional>

#include <cstdint>

#include "DataNodeBase.hpp"
#include "Statement.hpp"

namespace ws {

namespace asl {

    struct StatementBase;

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
        std::deque<GeneralDataNode> value;
    };

    /**
     * @brief Data node for `dict` type.
     */
    struct DataNodeDict final : public DataNodeBase {
        std::map<std::string, GeneralDataNode> value;
    };

    /**
     * @brief Data node for `func` type.
     */
    struct DataNodeFunc final : public DataNodeBase {
        Scope paramScope;
        std::vector<std::shared_ptr<StatementBase>> body;
    };

    /**
     * @brief Data node for system function access.
     * System functions are those functions provided by the
     * interpreter, such as `print()`, `read()`.
     */
    struct DataNodeSystemFunc final : public DataNodeBase {
        std::function<GeneralDataNode(std::vector<GeneralDataNode>)> impl;
    };

}

}

#endif //__WS_ASL_DATA_NODE_HPP__
