#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog(): Animal("Dog"), brain(new Brain("woofyIdea"))
{
	std::cout << "dog constructor called!\n";
}

Dog::Dog(const Dog &dog_cpy): Animal(dog_cpy)
{
	// delete(this->brain);
	this->brain = new Brain(dog_cpy.get_brain());
	std::cout << "dog copy constructor called!\n";
}


Dog::~Dog()
{
	delete(this->brain);
	std::cout << "dog destructor called!\n";
}

Dog &Dog::operator=(const Dog &dog)
{
	this->type = dog.get_type();
	delete(this->brain);
	this->brain = new Brain(dog.get_brain());

	return *this;
}
void Dog::make_sound(void) const
{
	std::cout << "Bark!" << std::endl;
}
const Brain	&Dog::get_brain(void) const
{
	return *(this->brain);
}