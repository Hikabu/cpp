#include "Animal.hpp"

Animal::Animal(){
    std::cout << "Animal constructor called" << std::endl;
    _type = ("Animal");
}

Animal::Animal( const Animal &toCopy){
    *this = toCopy;
    std::cout << "Animal copy constructor called " << std::endl;
}

Animal &Animal::operator=(const Animal &toCopy){
    std::cout << "Animal copy assignment constructor called" << std::endl;
    if (this == &toCopy)
        return (*this);
    _type = toCopy._type;
    return (*this);
}

Animal::~Animal(){
    std::cout << "Animal destructor called" << std::endl;
}

//get

std::string Animal::getType() const {return _type;}

