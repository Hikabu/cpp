#ifndef DOG_HPP
# define DOG_HPP

#include <iostream>
#include "Animal.hpp"

class Dog : public Animal {
    protected:
        std::string _type;

    public:
        Dog();
        Dog(const Dog &toCopy);
        Dog &operator=(const Dog &toCopy);
        ~Dog();

};

#endif