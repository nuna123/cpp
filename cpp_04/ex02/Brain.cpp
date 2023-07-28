#include "Brain.hpp"

Brain::Brain()
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "!";
	std::cout << "Brain Created!" << std::endl;
}
Brain::Brain(Brain const &brain)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.get_idea(i);
	std::cout << "Brain Created!" << std::endl;
}
Brain::Brain(std::string idea)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = idea;
	std::cout << "Brain Created!" << std::endl;
}

Brain::~Brain(){std::cout << "Brain Destroyed :(" << std::endl;}

Brain &Brain::operator=(Brain const &brain)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = brain.get_idea(i);
	return *this;
}

const std::string Brain::get_idea(int index) const
{
	if (index < 0 || index > 99)
		return NULL;
	return this->ideas[index];
}