#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal {
    private:
        Brain *_brain;
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