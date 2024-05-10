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
std::string *resurrect(std::string name)
{
    std::string* newborn = new Zombie(name);
    return (newborn);
}

