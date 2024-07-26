#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main ( void )
{
	DiamondTrap hero("HarryPotter");

	hero.whoAmI();
	hero.highFivesGuys();
	hero.guardGate();
	hero.attack("whoIsIt");
	hero.beRepaired(1);

	return (0);
}

