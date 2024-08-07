#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include <iostream>

class Dog : public Animal {
    protected:
        std::string _who;
    public:
        Dog();
        Dog(const Dog &toCopy);
        Dog &operator=(const Dog &toCopy);
        virtual ~Dog();

        void virtual makeSound() const;
};

#endif