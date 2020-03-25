#ifndef __WS_ASL_DATA_NODE_HPP__
#define __WS_ASL_DATA_NODE_HPP__

#include <string>
#include <deque>
#include <map>
#include <functional>
#include <memory>

#include <cstdint>

#include "DataRepresentation/DataNodeBase.hpp"
#include "Statement/Statement.hpp"

namespace ws {

namespace asl {

    struct StatementBase;
    struct StatementBlock;
    struct Environment;
    struct ExpressionBase;

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
        std::deque<std::shared_ptr<ExpressionBase>> generator;
        std::deque<GeneralDataNode> value;

        std::string ToString() override;
        bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) override;
        std::shared_ptr<DataNodeBase> DeepCopy() override;
    };

    /**
     * @brief Data node for `dict` type.
     */
    struct DataNodeDict final : public DataNodeBase {
        std::map<std::string, std::shared_ptr<ExpressionBase>> generator;
        std::map<std::string, GeneralDataNode> value;

        std::string ToString() override;
        bool IsEqualTo(std::shared_ptr<DataNodeBase> rhs) override;
        std::shared_ptr<DataNodeBase> DeepCopy() override;
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
        
        std::shared_ptr<StatementBlock> body;       // function body

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

        DataNodeSystemFunc() {}

        explicit DataNodeSystemFunc(
            std::function<GeneralDataNode(std::vector<GeneralDataNode>, Environment &)> impl
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

#endif //__WS_ASL_DATA_NODE_HPP__
