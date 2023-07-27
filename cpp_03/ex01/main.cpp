
#include	"ClapTrap.hpp"
#include	"ScavTrap.hpp"

int	main( void )
{
	ScavTrap scavvy("Clappy");

	ScavTrap scav_cpy(scavvy);
	scav_cpy.stats();

	scavvy.attack("Bob");
	scavvy.takeDamage(4);
	scavvy.beRepaired(1);
	scavvy.guardGate();



/* 	clappy.attack("Handsome Jack");
	clappy.takeDamage(6);
	clappy.beRepaired(4);
	clappy.takeDamage(3);
	clappy.beRepaired(8);
	clappy.takeDamage(17); */
}