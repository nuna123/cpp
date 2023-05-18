#include "Zombie.hpp"
#include <iostream>
#include <iomanip>
#include <string>

Zombie* newZombie( std::string name )
{
	Zombie *zz_the_zombie = new Zombie(name.c_str());
	return zz_the_zombie;
}

void randomChump( std::string name )
{
	Zombie zz_the_zombie(name.c_str());
	zz_the_zombie.announce();
}

int main(void)
{
	// const char	*name_char = "zombie 1";
	std::string	name_str = "zombie 2";

	Zombie	*zombie1 =  newZombie(name_str);
	zombie1->announce();
	zombie1->~Zombie();
	
	

	randomChump("random_Zombie");

	return 0;
}