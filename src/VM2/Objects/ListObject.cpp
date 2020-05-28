#include "ListObject.hpp"
#include "BoolObject.hpp"
#include "IntObject.hpp"
#include "ObjectExceptions.hpp"

using namespace ws::vm2;

std::string ListObject::toString() {
    std::string result = "[";
    bool first = true;

    for(auto & val : value) {
        if(!first) {
            result += ", ";
        }
        result += val->toString();
        first = false;
    }

    result += "]";
    return result;
}

Object::RValue ListObject::dCopy() {
    if(underRecursiveTraverse) {
        throw RecursiveTraverse();
    }

    auto result = std::make_shared<ListObject>();
    underRecursiveTraverse = true;

    for(auto & val : value) {
        result->value.push_back(val->dCopy());
    }

    underRecursiveTraverse = false;
    return result;
}

Object::LValue ListObject::operator[](RValue index) {
    int64_t idx = index->as<IntObject>()->value;

    if(idx < 0) {
        throw IndexOutOfRange();
    }

    if(idx >= value.size()) {
        value.resize(idx + 1);
    }

    return &(value[idx]);
}

Object::RValue ListObject::subscript(RValue index) {
    int64_t idx = index->as<IntObject>()->value;

    if(idx < 0 || idx >= value.size()) {
        throw IndexOutOfRange();
    }

    return value[idx];
}

Object::RValue ListObject::operator+(RValue rhs) {
    auto result = std::make_shared<ListObject>(value);
    result->value.push_back(rhs);
    return result;
}

Object::RValue ListObject::operator<(RValue rhs) {
    // compare to self
    if(this == rhs.get()) {
        return std::make_shared<BoolObject>(false);
    }

    // forbid recursively comparison
    if(underRecursiveTraverse || rhs->as<ListObject>()->underRecursiveTraverse) {
        throw RecursiveTraverse();
    }

    auto & rhsValue = rhs->as<ListObject>()->value;
    auto itThis = value.begin();
    auto itThat = rhsValue.begin();

    // compare in lexicographic order
    underRecursiveTraverse = true;
    rhs->as<ListObject>()->underRecursiveTraverse = true;

    while(itThis != value.end() && itThat != rhsValue.end()) {
        if(static_cast<bool>((*itThis)->operator<(*itThat))) {
            return std::make_shared<BoolObject>(true);
        }
        if(static_cast<bool>((*itThat)->operator<(*itThis))) {
            return std::make_shared<BoolObject>(false);
        }
        ++itThis;
        ++itThat;
    }

    underRecursiveTraverse = false;
    rhs->as<ListObject>()->underRecursiveTraverse = false;

    return std::make_shared<BoolObject>(itThat != rhsValue.end());
}

Object::RValue ListObject::operator==(RValue rhs) {
    if(rhs->type != TypeList) {
        return std::make_shared<BoolObject>(false);
    }

    // compare to self
    if(this == rhs.get()) {
        return std::make_shared<BoolObject>(true);
    }

    // forbid recursively comparison
    if(underRecursiveTraverse || rhs->as<ListObject>()->underRecursiveTraverse) {
        throw RecursiveTraverse();
    }

    auto & rhsValue = rhs->as<ListObject>()->value;

    // check list size
    if(value.size() != rhsValue.size()) {
        return std::make_shared<BoolObject>(false);
    }

    // compare one by one
    underRecursiveTraverse = true;
    rhs->as<ListObject>()->underRecursiveTraverse = true;

    for(size_t i = 0; i < value.size(); ++i) {
        if(!value[i]->operator==(rhsValue[i])) {
            return std::make_shared<BoolObject>(false);
        }
    }

    underRecursiveTraverse = true;
    rhs->as<ListObject>()->underRecursiveTraverse = false;

    return std::make_shared<BoolObject>(true);
}

ListObject::operator bool() {
    return !value.empty();
}

std::shared_ptr<Object::Iterator> ListObject::iter() {
    return std::make_shared<ListIterator>(value.begin(), value.end());
}

void ListObject::markReachables(uint8_t gcValue) {
    for(auto & val : value) {
        if(val->gcMarking != gcValue) {
            val->gcMarking = gcValue;
            val->markReachables(gcValue);
        }
    }
}

bool ListObject::ListIterator::advance() {
    if(iter != end) {
        ++iter;
        return true;
    }
    return false;
}

Object::RValue ListObject::ListIterator::curr() {
    return *iter;
}

bool ListObject::ListIterator::available() {
    return iter != end;
}
