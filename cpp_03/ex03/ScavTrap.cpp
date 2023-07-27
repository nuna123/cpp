#include "ScavTrap.hpp"


ScavTrap::ScavTrap(std::string name): ClapTrap(name, 100, 50, 20)
{
	this->GateKeepMode = false;
	std::cout << "Im a ScavTrap. Cool!" <<std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &scavTrap): ClapTrap(scavTrap)
{
	this->GateKeepMode = false;
	std::cout << "Im a ScavTrap. Cool!" <<std::endl;
}

ScavTrap::ScavTrap(): ClapTrap("defaultScavTrap", 100, 100, 30)
{
	this->GateKeepMode = false;
	std::cout << "Im a ScavTrap. Cool!" <<std::endl;
}

ScavTrap& ScavTrap::operator=(ScavTrap const &scavTrap)
{
	this->Energy_Points = scavTrap.get_energy_points();
	this->Attack_damage = scavTrap.get_attack_damage();
	this->Hit_Points = scavTrap.get_hit_points();

	return *this;
}


ScavTrap::~ScavTrap(void)
{
	std::cout << "Im a ScavTrap. I am also dead." <<std::endl;
}

void		ScavTrap::attack(const std::string& target)
{
	if (this->get_energy_points() <= 0)
		std::cout << this->get_name() << "can't attack, no Energy points left!" << std::endl;
	else
	{
		std::cout << this->get_name()
					<< " attacked " << target
					<< " causing " << this->get_attack_damage()
					<< " points of damage! (From ScavTrap)" << std::endl;
		this->Energy_Points --;
	}
}

void	ScavTrap::guardGate(void)
{
	std::cout << "Im a ScavTrap. A GateKeeping scavTrap." <<std::endl;
	this->GateKeepMode = true;
}