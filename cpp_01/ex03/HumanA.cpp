#include "HumanA.hpp"


//initializer list (: weapon(weapon))
	// used to intialise data members of a class,
	// has to be used for initialization of reference members

HumanA::HumanA (std::string name, Weapon &weapon) : name(name), weapon(weapon){};


void HumanA::attack(void)
{
	std::cout	<< this->name
				<< " attacks with their "
				<< this->weapon.getType()
				<< std::endl;
}
