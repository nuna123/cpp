#include "Zombie.hpp"


int main(void)
{
	int num = 5;
	Zombie *horde = zombieHorde(num, "Robert");

	for (int i = 0; i < num; i++)
	{
		std::cout << i << ": ";
		horde[i].announce();
	}

std::cout << "\tdeleting horde..." << std::endl;
	delete [] horde;

	return 0;
}