
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal();
		WrongAnimal(std::string	type);
		~WrongAnimal();
		WrongAnimal(const WrongAnimal &animal_cpy);
		WrongAnimal &operator = (const WrongAnimal &animal_cpy);

		std::string get_type() const;
		void make_sound() const;
};

#endif