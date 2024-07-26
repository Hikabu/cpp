#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "DiamondTrap.hpp"

ScavTrap::ScavTrap( const std::string &name) : ClapTrap(name, 100, 50, 20) {
    std::cout << "Defoult constructor called ScavTrap " << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &toCopy) : ClapTrap(toCopy){
    std::cout << "Copy constructor called ScavTrap" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &toCopy){
    std::cout << "Copy assignment constructor called ScavTrap" << std::endl;
    ClapTrap::operator=(toCopy);
    return (*this);
}

ScavTrap::~ScavTrap(){
    std::cout << "Destructor called ScavTrap" << std::endl;
}

void ScavTrap::attack(const std::string &target)
{
    if (getEnergyPoints() <= 0 || getHitPoints() <= 0){
        std::cout << COLOR_GREY "ScavTrap " << getName()  << "out of force, just see his status" << COLOR_CLEAN << std::endl;
        status();
        return ;
    }
    setEnergyPoints(getEnergyPoints() - 1);
    std::cout << COLOR_RED "ScavTrap " << getName() << " attacks " << target << ", causing "
        << getAttackDamage() << " points of damage!" << COLOR_CLEAN << std::endl;
    status();

}

void ScavTrap::guardGate(){
    std::cout << COLOR_YELLOW "ScavTrap " << getName() << " now in guard mode " <<  COLOR_CLEAN << std::endl << std::endl;
}