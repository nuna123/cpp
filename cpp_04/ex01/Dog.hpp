#ifndef DOG_HPP
#define DOG_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Dog: public Animal
{
	private:
		Brain *brain;

	public:
		Dog();
		~Dog();
		Dog(const Dog &dog);
		Dog &operator=(const Dog &dog);
		void		make_sound(void) const;
		const Brain	&get_brain(void) const;

};

#endif