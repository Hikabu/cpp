#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal {
    protected:
        std::string _type;

    public:
        Animal();
        Animal(const Animal& toCopy);
        Animal& operator=(const Animal &toCopy);
        virtual ~Animal();

        //get
        std::string getType() const;
        void setType( std::string type);
        void virtual makeSound() const; // dynamic binding resolved at runtime
};




#endif