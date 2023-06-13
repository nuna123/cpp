
#include	"ClapTrap.hpp"
#include	"ScavTrap.hpp"

int	main( void )
{
	ScavTrap scavvy("clappy");
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