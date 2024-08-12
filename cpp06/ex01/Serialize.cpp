#include "Serialize.hpp"

#define COLOR_RED "\x1b[31m"
#define COLOR_CLEAN "\x1b[0m"

 Serialize::Serialize() {}
                                          
 Serialize:: Serialize(const Serialize &toCopy){
   *this = toCopy;
}

 Serialize & Serialize::operator=(const  Serialize &toCopy) {
    return (*this);
}

 Serialize::~ Serialize(){}

 