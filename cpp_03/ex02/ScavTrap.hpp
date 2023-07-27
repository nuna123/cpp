#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap
{
	private:
		bool	GateKeepMode;
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &scavTrap);
		~ScavTrap(void);

		ScavTrap& operator=(ScavTrap const &scavTrap);
		void	guardGate(void);
		void		attack(const std::string& target);

};

#endif
