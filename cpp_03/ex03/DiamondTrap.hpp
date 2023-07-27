#ifndef DIAMONDTRAP
# define DIAMONDTRAP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class	DiamondTrap: public FragTrap,public ScavTrap
{
	private:
		std::string Name;
		void init(void);

	public:
		DiamondTrap();
		~DiamondTrap();
		DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap const &diamondTrap);

		DiamondTrap& operator=(DiamondTrap const &diamondTrap);

		void	attack(const std::string &target);
		void	whoAmI(void);
		std::string	get_diamond_name(void) const;
};

#endif

/* VIRTUAL INHERITANCE
	https://www.freecodecamp.org/news/what-is-virtual-inheritance/#:~:text=To%20inherit%20virtually%20we%20simply,to%20inherit%20from%20A%20virtually.
 */