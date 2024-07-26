#include "ClapTrap.hpp"

int main(){

    ClapTrap enemy("Volandemort");
    ClapTrap hero("HarryPotter");

    enemy.setAttackDamage(51);
    hero.setAttackDamage (51);
    enemy.setEnergyPoints(0);
    hero.setEnergyPoints(0);
    enemy.status();
    hero.status();

    hero.attack("Volandemort");
    enemy.attack("HarryPotter");
    enemy.beRepaired(0);
    hero.beRepaired(0);
    hero.takeDamage(enemy.getAttackDamage());
    enemy.takeDamage(hero.getAttackDamage());
}

