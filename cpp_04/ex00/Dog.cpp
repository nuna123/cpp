#include "Dog.hpp"



Dog::Dog(): Animal("Dog")
{
	std::cout << "dog constructor called!\n";
}

Dog::Dog(const Dog &dog_cpy): Animal(dog_cpy)
{
	std::cout << "dog copy constructor called!\n";
}


Dog::~Dog(){std::cout << "dog destructor called!\n";}

Dog &Dog::operator=(const Dog &dog)
{
	this->type = dog.get_type();
	return *this;
}
void Dog::make_sound(void) const
{
	std::cout << "Bark!" << std::endl;
}