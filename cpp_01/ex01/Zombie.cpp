#include "Zombie.hpp"

#include <iostream>
#include <iomanip>

void	Zombie::announce (void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::set_name(char	*name)
{
	this->name = name;
}

Zombie::~Zombie (void)
{
	std::cout << this->name << ": Goodbye cruel world!" << std::endl;
}