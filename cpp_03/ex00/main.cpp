
#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap clapTrap("WittyWill");

	clapTrap.stats();
	clapTrap.attack("HandsomeJack");
	clapTrap.takeDamage(6);
	clapTrap.beRepaired(4);
	clapTrap.takeDamage(3);
	clapTrap.beRepaired(8);
	clapTrap.takeDamage(17);
}