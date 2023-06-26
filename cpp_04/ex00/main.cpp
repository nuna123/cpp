#include "polymorphism.hpp"

int main (void)
{
/* 	Animal *animal = new Animal();

	delete(animal); */

/* 	Cat cat1;
	Dog duck;

	std::cout << "\n\n";
	duck.make_sound();

	return 0; */
const Animal* meta = new Animal();
const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->get_type() << " " << std::endl;
std::cout << i->get_type() << " " << std::endl;
i->make_sound(); //will output the cat sound!
j->make_sound();
meta->make_sound();

return 0;
}