#include <cassert>

#include "DataNode.hpp"

using namespace ws::asl;

/* ---------------- Implementation for type nil ---------------- */

std::string DataNodeNil::ToString() {
    return "";
}

bool DataNodeNil::IsEqualTo(std::shared_ptr<DataNodeBase> rhs) {
    assert(typeid(*this) == typeid(*rhs));

    /// nil is always equal to nil.
    return true;
}

std::shared_ptr<DataNodeBase> DataNodeNil::DeepCopy() {
    return std::make_shared<DataNodeNil>();
}

/* ---------------- Implementation for type nil ---------------- */

/* ---------------- Implementation for type bool ---------------- */

std::string DataNodeBool::ToString() {
    return value ? "true" : "false";
}

bool DataNodeBool::IsEqualTo(std::shared_ptr<DataNodeBase> rhs) {
    assert(typeid(*this) == typeid(*rhs));

    return value == std::dynamic_pointer_cast<DataNodeBool>(rhs)->value;
}

std::shared_ptr<DataNodeBase> DataNodeBool::DeepCopy() {
    auto result = std::make_shared<DataNodeBool>();
    result->value = value;

    return result;
}

/* ---------------- Implementation for type bool ---------------- */

/* ---------------- Implementation for type int ---------------- */

std::string DataNodeInt::ToString() {
    return std::to_string(value);
}

bool DataNodeInt::IsEqualTo(std::shared_ptr<DataNodeBase> rhs) {
    assert(typeid(*this) == typeid(*rhs));

    return value == std::dynamic_pointer_cast<DataNodeInt>(rhs)->value;
}

std::shared_ptr<DataNodeBase> DataNodeInt::DeepCopy() {
    auto result = std::make_shared<DataNodeInt>();
    result->value = value;

    return result;
}

/* ---------------- Implementation for type int ---------------- */

/* ---------------- Implementation for type float ---------------- */

std::string DataNodeFloat::ToString() {
    return std::to_string(value);
}

bool DataNodeFloat::IsEqualTo(std::shared_ptr<DataNodeBase> rhs) {
    assert(typeid(*this) == typeid(*rhs));

    return value == std::dynamic_pointer_cast<DataNodeFloat>(rhs)->value;
}

std::shared_ptr<DataNodeBase> DataNodeFloat::DeepCopy() {
    auto result = std::make_shared<DataNodeFloat>();
    result->value = value;

    return result;
}

/* ---------------- Implementation for type float ---------------- */

/* ---------------- Implementation for type str ---------------- */

std::string DataNodeStr::ToString() {
    return value;
}

bool DataNodeStr::IsEqualTo(std::shared_ptr<DataNodeBase> rhs) {
    assert(typeid(*this) == typeid(*rhs));

    return value == std::dynamic_pointer_cast<DataNodeStr>(rhs)->value;
}

std::shared_ptr<DataNodeBase> DataNodeStr::DeepCopy() {
    auto result = std::make_shared<DataNodeStr>();
    result->value = value;

    return result;
}

/* ---------------- Implementation for type str ---------------- */

/* ---------------- Implementation for type list ---------------- */

std::string DataNodeList::ToString() {
    std::string result = "[ ";
    bool first = true;
    for(auto gdn : value) {
        result += (first ? "" : ", ") + gdn.ToString();
        first = false;
    }
    result += " ]";

    return result;
}

bool DataNodeList::IsEqualTo(std::shared_ptr<DataNodeBase> rhs) {
    assert(typeid(*this) == typeid(*rhs));

    auto & rhsList = std::dynamic_pointer_cast<DataNodeList>(rhs)->value;

    /// the size of two lists should be same
    if(rhsList.size() != value.size()) {
        return false;
    }

    /// compare the elements one by one
    for(size_t i = 0; i < value.size(); ++i) {
        if(!value[i].IsEqualTo(rhsList[i])) {
            return false;
        }
    }

    return true;
}

std::shared_ptr<DataNodeBase> DataNodeList::DeepCopy() {
    auto result = std::make_shared<DataNodeList>();
    
    for(auto gdn : value) {
        /// ensure there is no loop (self containing) inside the list
        assert(gdn.data.get() != this);

        result->value.push_back(gdn.DeepCopy());
    }

    return result;
}

/* ---------------- Implementation for type list ---------------- */

/* ---------------- Implementation for type dict ---------------- */

std::string DataNodeDict::ToString() {
    std::string result = "{ ";
    bool first = true;
    for(auto kv : value) {
        result += std::string(first ? "" : ", ") + "\"" + kv.first + "\" : " + kv.second.ToString();
        first = false;
    }
    result += " }";

    return result;
}

bool DataNodeDict::IsEqualTo(std::shared_ptr<DataNodeBase> rhs) {
    assert(typeid(*this) == typeid(*rhs));

    auto & rhsMap = std::dynamic_pointer_cast<DataNodeDict>(rhs)->value;

    /// the size of two lists should be same
    if(rhsMap.size() != value.size()) {
        return false;
    }

    /// compare the keys and values one by one
    for(auto kv : value) {
        if(!kv.second.IsEqualTo(rhsMap[kv.first])) {
            return false;
        }
    }

    return true;
}

std::shared_ptr<DataNodeBase> DataNodeDict::DeepCopy() {
    auto result = std::make_shared<DataNodeDict>();
    
    for(auto kv : value) {
        /// ensure there is no loop (self containing) inside the dict
        assert(kv.second.data.get() != this);

        result->value[kv.first] = kv.second.DeepCopy();
    }

    return result;
}

/* ---------------- Implementation for type dict ---------------- */

/* ---------------- Implementation for type func ---------------- */

std::string DataNodeFunc::ToString() {
    std::string result = "(";

    bool first = true;
    for(auto paramName : paramNames) {
        result += (first ? "" : ", ") + paramName;
        first = false;
    }

    if(withArrTail) {
        result += (first ? "[" : ", [") + arrName + "]";
    }

    result += ") => func<" + std::to_string(reinterpret_cast<uint64_t>(this->body->body[0].get())) + ">";

    return result;
}

bool DataNodeFunc::IsEqualTo(std::shared_ptr<DataNodeBase> rhs) {
    assert(typeid(*this) == typeid(*rhs));

    /// for func, the storage of them are unique, so only need to 
    /// compare the location
    return this->body->body[0].get() == std::dynamic_pointer_cast<DataNodeFunc>(rhs)->body->body[0].get();
}

std::shared_ptr<DataNodeBase> DataNodeFunc::DeepCopy() {
    auto result = std::make_shared<DataNodeFunc>(*this);
    result->thisDict.reset();

    return result;
}

/* ---------------- Implementation for type func ---------------- */

/* ---------------- Implementation for type systemfunc ---------------- */

std::string DataNodeSystemFunc::ToString() {
    return "sysfunc<" + std::to_string(reinterpret_cast<uint64_t>(impl.target<void*>())) + ">";
}

bool DataNodeSystemFunc::IsEqualTo(std::shared_ptr<DataNodeBase> rhs) {
    assert(typeid(*this) == typeid(*rhs));

    return impl.target<void*>() == std::dynamic_pointer_cast<DataNodeSystemFunc>(rhs)->impl.target<void*>();
}

std::shared_ptr<DataNodeBase> DataNodeSystemFunc::DeepCopy() {
    auto result = std::make_shared<DataNodeSystemFunc>();
    result->impl = impl;

    return result;
}

/* ---------------- Implementation for type systemfunc ---------------- */

/* ---------------- Implementation for type weak ref ---------------- */

std::string DataNodeWeakReference::ToString() {
    return "weakref<" + std::to_string(reinterpret_cast<uint64_t>(ptr.lock().get())) + ">" + 
            "(count=" + std::to_string(ptr.use_count()) + ")";
}

bool DataNodeWeakReference::IsEqualTo(std::shared_ptr<DataNodeBase> rhs) {
    assert(typeid(*this) == typeid(*rhs));

    return ptr.lock() == std::dynamic_pointer_cast<DataNodeWeakReference>(rhs)->ptr.lock();
}

std::shared_ptr<DataNodeBase> DataNodeWeakReference::DeepCopy() {
    auto result = std::make_shared<DataNodeWeakReference>();
    result->ptr = ptr;
    result->type = type;

    return result;
}

/* ---------------- Implementation for type weak ref ---------------- */
