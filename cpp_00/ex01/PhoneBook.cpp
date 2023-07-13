#include "PhoneBook.hpp"

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
