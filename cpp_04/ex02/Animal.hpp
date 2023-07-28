#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	type;

	public:

		virtual ~Animal() {};

		virtual std::string	get_type() const = 0;
		virtual void		make_sound() const = 0;
};

#endif