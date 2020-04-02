#pragma once

#include <string>
#include <deque>
#include <map>
#include <vector>
#include <functional>
#include <memory>

#include <cstdint>

#include "DataNodeBase.hpp"
#include "GeneralDataNode.hpp"

namespace ws {

namespace vm {

    struct Machine;

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

        explicit DataNodeBool(bool value = false) : value(value) {}

        std::string ToString() override;
        bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) override;
        std::shared_ptr<DataNodeBase> DeepCopy() override;
    };

    /**
     * @brief Data node for `int` type.
     */
    struct DataNodeInt final : public DataNodeBase {
        int64_t value;

        explicit DataNodeInt(int64_t value = 0) : value(value) {}

        std::string ToString() override;
        bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) override;
        std::shared_ptr<DataNodeBase> DeepCopy() override;
    };

    /**
     * @brief Data node for `float` type.
     */
    struct DataNodeFloat final : public DataNodeBase {
        double value;

        explicit DataNodeFloat(double value = 0) : value(value) {}

        std::string ToString() override;
        bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) override;
        std::shared_ptr<DataNodeBase> DeepCopy() override;
    };

    /**
     * @brief Data node for `str` type.
     */
    struct DataNodeStr final : public DataNodeBase {
        std::string value;

        explicit DataNodeStr(const std::string & value = "") : value(value) {}

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

    private:
        bool underTraverse = false;
    };

    /**
     * @brief Data node for `dict` type.
     */
    struct DataNodeDict final : public DataNodeBase {
        std::map<std::string, GeneralDataNode> value;

        std::string ToString() override;
        bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) override;
        std::shared_ptr<DataNodeBase> DeepCopy() override;

    private:
        bool underTraverse = false;
    };

    /**
     * @brief Data node for `func` type.
     */
    struct DataNodeFunc final : public DataNodeBase {
        std::weak_ptr<DataNodeDict> thisDict;       // the owner dict object of this function

        std::vector<std::string> paramNames;        // parameter name list

        bool withArrTail = false;                   // whether this function contains array-tailed parameter
        std::string arrName;                        // the name of tail array

        std::vector<std::string> captureIDs;        // the list of ID this function wants to capture
        std::vector<GeneralDataNode> captureVals;   // captured values
        
        size_t executorID;                          // which executor it belongs to
        size_t startOffset;                         // the offset in bytecode file

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
        std::function<GeneralDataNode(std::vector<GeneralDataNode>, Machine &)> impl;

        DataNodeSystemFunc() {}

        explicit DataNodeSystemFunc(
            std::function<GeneralDataNode(std::vector<GeneralDataNode>, Machine &)> impl
        ) : impl(impl) {}

        std::string ToString() override;
        bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) override;
        std::shared_ptr<DataNodeBase> DeepCopy() override;
    };

    /**
     * @brief Data node for weak reference node.
     */
    struct DataNodeWeakReference final : public DataNodeBase {
        std::weak_ptr<DataNodeBase> ptr;
        GeneralDataNode::DataType type;

        std::string ToString() override;
        bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) override;
        std::shared_ptr<DataNodeBase> DeepCopy() override;
    };

}

}
