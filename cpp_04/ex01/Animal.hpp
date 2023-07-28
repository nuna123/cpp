#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	type;

	public:
		Animal();
		Animal(std::string	type);
		virtual ~Animal();
		Animal(const Animal &animal_cpy);
		Animal &operator = (const Animal &animal_cpy);

		std::string	get_type() const;
		void		make_sound() const;
};

#endif