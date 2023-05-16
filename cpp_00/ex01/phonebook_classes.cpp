#include "phonebook_classes.hpp"

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

void PhoneBook::add_contact(Contact contact)
{
	int	i;

	i = 0;
	while (i < PHONEBOOK_LIM && this->contacts[i].exists == 1)
		i++;
	i %= PHONEBOOK_LIM;
	this->contacts[i] = contact;
	this->contacts[i].exists = 1;
	this->contacts[i].index = i;
}

static void print_val(std::string val)
{
	if (val.length() > 10)
	{
		std::cout.write (val.c_str(), 9);
		std::cout << ".|";
	}
	else
		std::cout << std::setw(10) << val << "|";
}

void PhoneBook::print_contacts(void)
{
	int i = -1;
	while (++i < PHONEBOOK_LIM && this->contacts[i].exists == 1)
	{
		std::cout << std::setw(10) << this->contacts[i].index << "|";
		print_val (this->contacts[i].first_name);
		print_val (this->contacts[i].last_name);
		print_val (this->contacts[i].nickname);
		print_val (this->contacts[i].number);
		std::cout << std::endl;

	}
}
