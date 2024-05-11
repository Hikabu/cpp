#include "Zombie.hpp"

void Zombie::setName(std::string name)
{
    this->name = name;
}

Zombie* zombieHorde( int N, std::string name )
{
    Zombie *foReturn = new Zombie[N];
    
    for (int i = 0;  i < N; i++)
    {
        foReturn[i].setName(name);
        foReturn->announce();
    }
    return (foReturn);
}
