#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(): Animal("Cat"), brain(new Brain("cat"))
{
	std::cout << "cat constructor called!\n";
}

Cat::Cat(const Cat &cat): Animal(cat)
{
	this->brain = new Brain(cat.get_brain());
	std::cout << "dog copy constructor called!\n";
}


Cat::~Cat()
{
	delete(this->brain);
	std::cout << "dog destructor called!\n";
}

Cat &Cat::operator=(const Cat &dog)
{
	this->type = dog.get_type();
	this->brain = new Brain(dog.get_brain());

	return *this;
}
void Cat::make_sound(void) const
{
	std::cout << "Bark!" << std::endl;
}
const Brain	&Cat::get_brain(void) const
{
	return *(this->brain);
}