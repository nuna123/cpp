#include "polymorphism.hpp"

using namespace std;

WrongAnimal::WrongAnimal (void) : type(""), my_sound("um...animal sound") {cout << "WrongAnimal created!\n";}
WrongAnimal::WrongAnimal (string s_type) : type(s_type), my_sound("um...animal sound") {cout << "WrongAnimal {"<< s_type <<"} created!\n";}
WrongAnimal::~WrongAnimal (void){cout << "WrongAnimal destroyed!\n";}
WrongAnimal::WrongAnimal(const WrongAnimal &animal_cpy) : type(animal_cpy.get_type()){cout << "WrongAnimal created!\n";}
WrongAnimal &WrongAnimal::operator = (const WrongAnimal &animal_cpy) {this->type = animal_cpy.get_type(); my_sound = "um...animal sound"; cout << "WrongAnimal created!\n"; return *this;}

string WrongAnimal::get_type(void) const {return this->type;}
void WrongAnimal::make_sound(void) const {cout << this->my_sound <<"\n";}