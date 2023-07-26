#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20)
{
	this->GateKeepMode = false;
	std::cout << "Im a ScavTrap. Cool!" <<std::endl;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << "Im a ScavTrap. I am also dead." <<std::endl;
}

void	ScavTrap::guardGate(void)
{
	std::cout << "Im a ScavTrap. A GateKeeping scavTrap." <<std::endl;
	this->GateKeepMode = true;
}