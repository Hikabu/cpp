#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(){


    ClapTrap enemy("Volandemort");
    ClapTrap hero("HarryPotter");

    ScavTrap death("Draco");
    ScavTrap death1("Vincent");
    ScavTrap death2("Gregory");
    ScavTrap death3(death2);

    enemy.attack("HarryPotter");
    hero.attack("Vincent");
    death1.attack("Draco");
    death.takeDamage(death1.getAttackDamage());
    death2.guardGate();
}

