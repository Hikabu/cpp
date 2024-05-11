#include "Zombie.hpp"

Zombie::Zombie(){
}

Zombie::~Zombie(){
    std::cout << "I am the destroyer" << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->name = name;
}

void Zombie::announce( void )
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie *resurrect(std::string name)
{
    Zombie* newborn = new Zombie(name);
    return (newborn);
}

