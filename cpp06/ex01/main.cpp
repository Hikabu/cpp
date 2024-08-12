#include "Serialize.hpp"

int main()
{
    struct Data data;
    data.s1 = "Fridge is cool";
    data.s2 = "especially when u in Thailnad ";
    data.i = 42;

    Data *ptr = &data;
    std::cout << "pointer: " << ptr << std::endl;

    uintptr_t iptr = Serialize::serializer(ptr);
    std::cout << "int pointer: " << iptr << std::endl;

    ptr = Serialize::deserialize(iptr);
    
    std::cout   << "pointer= " << ptr      \
                << " -val1- " << ptr->s1 \
                << " -val2- " << ptr->s2 \
                << " -val3- " << ptr->i << std::endl; \

}