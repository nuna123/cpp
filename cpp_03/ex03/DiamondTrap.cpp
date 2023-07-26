#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name")
{
	this->Name = "default";
	this->Hit_Points = FragTrap::Hit_Points;
	this->Energy_Points = ScavTrap::Energy_Points;
	this->Attack_damage = ScavTrap::Attack_damage;

	std::cout << ScavTrap::Attack_damage << " -- DiamondTrap Default Constructor called" << std::endl;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}