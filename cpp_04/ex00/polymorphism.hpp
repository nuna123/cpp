#ifndef POLYMORPHISM_H
#define POLYMORPHISM_H

#include <iostream>

class Animal
{
	protected:
		std::string	type;
		std::string	my_sound;

	public:
		Animal();
		Animal(std::string	type);
		~Animal();
		Animal(const Animal &animal_cpy);
		Animal &operator = (const Animal &animal_cpy);

		std::string get_type() const;
		void make_sound() const;
};

class Cat: public Animal
{
	public:
		Cat();
		~Cat();
		Cat(const Cat &cat);
		// Cat &operator=(const Cat &cat); //is inherited by Animal class
};

class Dog: public Animal
{
	public:
		Dog();
		~Dog();
		Dog(const Dog &dog);
		// Dog &operator=(const Dog &dog); //is inherited by Animal class
};

#endif
////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////		INFO	////////////////////////////////////////////
/*
	In C++, derived classes cannot inherit the constructors of their base classes
	-- nor can they inherit assignment operators.

	MEMBER MODES:
			ex:
				PUBLIC:
					string	type;
		Public:
				When the member is declared as public, it is accessible to all the functions of the program.
		Private:
				When the member is declared as private, it is accessible within the class only.
		Protected:
				When the member is declared as protected, it is accessible within its own class (like private members)
				as well as the class immediately derived from it.

	INHERITENCE MODES
			ex:
				class car: PRIVATE Vhicle{}; // class car privately inherits from class Vhicle
		Public Mode:
			PUBLIC members become PUBLIC in the derived class.
			PROTECTED members become PROTECTED.
		Protected mode:
			PUBLIC => PROTECTED
			PROTECTED => PROTECTED
		private mode:
			PUBLIC => PRIVATE
			PROTECTED => PRIVATE
		******PRIVATE MEMBERS ARE NEVER INHERITED******
		******CONSTRUCTORS AND DESTRUCTORS ARE NOT INHERITED******

*/
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
