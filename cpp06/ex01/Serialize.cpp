#include "Serialize.hpp"

#define COLOR_RED "\x1b[31m"
#define COLOR_CLEAN "\x1b[0m"

 Serialize::Serialize() {}
                                          
 Serialize:: Serialize(const Serialize &toCopy){
   *this = toCopy;
}

 Serialize & Serialize::operator=(const  Serialize &toCopy) {
    if (this != &toCopy)
    {}

    return (*this);
}

 Serialize::~ Serialize(){}

uintptr_t   Serialize::serializer(Data* ptr){
   return (reinterpret_cast<uintptr_t>(ptr));
}
Data*       Serialize::deserialize(uintptr_t raw){
   return (reinterpret_cast<Data*> (raw));
}