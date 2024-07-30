#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    std::cout << "WrongAnimal constructor called" << std::endl;
    _type = ("WrongAnimal");
}

WrongAnimal::WrongAnimal( const WrongAnimal &toCopy){
    *this = toCopy;
    std::cout << "WrongAnimal copy constructor called " << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &toCopy){
    std::cout << "WrongAnimal copy assignment constructor called" << std::endl;
    if (this == &toCopy)
        return (*this);
    _type = toCopy._type;
    return (*this);
}

WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal destructor called" << std::endl;
}

std::string WrongAnimal::getType() const{
    return (_type);
}

void WrongAnimal::setType(std::string type){
    this->_type = type;
}

void WrongAnimal::makeSound() const{
    std::cout << "Wrong animal sounds like " << std::endl;
    
}

