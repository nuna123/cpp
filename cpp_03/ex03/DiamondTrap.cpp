#include "DiamondTrap.hpp"


void DiamondTrap::init()
{
	FragTrap temp_frag;
	ScavTrap temp_scav;

	this->ClapTrap::Name = this->DiamondTrap::Name + "_clap_name";
	this->Hit_Points = temp_frag.get_hit_points();
	this->Energy_Points = temp_scav.get_energy_points();
	this->Attack_damage = temp_scav.get_attack_damage();

}

DiamondTrap::DiamondTrap(DiamondTrap const &diamondTrap): ClapTrap(diamondTrap)
{
	this->DiamondTrap::Name = diamondTrap.get_diamond_name();
	init();
}
DiamondTrap& DiamondTrap::operator=(DiamondTrap const &diamondTrap)
{
	this->DiamondTrap::Name = diamondTrap.get_diamond_name();
	this->ClapTrap::Name = diamondTrap.get_diamond_name() + "_clap_trap";
	this->Energy_Points = diamondTrap.get_energy_points();
	this->Hit_Points = diamondTrap.get_hit_points();
	this->Attack_damage = diamondTrap.get_attack_damage();

	return *this;
}
DiamondTrap::DiamondTrap(): ClapTrap()
{
	std::cout << "DiamondTrap Default Constructor called" << std::endl << std::endl;
	this->DiamondTrap::Name = "defaultDiamond";
	init();
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap()
{

	std::cout << "DiamondTrap Constructor called" << std::endl << std::endl;

	this->DiamondTrap::Name = name;
	init();

}
void DiamondTrap::whoAmI(void)
{
	std::cout	<< "\tDiamondTrap Name: " << this->DiamondTrap::Name << std::endl
				<< "\tClapTrap Name: " << this->ClapTrap::Name << std::endl;
}
std::string DiamondTrap::get_diamond_name(void) const
{
	return this->DiamondTrap::Name;
}

void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "A diamondTrap has died here today..." << std::endl;
}