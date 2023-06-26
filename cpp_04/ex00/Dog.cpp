#include "polymorphism.hpp"

using namespace std;

Dog::Dog(): Animal("dog")
{
	my_sound = "bark!";
	std::cout << "dog constructor called!\n";
}

Dog::Dog(const Dog &dog_cpy): Animal("dog")
{
	(void) dog_cpy;
	my_sound = "bark!";
	std::cout << "dog copy constructor called!\n";
}


Dog::~Dog(){std::cout << "dog destructor called!\n";}