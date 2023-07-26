#include "Contact.hpp"
#include "PhoneBook.hpp"

void	add_contact (PhoneBook *phone_book)
{
	Contact	contact;
	std::string	secret;

	std::cout << "\tFirst Name : ";
		std::cin >> contact.first_name;
	std::cout << "\tLast Name : ";
		std::cin >> contact.last_name;
	std::cout << "\tNickname : ";
		std::cin >> contact.nickname;
	std::cout << "\tPhone Number : ";
		std::cin >> contact.number;
	std::cout << "\tDarkest Secret : ";
		std::cin >> secret;
	phone_book->add_contact(contact);
}

void	search_contacts (PhoneBook phone_book)
{
	int index_i;
	std::string index_s;

	if (phone_book.contacts[0].exists != 1)
	{
		std::cout << "NO CONTACTS! get some friends!" << std::endl;
		return;
	}
	std::cout << "\n";
	phone_book.print_contacts();
	std::cout << "\n\tContact index : ";
	std::cin >> index_s;
	index_i = atoi(index_s.c_str());

	if ((index_i == 0 && index_s.c_str()[0] != '0')
		|| index_i < 0
		|| index_i > PHONEBOOK_LIM
		|| phone_book.contacts[index_i].exists != 1)
		std::cout << "Your index sucks!" << std::endl;
	else
		phone_book.contacts[index_i].print_contact();
}

int main(void)
{
	PhoneBook	pb;
	std::string		cmd;
	Contact		contact;

	contact.exists = 0;
	for (int i = 0; i < PHONEBOOK_LIM; i++)
		pb.contacts[i] = contact;

	while (1)
	{
		std::cout << "Command [SEARCH/ADD/EXIT]: ";
		std::cin >> cmd;
		if (cmd == "ADD")
			add_contact(&pb);
/* 		else if (cmd == "PRINT")
			pb.print_contacts(); */
		else if (cmd == "SEARCH")
			search_contacts(pb);
		else if (cmd == "EXIT")
			break;
	}

	return 0;
}