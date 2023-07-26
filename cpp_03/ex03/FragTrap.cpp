#include "FragTrap.hpp"



FragTrap::FragTrap(std::string name): ClapTrap(name, 100, 100, 30)
{
	std::cout << "Im a FragTrap. woo-hoo!" <<std::endl;
}

FragTrap::FragTrap(): ClapTrap()
{
	this->Hit_Points = 100;
	this->Energy_Points = 100;
	this->Attack_damage = 30;
	std::cout << "Im a FragTrap. woo-hoo!" << std::endl;
};


FragTrap::~FragTrap(void)
{
	std::cout << "Im a FragTrap. Well, Was a Fragtrap." <<std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "High Five! (pls?)" <<std::endl;
}