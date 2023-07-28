#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal (void) : type("") {std::cout << "WrongAnimal created!" << std::endl;}
WrongAnimal::WrongAnimal (std::string s_type) : type(s_type) {std::cout << "WrongAnimal of type ["<< s_type <<"] created!" << std::endl;}
WrongAnimal::~WrongAnimal (void){std::cout << "WrongAnimal destroyed!" << std::endl;}
WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal_cpy) : type(WrongAnimal_cpy.get_type()){std::cout << "WrongAnimal created!" << std::endl;}
WrongAnimal &WrongAnimal::operator = (const WrongAnimal &WrongAnimal_cpy) {this->type = WrongAnimal_cpy.get_type(); std::cout << "WrongAnimal created!" << std::endl; return *this;}

std::string WrongAnimal::get_type(void) const {return this->type;}

void WrongAnimal::make_sound(void) const
{
	std::cout << "WrongAnimal Sound!" << std::endl;
}