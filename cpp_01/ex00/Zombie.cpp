#include "Zombie.hpp"

#include <iostream>
#include <iomanip>

void	Zombie::announce (void)
{
	std::cout << this->name.c_str()  << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie (std::string	name)
{
	this->name = name;
}

Zombie::~Zombie (void)
{
	std::cout << this->name.c_str() << ": Goodbye cruel world!" << std::endl;
}