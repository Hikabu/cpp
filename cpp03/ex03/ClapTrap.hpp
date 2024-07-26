#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

#define COLOR_RED "\x1b[31m"
#define COLOR_GREEN "\x1b[32m"
#define COLOR_YELLOW "\x1b[33m"
#define COLOR_GREY "\x1b[90m"
#define COLOR_CLEAN "\x1b[0m"
#define COLOR_ANOTHER "\x1b[35m"

class ClapTrap{
    private:

        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:
        ClapTrap(const std::string &name);
        ClapTrap(const ClapTrap &toCopy);
        ClapTrap &operator=(const ClapTrap &value);
        ~ClapTrap();
        ClapTrap(const std::string &name, int HitPoints, \
            int EnergyPoints, int AttackPoints);

    //functions
    	void attack(const std::string& target);
    	void takeDamage(unsigned int amount);
    	void beRepaired (unsigned int amount);
    	void status();

	//get and set
    void setName( const std::string &name );
	void setAttackDamage (unsigned const int attackDemage);
	void setHitPoints (unsigned const int hitPoints);
	void setEnergyPoints (unsigned const int energyPoints);

    const std::string&	getName() const;
	int getAttackDamage() const;
	int getHitPoints() const;
	int getEnergyPoints() const;
};


#endif