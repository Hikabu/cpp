#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>>

class Animal{
    protected:
        std::string _type;

    public:
        Animal();
        Animal(const Animal &toCopy);
        Animal &operator=(const Animal &toCopy);
        ~Animal();

};

#endif