#include "Contact.hpp"

void Contact::print_contact ()
{
	std::cout << "\t-----------------------" << std::endl;
	std::cout << "\tIndex: " << this->index<< std::endl;
	std::cout << "\tFirst Name: " << this->first_name<< std::endl;
	std::cout << "\tLast Name: " << this->last_name<< std::endl;
	std::cout << "\tNickname: " << this->nickname<< std::endl;
	std::cout << "\tPhone Number: " << this->number<< std::endl;
	std::cout << "\t-----------------------" << std::endl;

}