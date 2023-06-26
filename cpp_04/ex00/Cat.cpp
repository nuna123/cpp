#include "polymorphism.hpp"

using namespace std;

Cat::Cat(): Animal("cat")
{
	my_sound = "meow!";
	std::cout << "cat constructor called!\n";
}

Cat::Cat(const Cat &cat_cpy): Animal("cat")
{
	(void) cat_cpy;
	my_sound = "meow!";
	std::cout << "cat copy constructor called!\n";
}


Cat::~Cat(){std::cout << "cat destructor called!\n";}