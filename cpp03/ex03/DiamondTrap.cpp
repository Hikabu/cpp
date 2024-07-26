#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string &name) : 
    ClapTrap(name + "_clap_trap", 100, 50, 30), ScavTrap(name), FragTrap(name), _name(name)
{
    std::cout << "Defoult constructor called for DiamondTrap" << std::endl;

}
 DiamondTrap::DiamondTrap(const DiamondTrap &toCopy) : ClapTrap(toCopy), ScavTrap(toCopy), FragTrap(toCopy){
    std::cout << "Copy constructor called for DiamondTrap" << std::endl;
 }

 DiamondTrap &DiamondTrap::operator=(const DiamondTrap &toCopy) {
    std::cout << "Copy assignment constructor called for DiamondTrap" << std::endl;
    this->ClapTrap::operator=(toCopy);
    return (*this);
 }

 DiamondTrap::~DiamondTrap(){
    std::cout << "Destructor called for DiamondTrap" << std::endl;
 }

void DiamondTrap::attack(const std::string &target){
    ScavTrap::attack(target);
}


void DiamondTrap::whoAmI(){
    std::cout << "DiamondTrap name is: " << _name << std::endl;
    std::cout << "ClapTrap name is: " << ClapTrap::getName() << std::endl;

}
 
