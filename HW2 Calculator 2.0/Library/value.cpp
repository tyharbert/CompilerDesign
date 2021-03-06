// Tyler Harbert
// code file for value class

#include "value.hpp"

// Value class function definitions

int Value::get_int(){
    return this->_i;
}

bool Value::get_bool(){
    return this->_b;
}

int Value::type(){
    return (int)this->_t;
}

bool Value::is_bool() const{
    return this->_t == BOOL;
}

bool Value::is_int() const{
    return this->_t == INT;
}

// overloading cout operators
std::ostream& operator<<(std::ostream& os, const Value& v)
{
    if (v.is_int())
        os << v._i;
    else
        os << (v._b?"true":"false");
    
    return os;
}