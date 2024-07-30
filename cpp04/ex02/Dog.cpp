#include "Dog.hpp"

Dog::Dog() {
    std::cout << "Dog constructor called" << std::endl;
    _type = ("Dog");
    _brain = new Brain();
}

Dog::Dog( const Dog &toCopy) {
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
    delete _brain;
}
void Dog::makeSound() const{
    std::cout << "Woof woof woof woof woof woof woof " << std::endl;
}