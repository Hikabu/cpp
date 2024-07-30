#ifndef CHARACTER_HPP
# define CHARACTER_HPP

#include <iostream>
#include "AMateria.hpp"


class Character : public ICharacter{ //pure cant drectly use its functions or instance
    private:
        std::string _name;
        AMateria* _inventory[4];
        AMateria** _onFloor;
        int _count;

    public:
        Character(std::string name);
        Character(const Character& toCopy);
        Character& operator=(const Character &toCopy);
        virtual ~Character();

        virtual std::string const & getName() const;
        virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif