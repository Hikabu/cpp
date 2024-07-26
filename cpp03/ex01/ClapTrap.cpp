#include "ClapTrap.hpp"

ClapTrap::ClapTrap(const std::string &name):
                             _name(name),
                             _hitPoints(10),
                            _energyPoints(10),
                            _attackDamage(0)
{

    std::cout << "Constructor called for ClapTrap" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &toCopy){
    *this = toCopy;
    std::cout << "Copy constructor called for ClapTrap" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &toCopy){
    std::cout << "ClapTrap assignation operator called for ClapTrap" << std::endl;
    this->_name = toCopy._name;
    this->_hitPoints = toCopy._hitPoints;
    this->_energyPoints = toCopy._energyPoints;
    this->_attackDamage = toCopy._attackDamage;
    return (*this);
}

ClapTrap::ClapTrap(const std::string &name, int hitPoints, int energyPoints, int attackPoints) : _name(name),
                                                                                                _hitPoints(hitPoints),
                                                                                                _energyPoints(energyPoints),
                                                                                                _attackDamage(attackPoints){
    std::cout << "Constructors with parametrs called" << std::endl;
}

ClapTrap::~ClapTrap(){
    std::cout << "Destructor called for ClapTrap" << std::endl;
}

//get/set
const std::string&	ClapTrap::getName() const { return _name; }

int ClapTrap::getHitPoints() const { return _hitPoints; }
int ClapTrap::getAttackDamage() const { return _attackDamage; }
int ClapTrap::getEnergyPoints() const { return _energyPoints; }

void ClapTrap::setHitPoints( unsigned const int hitPoints ) {_hitPoints = hitPoints >= 0 ? hitPoints : 0;}
void ClapTrap::setAttackDamage( unsigned const int attackDamage) { _attackDamage = attackDamage >= 0 ? attackDamage : 0; }
void ClapTrap::setEnergyPoints( unsigned const int energyPoints) {_energyPoints = energyPoints >= 0 ? energyPoints : 0; }

//status

void ClapTrap::status(){
    std::cout << COLOR_GREY << "ClapTrap status: " << _name <<
                                "\n\t hit_points: " << _hitPoints <<
                                "\n\t energyPoints: " << _energyPoints <<
                                "\n\t DamagePoints: " << _attackDamage <<
                                COLOR_CLEAN << std::endl <<std::endl;
}

//functions

void ClapTrap::attack(const std::string& target){
    if (_hitPoints <= 0 || _energyPoints <= 0){
        std::cout << COLOR_GREY "ClapTrap " << _name << "out of force, just see his status" << COLOR_CLEAN << std::endl;
        status();
        return ;
    }
    setEnergyPoints(_energyPoints - 1);
    std::cout << COLOR_RED "ClapTrap " << _name << " attacks " << target << ", causing "
        << _attackDamage << " points of damage!" << COLOR_CLEAN << std::endl;
    status();
 }

void ClapTrap::beRepaired( unsigned int amount){
    if (_energyPoints <= 0 || _hitPoints <= 0 ){
        std::cout << COLOR_GREY "ClapTrap " << _name << " out of force he can't repair himself" << COLOR_CLEAN << std::endl;
        return ;
    }
    setEnergyPoints(_energyPoints - 1);
    setHitPoints(_hitPoints + amount);
    std::cout << COLOR_GREEN "ClapTrap repairs himself for " << amount << " points" 
                << COLOR_CLEAN << std::endl;
    status();
 }

void ClapTrap::takeDamage(unsigned int amount){
    if (_hitPoints <= 0 || _energyPoints <= 0){
        std::cout << COLOR_GREY "ClapTrap " << _name << " is already dead " << COLOR_CLEAN << std::endl;
        return ;
    }
    if (amount > _hitPoints){
        _hitPoints = 0;
        status();
    } else {
        setHitPoints(_hitPoints - amount);
        std::cout << COLOR_YELLOW "ClapTrap suffered losses in "  << amount 
                <<  " points" << COLOR_CLEAN << std::endl;
        status();
    }
 }