#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>

class FragTrap : public ClapTrap{

    private:
    
    public:
        FragTrap( const std::string &name);
        FragTrap(const FragTrap &toCopy);
        FragTrap &operator=(const FragTrap &toCopy );
        ~FragTrap();

        void highFivesGuys(void);
};

#endif