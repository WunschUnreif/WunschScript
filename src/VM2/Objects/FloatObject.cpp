#include "FloatObject.hpp"
#include "IntObject.hpp"
#include "BoolObject.hpp"
#include "ObjectExceptions.hpp"

using namespace ws::vm2;

std::string FloatObject::toString() {
    return std::to_string(value);
}

FloatObject::RValue FloatObject::dCopy() {
    return std::make_shared<FloatObject>(value);
}

FloatObject::RValue FloatObject::operator+() {
    return std::make_shared<FloatObject>(value);
}

FloatObject::RValue FloatObject::operator-() {
    return std::make_shared<FloatObject>(-value);
}

FloatObject::RValue FloatObject::operator+(RValue rhs) {
    try { return std::make_shared<FloatObject>(value + rhs->as<FloatObject>()->value); } 
    catch (TypeError) {}
    
    return std::make_shared<FloatObject>(value + rhs->as<IntObject>()->value);
}

FloatObject::RValue FloatObject::operator-(RValue rhs) {
    try { return std::make_shared<FloatObject>(value - rhs->as<FloatObject>()->value); } 
    catch (TypeError) {}
    
    return std::make_shared<FloatObject>(value - rhs->as<IntObject>()->value);
}

FloatObject::RValue FloatObject::operator*(RValue rhs) {
    try { return std::make_shared<FloatObject>(value * rhs->as<FloatObject>()->value); } 
    catch (TypeError) {}
    
    return std::make_shared<FloatObject>(value * rhs->as<IntObject>()->value);
}

FloatObject::RValue FloatObject::operator/(RValue rhs) {
    try { 
        double rhsValue = rhs->as<FloatObject>()->value;
        if(rhsValue == 0) {
            throw DividedByZero();
        }
        return std::make_shared<FloatObject>(value / rhsValue); 
    } 
    catch (TypeError) {}
    
    int64_t rhsValue = rhs->as<IntObject>()->value;
    if(rhsValue == 0) {
        throw DividedByZero();
    }
    return std::make_shared<FloatObject>(value / rhsValue);
}

FloatObject::RValue FloatObject::operator<(RValue rhs) {
    try { return std::make_shared<BoolObject>(value < rhs->as<FloatObject>()->value); } 
    catch (TypeError) {}
    
    return std::make_shared<BoolObject>(value < rhs->as<IntObject>()->value);
}

FloatObject::RValue FloatObject::operator==(RValue rhs) {
    try { return std::make_shared<BoolObject>(value == rhs->as<FloatObject>()->value); } 
    catch (TypeError) {}
    
    try { return std::make_shared<BoolObject>(value == rhs->as<IntObject>()->value); }
    catch (TypeError) {}

    return std::make_shared<BoolObject>(false);
}

FloatObject::operator bool() {
    return value != 0;
}
