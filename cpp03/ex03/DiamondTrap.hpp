#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include "ClapTrap.hpp"
# include "ScavTrap.hpp"
# include "FragTrap.hpp"
# include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap{

    private:
        std::string _name;
    public:
        DiamondTrap( const std::string &name);
        DiamondTrap(const DiamondTrap &toCopy);
        DiamondTrap &operator=(const DiamondTrap &toCopy );
        ~DiamondTrap();

        void attack(const std::string &target);
        void whoAmI();
};

#endif