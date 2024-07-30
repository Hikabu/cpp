#include "AMateria.hpp"
#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
    std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure( const Cure &copy) : AMateria (copy){
    *this = copy;
    std::cout << "Cure copy constructor called " << std::endl;
}

Cure &Cure::operator=(const Cure &copy){
    std::cout << "Cure copy assignment constructor called" << std::endl;
    if (this != &copy)
        AMateria::operator=(copy);
    return (*this);
}

Cure::~Cure(){
    std::cout << "Cure destructor called" << std::endl;
}

AMateria* Cure::clone() const{ //must provide its own implemetation of clone()
    return(new Cure());
}

void Cure::use(ICharacter& target){
    std::cout << " heals " << target.getName() << "'s wounds " << std::endl;

}