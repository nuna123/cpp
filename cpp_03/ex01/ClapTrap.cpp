#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: Name(name), Hit_Points(10), Energy_Points(10), Attack_damage(0)
{
	std::cout << "ClapTrap constructor called. Hello world!" << std::endl;
}

ClapTrap::ClapTrap(std::string name, int hitpoints, int energy_points, int attack_damage)
{
	std::cout << "ClapTrap constructor called. Hello world!" << std::endl;

	this->Name = name;
	this->Hit_Points = hitpoints;
	this->Energy_Points = energy_points;
	this->Attack_damage = attack_damage;
}

ClapTrap::ClapTrap(const ClapTrap &clap_trap)
	:	Name(clap_trap.get_name()), Hit_Points(clap_trap.get_hit_points()),
		Energy_Points(clap_trap.get_energy_points()), Attack_damage(clap_trap.get_attack_damage())
{
	std::cout << "ClapTrap constructor called. Hello world!" << std::endl;
}

ClapTrap::ClapTrap(void)
	: Name("default_clapTrap"), Hit_Points(10), Energy_Points(10), Attack_damage(0)
{std::cout << "Default constructor called. Hello world!" << std::endl;}

ClapTrap& ClapTrap::operator=(const ClapTrap &clap_trap)
{
	this->Name = clap_trap.get_name();
	this->Hit_Points = clap_trap.get_hit_points();
	this->Energy_Points = clap_trap.get_energy_points();
	this->Attack_damage = clap_trap.get_attack_damage();

	std::cout << "ClapTrap constructor called. Hello world!" << std::endl;
	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called. Goodbye cruel world!" << std::endl;
}


void		ClapTrap::attack(const std::string& target)
{
	if (this->get_energy_points() <= 0)
		std::cout << this->get_name() << "can't attack, no Energy points left!" << std::endl;
	else
	{
		std::cout << this->get_name()
					<< " attacked " << target
					<< " causing " << this->get_attack_damage()
					<< " points of damage!" << std::endl;
		this->Energy_Points --;
	}
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	Hit_Points -= amount;
	if (Hit_Points < 0)
		Hit_Points = 0;
	std::cout	<< this->get_name() << " took "<< amount << " damage. Ouch! "
				<< this-> get_hit_points() << " hitpoints left." << std::endl;

}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (this->get_energy_points() <= 0)
		std::cout << this->get_name() << "can't be repaired, no Energy points left!" << std::endl;
	else
	{
		this->Energy_Points --;
		this->Hit_Points += amount;
		std::cout << this->get_name() << " got repaired. Recieved " << amount << " more hit points!" << std::endl;
	}

}


std::string	ClapTrap::get_name(void) const
	{return this->Name;}
int			ClapTrap::get_hit_points(void) const
	{return this->Hit_Points;}
int			ClapTrap::get_energy_points(void) const
	{return this->Energy_Points;}
int			ClapTrap::get_attack_damage(void) const
	{return this->Attack_damage;}


void ClapTrap::stats(void)
{
	std::cout	<< "\tName: " << this->Name << std::endl
				<< "\tHit Points: " << this->Hit_Points << std::endl
				<< "\tEnergy Points: " << this->Energy_Points << std::endl
				<< "\tAttack Damage: " << this->Attack_damage << std::endl;
}
