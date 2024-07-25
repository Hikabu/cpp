#include "ClapTrap.hpp"

int main(){

    ClapTrap enemy("Volandemort");
    ClapTrap hero("HarryPotter");

    enemy.setAttackDamage(50);
    hero.setAttackDamage (51);
    enemy.setEnergyPoints(1);
    hero.setEnergyPoints(1);
    enemy.status();
    hero.status();

    hero.attack("Volandemort");
    enemy.attack("HarryPotter");
    enemy.beRepaired(1);
    hero.beRepaired(1);
    hero.takeDamage(enemy.getAttackDamage());
    enemy.takeDamage(hero.getAttackDamage());

   
}