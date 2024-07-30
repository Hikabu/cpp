#include "AMateria.hpp"

AMateria::AMateria(std::string const &type){
    std::cout << "AMateria constructor called" << std::endl;
    _materiaType = type;
}

AMateria::AMateria( const AMateria &copy){
    *this = copy;
    std::cout << "AMateria copy constructor called " << std::endl;
}

AMateria &AMateria::operator=(const AMateria &copy){
    std::cout << "AMateria copy assignment constructor called" << std::endl;
    if (this == &copy)
        return (*this);
    _materiaType = copy._materiaType;
    return (*this);
}

AMateria::~AMateria(){
    std::cout << "AMateria destructor called" << std::endl;
}

std::string const &AMateria::getType()const {
    return (_materiaType);
}

void AMateria::use(ICharacter& target){
    (void)target;
}