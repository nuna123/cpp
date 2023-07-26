
#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap cl4ptp("WittyWill");

	cl4ptp.attack("HandsomeJack");
	cl4ptp.takeDamage(6);
	cl4ptp.beRepaired(4);
	cl4ptp.takeDamage(3);
	cl4ptp.beRepaired(8);
	cl4ptp.takeDamage(17);
}