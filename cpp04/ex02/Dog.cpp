#include "Dog.hpp"

Dog::Dog() : Animal(), _brain(new Brain()){
    _type = ("Dog");
    std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog( const Dog &toCopy) : Animal(toCopy){
     _brain = new Brain(*toCopy._brain); //deep copy of the brain 
    _type = toCopy._type;
    // *this = toCopy;
    std::cout << "Dog copy constructor called " << std::endl;
}

Dog &Dog::operator=(const Dog &toCopy){
    std::cout << "Dog copy assignment constructor called" << std::endl;
    if (this != &toCopy){
        Animal::operator=(toCopy);
        delete _brain;
        _brain = new Brain(*toCopy._brain);
        // *this = toCopy;
        _type = toCopy._type;

    }
        return (*this);
}

Dog::~Dog(){
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}
void Dog::makeSound() const{
    std::cout << "Woof woof woof woof woof woof woof " << std::endl;
}