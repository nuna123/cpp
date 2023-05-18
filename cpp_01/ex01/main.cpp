#include "Zombie.hpp"


int main(void)
{
	int num = 5;
	Zombie *horde = zombieHorde(num, "Robert");

	for (int i = 0; i < num; i++)
	{
		horde[i].announce();
	}
		
	delete [] horde;

	return 0;
}