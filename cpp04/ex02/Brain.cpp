#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain( const Brain &toCopy){
    std::cout << "Brain copy constructor called " << std::endl;
    for (int i = 0; i < 100; i++)
        this->_ideas[i] = toCopy._ideas[i];
}

Brain &Brain::operator=(const Brain &toCopy){
    std::cout << "Brain copy assignment constructor called" << std::endl;
    if (this == &toCopy)
        return (*this);
    for(int i = 0; i < 100; i++)
        _ideas[i] = toCopy._ideas[i];
    return (*this);
}

Brain::~Brain(){
    std::cout << "Brain destructor called" << std::endl;
}

//get/set

std::string Brain::getType(int i) const {return this->_ideas[i];}

void Brain::setType(int i, std::string idea)  {this->_ideas[i] = idea;}

