#ifndef DIAMONDTRAP
# define DIAMONDTRAP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap: public FragTrap,public ScavTrap
{
	private:
		std::string Name;

	public:
		DiamondTrap();
		void attack(const std::string &target);

};

#endif

/* VIRTUAL INHERITANCE
	https://www.freecodecamp.org/news/what-is-virtual-inheritance/#:~:text=To%20inherit%20virtually%20we%20simply,to%20inherit%20from%20A%20virtually.
 */