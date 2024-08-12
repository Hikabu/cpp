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

uintptr_t   Serialize::serialize(Data* ptr){
   return (uintptr_t)ptr;
}
Data*       Serialize::deserialize(uintptr_t raw){
   return (Data *)raw;
}