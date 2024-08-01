#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal(), _brain(new Brain()){
    _type = ("Cat");
    std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat( const Cat &toCopy) : Animal(toCopy){
    _brain = new Brain(*toCopy._brain);
    _type = toCopy._type;
    std::cout << "Cat copy constructor called " << std::endl;
}

Cat &Cat::operator=(const Cat &toCopy){
    std::cout << "Cat copy assignment constructor called" << std::endl;
    if (this != &toCopy){
        Animal::operator=(toCopy);
        delete _brain;
        _brain = new Brain(*toCopy._brain);
        _type = toCopy._type;
    }
    return (*this);
}

Cat::~Cat(){
    std::cout << "Cat destructor called" << std::endl;
    delete _brain;
}

void Cat::makeSound() const{
    std::cout << "Meow meow meow meow meow meow meow " << std::endl;
    
}