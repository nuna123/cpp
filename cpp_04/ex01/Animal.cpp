#include "Animal.hpp"
#include <iostream>


Animal::Animal (void) : type("") {std::cout << "Animal created!" << std::endl;}
Animal::Animal (std::string s_type) : type(s_type) {std::cout << "Animal of type ["<< s_type <<"] created!" << std::endl;}
Animal::~Animal (void){std::cout << "Animal destroyed!" << std::endl;}
Animal::Animal(const Animal &animal_cpy) : type(animal_cpy.get_type()){std::cout << "Animal created!" << std::endl;}
Animal &Animal::operator = (const Animal &animal_cpy) {this->type = animal_cpy.get_type(); std::cout << "Animal created!" << std::endl; return *this;}

std::string Animal::get_type(void) const {return this->type;}

void Animal::make_sound(void) const
{
	std::cout << "Animal Sound!" << std::endl;
}
/* void Animal::make_sound(void) const
{
	if (this->get_type() == "Cat")
		std::cout << "Meow!" << std::endl;
	else if (this->get_type() == "Dog")
		std::cout << "Bark!" << std::endl;
	else
		std::cout << "Animal Sound!" << std::endl;
} */