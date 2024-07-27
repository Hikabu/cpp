#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

class Animal{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(const Animal &toCopy);
        Animal &operator=(const Animal &toCopy);
        ~Animal();

        //get
        std::string getType() const;
};




#endif