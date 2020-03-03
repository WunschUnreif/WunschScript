#ifndef __WS_ASL_DATA_NODE_HPP__
#define __WS_ASL_DATA_NODE_HPP__

#include <string>
#include <deque>
#include <map>
#include <functional>
#include <memory>

#include <cstdint>

#include "DataNodeBase.hpp"
#include "Statement.hpp"

namespace ws {

namespace asl {

    struct StatementBase;
    struct Environment;

    /**
     * @brief Data node for `nil` type
     * Nothing is stored.
     */
    struct DataNodeNil final : public DataNodeBase {
        std::string ToString() override;
        bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) override;
        std::shared_ptr<DataNodeBase> DeepCopy() override;
    };

    /**
     * @brief Data node for `bool` type.
     */
    struct DataNodeBool final : public DataNodeBase {
        bool value;

        std::string ToString() override;
        bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) override;
        std::shared_ptr<DataNodeBase> DeepCopy() override;
    };

    /**
     * @brief Data node for `int` type.
     */
    struct DataNodeInt final : public DataNodeBase {
        int64_t value;

        std::string ToString() override;
        bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) override;
        std::shared_ptr<DataNodeBase> DeepCopy() override;
    };

    /**
     * @brief Data node for `float` type.
     */
    struct DataNodeFloat final : public DataNodeBase {
        double value;

        std::string ToString() override;
        bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) override;
        std::shared_ptr<DataNodeBase> DeepCopy() override;
    };

    /**
     * @brief Data node for `str` type.
     */
    struct DataNodeStr final : public DataNodeBase {
        std::string value;

        std::string ToString() override;
        bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) override;
        std::shared_ptr<DataNodeBase> DeepCopy() override;
    };

    /**
     * @brief Data node for `list` type.
     */
    struct DataNodeList final : public DataNodeBase {
        std::deque<GeneralDataNode> value;

        std::string ToString() override;
        bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) override;
        std::shared_ptr<DataNodeBase> DeepCopy() override;
    };

    /**
     * @brief Data node for `dict` type.
     */
    struct DataNodeDict final : public DataNodeBase {
        std::map<std::string, GeneralDataNode> value;

        std::string ToString() override;
        bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) override;
        std::shared_ptr<DataNodeBase> DeepCopy() override;
    };

    /**
     * @brief Data node for `func` type.
     */
    struct DataNodeFunc final : public DataNodeBase, public std::enable_shared_from_this<DataNodeFunc> {
        std::weak_ptr<DataNodeDict> thisDict;
        Scope paramScope;
        std::vector<std::string> paramNames;
        
        StatementBlock body;

        std::string ToString() override;
        bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) override;
        std::shared_ptr<DataNodeBase> DeepCopy() override;
    };

    /**
     * @brief Data node for system function access.
     * System functions are those functions provided by the
     * interpreter, such as `print()`, `read()`.
     */
    struct DataNodeSystemFunc final : public DataNodeBase {
        std::function<GeneralDataNode(std::vector<GeneralDataNode>, Environment &)> impl;

        std::string ToString() override;
        bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) override;
        std::shared_ptr<DataNodeBase> DeepCopy() override;
    };

}

}

#endif //__WS_ASL_DATA_NODE_HPP__
