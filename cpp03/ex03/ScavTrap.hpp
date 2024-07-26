#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class ScavTrap : virtual public ClapTrap{

    private:
    
    public:
        ScavTrap( const std::string &name);
        ScavTrap(const ScavTrap &toCopy);
        ScavTrap &operator=(const ScavTrap &toCopy );
        ~ScavTrap();

        void attack(const std::string &target);
        void guardGate();
};

#endif