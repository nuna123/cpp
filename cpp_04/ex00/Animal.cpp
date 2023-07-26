#include "polymorphism.hpp"
#include <iostream>


Animal::Animal (void) : type(""), my_sound("um...animal sound") {std::cout << "Animal created!\n";}
Animal::Animal (std::string s_type) : type(s_type), my_sound("um...animal sound") {std::cout << "Animal {"<< s_type <<"} created!\n";}
Animal::~Animal (void){std::cout << "Animal destroyed!\n";}
Animal::Animal(const Animal &animal_cpy) : type(animal_cpy.get_type()){std::cout << "Animal created!\n";}
Animal &Animal::operator = (const Animal &animal_cpy) {this->type = animal_cpy.get_type(); my_sound = "um...animal sound"; std::cout << "Animal created!\n"; return *this;}

std::string Animal::get_type(void) const {return this->type;}
void Animal::make_sound(void) const {std::cout << this->my_sound <<"\n";}