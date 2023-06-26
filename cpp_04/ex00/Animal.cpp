#include "polymorphism.hpp"

using namespace std;


Animal::Animal (void) : type(""), my_sound("um...animal sound") {cout << "Animal created!\n";}
Animal::Animal (string s_type) : type(s_type), my_sound("um...animal sound") {cout << "Animal {"<< s_type <<"} created!\n";}
Animal::~Animal (void){cout << "Animal destroyed!\n";}
Animal::Animal(const Animal &animal_cpy) : type(animal_cpy.get_type()){cout << "Animal created!\n";}
Animal &Animal::operator = (const Animal &animal_cpy) {this->type = animal_cpy.get_type(); my_sound = "um...animal sound"; cout << "Animal created!\n"; return *this;}

string Animal::get_type(void) const {return this->type;}
void Animal::make_sound(void) const {cout << this->my_sound <<"\n";}