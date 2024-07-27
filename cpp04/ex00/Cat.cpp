#include "Cat.hpp"

Cat::Cat(){
    std::cout << "Cat constructor called" << std::endl;
    _type = ("Cat");
}

Cat::Cat( const Cat &toCopy){
    *this = toCopy;
    std::cout << "Cat copy constructor called " << std::endl;
}

Cat &Cat::operator=(const Cat &toCopy){
    std::cout << "Cat copy assignment constructor called" << std::endl;
    if (this == &toCopy)
        return (*this);
    _type = toCopy._type;
    return (*this);
}

Cat::~Cat(){
    std::cout << "Cat destructor called" << std::endl;
}