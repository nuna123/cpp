#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type)
{
	this->setType(weapon_type);
}

Weapon::Weapon(const Weapon &weapon)
{
	this->setType(weapon.getType());
}

Weapon &Weapon::operator=(const Weapon &weapon)
{
	this->setType(weapon.getType());
	return *this;
}
Weapon::~Weapon(void)
{ return ;}




const std::string& Weapon::getType() const
{
	return this->type;
}

void	Weapon::setType(const std::string new_type)
{
	this->type = new_type;
}

