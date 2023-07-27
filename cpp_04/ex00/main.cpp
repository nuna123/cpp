#include "Animal.hpp"

#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
int main (void)
{

	Animal animal;
	Dog dog;
	Cat cat;
	std::cout << std::endl;
	animal.make_sound();
	dog.make_sound();
	cat.make_sound();
	std::cout<< std::endl << "------------WRONGANIMAL: " << std::endl;
	WrongCat badCat;

	badCat.make_sound();

		std::cout << std::endl;
	std::cout << std::endl;

	return 0;
}