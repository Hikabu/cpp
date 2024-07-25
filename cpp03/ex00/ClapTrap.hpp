#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# include <iostream>

class ClapTrap{
    private:

        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;

    public:
        ClapTrap(std::string name);
        ClapTrap(const ClapTrap &toCopy);
        ClapTrap &operator=(const ClapTrap &value);
        ~ClapTrap();

    //functions
    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired (unsigned int amount);

    void status();

	//get and set
	void setAttackDamage (unsigned const int attackDemage);
	void setHitPoints (unsigned const int hitPoints);
	void setEnergyPoints (unsigned const int energyPoints);

	int getAttackDamage() const;
	int getHitPoints() const;
	int getEnergyPoints() const;
};


#endif