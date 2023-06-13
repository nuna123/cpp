#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap
{
	private:
		bool	GateKeepMode;
	public:
		ScavTrap(std::string name): ClapTrap(name, 100, 50, 20)
		{
			this->GateKeepMode = false;
			std::cout << "Im a ScavTrap. Cool!" <<std::endl;
		}
		~ScavTrap(void)
		{
			std::cout << "Im a ScavTrap. I am also dead." <<std::endl;
		}

		void	guardGate(void)
		{
			std::cout << "Im a ScavTrap. A GateKeeping scavTrap." <<std::endl;
			this->GateKeepMode = true;
		}
};
#endif

