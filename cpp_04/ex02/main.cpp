#include "Animal.hpp"

#include "Cat.hpp"
#include "Dog.hpp"

#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

/* int main (void)
{
	Dog dog;

	std::cout << std::endl;

	dog.make_sound();
	std::cout << "Dog->brain->idea : "<< dog.get_brain().get_idea(33) << std::endl;

	std::cout << std::endl;

	return 0;
} */

int main (void)
{
	{
		Cat cat_one;
		Cat cat_cpy;

		std::cout << std::endl;
		std::cout << std::endl;

			std::cout << "Cat one: " << &cat_one << std::endl;
			std::cout << "Cat cpy: " << &cat_cpy << std::endl;
		cat_cpy = cat_one;
		std::cout << std::endl<< std::endl;

			std::cout << "Cat one: " << &cat_one << std::endl;
			std::cout << "Cat cpy: " << &cat_cpy << std::endl;



	}
		std::cout << std::endl << std::endl;
	{
		Cat cat_one;
		Cat cat_cpy(cat_one);

		std::cout << std::endl;
		std::cout << std::endl;

			std::cout << "Cat one: " << &cat_one << std::endl;
			std::cout << "Cat cpy: " << &cat_cpy << std::endl;
		cat_cpy = cat_one;
		std::cout << std::endl<< std::endl;

			std::cout << "Cat one: " << &cat_one << std::endl;
			std::cout << "Cat cpy: " << &cat_cpy << std::endl;



	}
		std::cout << std::endl << std::endl;

	int arrlen = 2;
	Animal *arr[arrlen];

	for (int i = 0; i < arrlen; i++)
	{
		if (i < (arrlen / 2))
			arr[i] = new Dog;
		else
			arr[i] = new Cat;
	}
	
	std::cout << std::endl;

	for (int i = 0; i < arrlen; i++)
	{
		std::cout << arr[i]->get_type() << " - ";
		std::cout << &(arr[i]) << std::endl;
	}

std::cout << std::endl;

	for (int i = 0; i < arrlen; i++)
		delete(arr[i]);

	return 0;
}