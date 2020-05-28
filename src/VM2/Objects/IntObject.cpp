#include "IntObject.hpp"
#include "FloatObject.hpp"
#include "BoolObject.hpp"
#include "ObjectExceptions.hpp"

using namespace ws::vm2;

std::string IntObject::toString() {
    return std::to_string(value);
}

IntObject::RValue IntObject::dCopy() {
    return std::make_shared<IntObject>(value);
}

IntObject::RValue IntObject::operator~() {
    return std::make_shared<IntObject>(~value);
}

IntObject::RValue IntObject::operator+() {
    return std::make_shared<IntObject>(value);
}

IntObject::RValue IntObject::operator-() {
    return std::make_shared<IntObject>(-value);
}

IntObject::RValue IntObject::operator+(RValue rhs) {
    try { return std::make_shared<IntObject>(value + rhs->as<IntObject>()->value); } 
    catch (TypeError) {}
    
    return std::make_shared<FloatObject>(value + rhs->as<FloatObject>()->value);
}

IntObject::RValue IntObject::operator-(RValue rhs) {
    try { return std::make_shared<IntObject>(value - rhs->as<IntObject>()->value); } 
    catch (TypeError) {}
    
    return std::make_shared<FloatObject>(value - rhs->as<FloatObject>()->value);
}

IntObject::RValue IntObject::operator*(RValue rhs) {
    try { return std::make_shared<IntObject>(value * rhs->as<IntObject>()->value); } 
    catch (TypeError) {}
    
    return std::make_shared<FloatObject>(value * rhs->as<FloatObject>()->value);
}

IntObject::RValue IntObject::operator/(RValue rhs) {
    try { 
        int64_t rhsValue = rhs->as<IntObject>()->value;
        if(rhsValue == 0) {
            throw DividedByZero();
        }
        return std::make_shared<IntObject>(value / rhsValue); 
    } 
    catch (TypeError) {}
    
    double rhsValue = rhs->as<FloatObject>()->value;;
    if(rhsValue == 0) {
        throw DividedByZero();
    }
    return std::make_shared<FloatObject>(value / rhsValue);
}

IntObject::RValue IntObject::operator%(RValue rhs) {
    return std::make_shared<IntObject>(value % rhs->as<IntObject>()->value); 
}

IntObject::RValue IntObject::operator<(RValue rhs) {
    try { return std::make_shared<BoolObject>(value < rhs->as<IntObject>()->value); } 
    catch (TypeError) {}
    
    return std::make_shared<BoolObject>(value < rhs->as<FloatObject>()->value);
}

IntObject::RValue IntObject::operator==(RValue rhs) {
    try { return std::make_shared<BoolObject>(value == rhs->as<IntObject>()->value); } 
    catch (TypeError) {}
    
    return std::make_shared<BoolObject>(value == rhs->as<FloatObject>()->value);
}

IntObject::RValue IntObject::operator&(RValue rhs) {
    return std::make_shared<IntObject>(value & rhs->as<IntObject>()->value); 
}

IntObject::RValue IntObject::operator|(RValue rhs) {
    return std::make_shared<IntObject>(value | rhs->as<IntObject>()->value); 
}

IntObject::RValue IntObject::operator^(RValue rhs) {
    return std::make_shared<IntObject>(value ^ rhs->as<IntObject>()->value); 
}

IntObject::operator bool() {
    return value != 0;
}
