#include "Dog.hpp"

Dog::Dog() : Animal(){
    std::cout << "Dog constructor called" << std::endl;
    _type = ("Dog");
}

Dog::Dog( const Dog &toCopy) : Animal(toCopy){
    *this = toCopy;
    std::cout << "Dog copy constructor called " << std::endl;
}

Dog &Dog::operator=(const Dog &toCopy){
    std::cout << "Dog copy assignment constructor called" << std::endl;
    if (this == &toCopy)
        return (*this);
    _type = toCopy._type;
    return (*this);
}

Dog::~Dog(){
    std::cout << "Dog destructor called" << std::endl;
}


void Dog::makeSound() const{
    std::cout << "Woof woof woof woof woof woof woof " << std::endl;
}