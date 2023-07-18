#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{

		Weapon Bobs_club = Weapon("crude spiked club");

		HumanA bob("Bob", Bobs_club);
		bob.attack();
		Bobs_club.setType("some other type of club");
		bob.attack();

		Weapon Jims_club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(Jims_club);
		jim.attack();
		Jims_club.setType("some other type of club");
		jim.attack();


	return 0;
}