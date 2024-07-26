#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap(const std::string &name) : ClapTrap(name, 100, 100, 30){
    std::cout << "FragTrap constructor called " << std::endl;
}

FragTrap::FragTrap(const FragTrap &toCopy) : ClapTrap(toCopy){
    std::cout << "FragTrap copy constructor called " << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &toCopy){
    std::cout << "FragTrap copy assignment constructor called" << std::endl;
    ClapTrap::operator=(toCopy);
    return(*this);
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(){
    std::cout << COLOR_ANOTHER << "Dude, high fives from " << getName() << COLOR_CLEAN << std::endl << std::endl;
}