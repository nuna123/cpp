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
	std::string	name_str = "Bernard";


	std::cout << "\tcreating a zombie from newZombie() func. allocating on the heap." << std::endl;
	Zombie	*zombie1 =  newZombie(name_str);
	zombie1->announce();
	delete (zombie1);


	std::cout << "\tcreating a zombie from randomChump() func. allocating on the stack." << std::endl;

	randomChump("Tony");

	return 0;
}