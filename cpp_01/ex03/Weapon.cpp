#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type)
{
	this->setType(weapon_type);
}

const std::string& Weapon::getType()
{
	return this->type;
}

void	Weapon::setType(std::string new_type)
{
	this->type = new_type;
}

