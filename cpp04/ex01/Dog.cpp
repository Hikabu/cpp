#include "Dog.hpp"

//shallow copy - cool pic, just simple replica 
//deep copy - wow, replica with the soul

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
        Animal::operator=(toCopy); // dog is type of animal - to shure all anima copied correctly 
        delete _brain; //avoid mem.leaks 
        _brain = new Brain(*toCopy._brain);
        // *this = toCopy; //shallow copy 
        _type = toCopy._type;

    }
        return (*this);
}

Dog::~Dog(){
    std::cout << "Dog destructor called" << std::endl;
    delete _brain;
}
std::string Dog::getIdea() const{
    return  (this->_who);
}
void Dog::setIdea(std::string idea){
   this->_who = idea;
}


void Dog::makeSound() const{
    std::cout << "Woof woof woof woof woof woof woof " << std::endl;
}