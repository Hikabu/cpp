#include "WrongCat.hpp"

WrongCat::WrongCat(){
    std::cout << "WrongCat constructor called" << std::endl;
    _type = ("WrongCat");
}

WrongCat::WrongCat( const WrongCat &toCopy){
    *this = toCopy;
    std::cout << "WrongCat copy constructor called " << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &toCopy){
    std::cout << "WrongCat copy assignment constructor called" << std::endl;
    if (this == &toCopy)
        return (*this);
    _type = toCopy._type;
    return (*this);
}

WrongCat::~WrongCat(){
    std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << "SeGFoULt SeGFoULt SeGFoULt SeGFoULt" << std::endl;
    
}