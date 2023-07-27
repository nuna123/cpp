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

	Animal *arr[10];

	for (int i = 0; i < 10; i++)
	{
		if (i < 5)
			arr[i] = new Dog;
		else
			arr[i] = new Cat;
	}
std::cout << std::endl;

	for (int i = 0; i < 10; i++)
	{
		std::cout << arr[i]->get_type() << " - ";
		std::cout << &(arr[i]) << std::endl;
	}

std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		delete(arr[i]);

	return 0;
}