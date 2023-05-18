#include "Zombie.hpp"

#include <iostream>
#include <iomanip>

void	Zombie::announce (void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie (const char *name)
{
	this->name = name;
}

Zombie::~Zombie (void)
{
	std::cout << this->name << ": Goodbye cruel world!" << std::endl;
}