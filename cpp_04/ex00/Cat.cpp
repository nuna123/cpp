#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "cat constructor called!\n";
}

Cat::Cat(const Cat &cat_cpy): Animal(cat_cpy)
{
	std::cout << "cat copy constructor called!\n";
}


Cat::~Cat(){std::cout << "cat destructor called!\n";}

Cat &Cat::operator=(const Cat &cat)
{
	this->type = cat.get_type();
	return *this;
}

void Cat::make_sound(void) const
{
	std::cout << "Meow!" << std::endl;
}