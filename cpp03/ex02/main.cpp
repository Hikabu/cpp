#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(){

    ClapTrap hero("HarryPotter");
    ScavTrap death("Draco");
    FragTrap dude("SomeDude");

    hero.attack("Draco");
    death.takeDamage(hero.getAttackDamage());
    dude.attack("HarryPotter");
    hero.takeDamage(dude.getAttackDamage());
    dude.highFivesGuys();
}

