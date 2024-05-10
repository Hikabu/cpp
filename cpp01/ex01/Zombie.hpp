#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>


class Zombie{
    private:
        std::string name;
    public:
        Zombie();
        ~Zombie();
        std::string *resurrect(std::string name);
        Zombie(std::string name);
};
Zombie* zombieHorde( int N, std::string name );

#endif