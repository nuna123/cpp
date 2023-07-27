#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	FragTrap: virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const &fragTrap);
		~FragTrap(void);

		FragTrap& operator=(FragTrap const &fragTrap);
		void highFivesGuys(void);
};
#endif
