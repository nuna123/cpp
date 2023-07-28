#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal("WrongCat")
{
	std::cout << "WrongCat constructor called!\n";
}

WrongCat::WrongCat(const WrongCat &cat_cpy): WrongAnimal(cat_cpy)
{
	std::cout << "WrongCat copy constructor called!\n";
}


WrongCat::~WrongCat(){std::cout << "WrongCat destructor called!\n";}

WrongCat &WrongCat::operator=(const WrongCat &WrongCat)
{
	this->type = WrongCat.get_type();
	return *this;
}
