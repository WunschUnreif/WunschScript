#include <exception>

#include "ExprMemberAccess.hpp"
#include "GeneralDataNodeFactory.hpp"

using namespace ws::asl;

GeneralDataNode ExpressionMemberAccess::Eval(Environment & env, bool asLval) {
    /// first evaluate the left hand expression
    auto lhsResult = lhs->Eval(env);

    /// the result should be a dict
    if(lhsResult.type != GeneralDataNode::DataType::TypeDict) {
        env.ReportError(std::runtime_error("Trying to access a member from non-dict value."));
        return GeneralDataNode();
    }

    if(!asLval) {
        auto dictNode = std::dynamic_pointer_cast<DataNodeDict>(lhsResult.data);
        auto it = dictNode->value.find(id);

        ///< the dict should contain the id if evaluated as rvalue
        if(it == dictNode->value.end()) {
            env.ReportError(std::runtime_error("Key does not exists for the required member access."));
            return GeneralDataNode();
        }

        /// bind `this` to function member and keep the current dict alive
        if(it->second.type == GeneralDataNode::DataType::TypeFunc) {
            std::dynamic_pointer_cast<DataNodeFunc>(it->second.data)->thisDict = dictNode;
            env.aliveDictStack.top().push_back(dictNode);
        }

        return it->second;
    } else {
        /// [DEPRECATED] branch shifted into function `SetValue`
        ///< as lval, do not care whether the key exists in the dict, if not, 
        ///< an empty GDN will be created for assignment.
        auto dictNode = std::dynamic_pointer_cast<DataNodeDict>(lhsResult.data);

        auto result = dictNode->value[id];

        /// bind `this` to function member
        if(result.type == GeneralDataNode::DataType::TypeFunc) {
            std::dynamic_pointer_cast<DataNodeFunc>(result.data)->thisDict = dictNode;
        }

        return result;
    }
}

void ExpressionMemberAccess::SetValue(Environment & env, GeneralDataNode target) {
    /// first evaluate the left hand expression
    auto lhsResult = lhs->Eval(env);

    /// the result should be a dict
    if(lhsResult.type != GeneralDataNode::DataType::TypeDict) {
        env.ReportError(std::runtime_error("Trying to access a member from non-dict value."));
        return;
    }

    /// get the dict storage
    auto dictNode = std::dynamic_pointer_cast<DataNodeDict>(lhsResult.data);

    /// set the value
    dictNode->value[id] = target;
}

int64_t ExpressionMemberAccess::GenByteCode(vm::ByteCodeBuilder & builder) {
    int64_t length = 0;

    length += lhs->GenByteCode(builder);

    builder.Append(vm::OpCode::ACCID, id);
    length += vm::OpCodeSize + vm::OpArgSize;

    return length;
}

int64_t ExpressionMemberAccess::GenByteCodeLval(vm::ByteCodeBuilder & builder) {
    int64_t length = 0;

    length += lhs->GenByteCode(builder);

    builder.Append(vm::OpCode::ACCIDL, id);
    length += vm::OpCodeSize + vm::OpArgSize;

    return length;
}



GeneralDataNode ExpressionMemberAccessCalaulated::Eval(Environment & env, bool asLval) {
    /// first evaluated the left hand expression
    auto lhsResult = lhs->Eval(env);

    /// 1. in case lhs is dict
    if(lhsResult.type == GeneralDataNode::DataType::TypeDict) {
        /// evaluated the right hand expression (inside the '[]')
        auto rhsResult = rhs->Eval(env);

        /// the result should be a str 
        if(rhsResult.type != GeneralDataNode::DataType::TypeString) {
            env.ReportError(std::runtime_error("Trying to access a member using non-str key."));
            return GeneralDataNode();
        }

        std::string id = std::dynamic_pointer_cast<DataNodeStr>(rhsResult.data)->value;

        /// retrive the reqiured data from dict
        if(!asLval) {
            ///< the dict should contain the id if evaluated as rvalue
            auto dictNode = std::dynamic_pointer_cast<DataNodeDict>(lhsResult.data);
            auto it = dictNode->value.find(id);

            if(it == dictNode->value.end()) {
                env.ReportError(std::runtime_error("Key does not exists for the required member access."));
                return GeneralDataNode();
            }

            /// bind `this` to function member and keep the current dict alive
            if(it->second.type == GeneralDataNode::DataType::TypeFunc) {
                std::dynamic_pointer_cast<DataNodeFunc>(it->second.data)->thisDict = dictNode;
                env.aliveDictStack.top().push_back(dictNode);
            }

            return it->second;
        } else {
            ///< as lval, do not care whether the key exists in the dict, if not, 
            ///< an empty GDN will be created for assignment.
            auto dictNode = std::dynamic_pointer_cast<DataNodeDict>(lhsResult.data);

            return dictNode->value[id];
        }
    }

    /// 2. in case lhs is list
    if(lhsResult.type == GeneralDataNode::DataType::TypeList) {
        /// evaluated the right hand expression (inside the '[]')
        auto rhsResult = rhs->Eval(env);

        /// the result should be a int 
        if(rhsResult.type != GeneralDataNode::DataType::TypeInt) {
            env.ReportError(std::runtime_error("Trying to access a member using non-int index."));
            return GeneralDataNode();
        }

        /// get the indexed data from list
        auto listNode = std::dynamic_pointer_cast<DataNodeList>(lhsResult.data);
        auto index = std::dynamic_pointer_cast<DataNodeInt>(rhsResult.data)->value;

        if(asLval) {
            /// reserve enough space if accessing out-of-range index, using nil to fill
            while(index >= listNode->value.size()) {
                /// generate a nil node to fill
                GeneralDataNode filling;
                filling.type = GeneralDataNode::DataType::TypeNil;
                filling.data = std::make_shared<DataNodeNil>();

                listNode->value.push_back(filling);
            }

            return listNode->value[index];
        } else {
            if(index >= listNode->value.size()) {
                env.ReportError(std::runtime_error("Index out of range."));
                return GeneralDataNode();
            }

            return listNode->value[index];
        }
    }

    /// 3. in case lhs is str
    if(lhsResult.type == GeneralDataNode::DataType::TypeString) {
        /// evaluated the right hand expression (inside the '[]')
        auto rhsResult = rhs->Eval(env);

        /// the result should be a int 
        if(rhsResult.type != GeneralDataNode::DataType::TypeInt) {
            env.ReportError(std::runtime_error("Trying to access a member using non-int index."));
            return GeneralDataNode();
        }

        /// get the indexed data from list
        auto & strdata = std::dynamic_pointer_cast<DataNodeStr>(lhsResult.data)->value;
        auto index = std::dynamic_pointer_cast<DataNodeInt>(rhsResult.data)->value;

        if(asLval) {
            /// cannot eval str[index] as lval
            env.ReportError(std::runtime_error("Cannot evaluate `[...]` on str as left value."));
            return GeneralDataNode();
        } else {
            if(index >= strdata.length()) {
                env.ReportError(std::runtime_error("Index out of range."));
                return GeneralDataNode();
            }

            /// generate a string GDN for result
            auto result = GeneralDataNodeFactory::MakeStrGDN(strdata.substr(index, 1));
            return result;
        }
    }

    /// 4. otherwise, error
    env.ReportError(std::runtime_error("Cannor access member from non-dict/list value"));
    return GeneralDataNode();
}

void ExpressionMemberAccessCalaulated::SetValue(Environment & env, GeneralDataNode target) {
    /// first evaluated the left hand expression
    auto lhsResult = lhs->Eval(env);

    /// 1. in case lhs is dict
    if(lhsResult.type == GeneralDataNode::DataType::TypeDict) {
        /// evaluated the right hand expression (inside the '[]')
        auto rhsResult = rhs->Eval(env);

        /// the result should be a str 
        if(rhsResult.type != GeneralDataNode::DataType::TypeString) {
            env.ReportError(std::runtime_error("Trying to access a member using non-str key."));
            return;
        }

        std::string id = std::dynamic_pointer_cast<DataNodeStr>(rhsResult.data)->value;

        /// get the dict storage
        auto dictNode = std::dynamic_pointer_cast<DataNodeDict>(lhsResult.data);

        /// set the value
        dictNode->value[id] = target;

        return;
    }

    /// 2. in case lhs is list
    if(lhsResult.type == GeneralDataNode::DataType::TypeList) {
        /// evaluated the right hand expression (inside the '[]')
        auto rhsResult = rhs->Eval(env);

        /// the result should be a int 
        if(rhsResult.type != GeneralDataNode::DataType::TypeInt) {
            env.ReportError(std::runtime_error("Trying to access a member using non-int index."));
            return;
        }

        /// get the indexed data from list
        auto listNode = std::dynamic_pointer_cast<DataNodeList>(lhsResult.data);
        auto index = std::dynamic_pointer_cast<DataNodeInt>(rhsResult.data)->value;

        /// reserve enough space if accessing out-of-range index, using nil to fill
        while(index >= listNode->value.size()) {
            /// generate a nil node to fill
            GeneralDataNode filling;
            filling.type = GeneralDataNode::DataType::TypeNil;
            filling.data = std::make_shared<DataNodeNil>();

            listNode->value.push_back(filling);
        }

        /// set the valur
        listNode->value[index] = target;

        return;
    }

    /// 3. otherwise, error
    env.ReportError(std::runtime_error("Cannor access member from non-dict/list value"));
    return;
}

int64_t ExpressionMemberAccessCalaulated::GenByteCode(vm::ByteCodeBuilder & builder) {
    int64_t length = 0;

    length += lhs->GenByteCode(builder);
    length += rhs->GenByteCode(builder);

    builder.Append(vm::OpCode::ACCESS);
    length += vm::OpCodeSize;

    return length;
}

int64_t ExpressionMemberAccessCalaulated::GenByteCodeLval(vm::ByteCodeBuilder & builder) {
    int64_t length = 0;

    length += lhs->GenByteCode(builder);
    length += rhs->GenByteCode(builder);

    builder.Append(vm::OpCode::ACCESSL);
    length += vm::OpCodeSize;

    return length;
}
