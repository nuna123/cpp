#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30)
{
	std::cout << "Im a FragTrap. woo-hoo!" <<std::endl;
}

FragTrap::FragTrap(FragTrap const &fragTrap): ClapTrap(fragTrap)
{
	std::cout << "Im a FragTrap. woo-hoo!" <<std::endl;
}

FragTrap::FragTrap(): ClapTrap("defaultFragTrap", 100, 100, 30)
{
	std::cout << "Im a FragTrap. woo-hoo!" << std::endl;
};

FragTrap& FragTrap::operator=(FragTrap const &fragTrap)
{
	this->Energy_Points = fragTrap.get_energy_points();
	this->Attack_damage = fragTrap.get_attack_damage();
	this->Hit_Points = fragTrap.get_hit_points();

	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "Im a FragTrap. Well, Was a Fragtrap." <<std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High Five! (pls?)" <<std::endl;
}