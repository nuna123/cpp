#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap
{
	private:
		bool	GateKeepMode;
	public:
		ScavTrap(std::string name);
		~ScavTrap(void);

		void	guardGate(void);
};

#endif
