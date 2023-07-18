#include "Zombie.hpp"
#include <iostream>
#include <iomanip>
#include <string>

Zombie* newZombie( std::string name )
{
	Zombie *zz_the_zombie = new Zombie(name);
	return zz_the_zombie;
}

void randomChump( std::string name )
{
	Zombie zz_the_zombie(name);
	zz_the_zombie.announce();
}

int main(void)
{
	std::string	name_str = "Bernard";

	std::cout << "\n\tcreating a zombie from randomChump() func. allocating on the stack." << std::endl;

	randomChump("Tony");

	std::cout << "\n\tcreating a zombie from newZombie() func. allocating on the heap." << std::endl;
	Zombie	*zombie1 =  newZombie(name_str);
	zombie1->announce();

	std::cout << "\n\tDone with zombies! Deleting " << name_str << std::endl;
	delete (zombie1);



	return 0;
}