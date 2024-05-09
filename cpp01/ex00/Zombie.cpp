#include "Zombie.hpp"

Zombie::Zombie()
{
}
Zombie::~Zombie()
{
    std::cout << this->name << "I don't need zombie anymore. Zombie was destroyed" << std::endl;
}

Zombie::Zombie( std::string name )
{
    this->name = name;
}
