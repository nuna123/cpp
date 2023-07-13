#include "Contact.hpp"
#include "PhoneBook.hpp"

using namespace std;

void	add_contact (PhoneBook *phone_book)
{
	Contact	contact;
	string	secret;

	cout << "\tFirst Name : ";
		cin >> contact.first_name;
	cout << "\tLast Name : ";
		cin >> contact.last_name;
	cout << "\tNickname : ";
		cin >> contact.nickname;
	cout << "\tPhone Number : ";
		cin >> contact.number;
	cout << "\tDarkest Secret : ";
		cin >> secret;
	phone_book->add_contact(contact);
}

void	search_contacts (PhoneBook phone_book)
{
	int index_i;
	string index_s;

	if (phone_book.contacts[0].exists != 1)
	{
		cout << "NO CONTACTS! get some friends!" << endl;
		return;
	}
	cout << "\n";
	phone_book.print_contacts();
	cout << "\n\tContact index : ";
	cin >> index_s;
	index_i = atoi(index_s.c_str());

	if ((index_i == 0 && index_s.c_str()[0] != '0')
		|| index_i < 0
		|| index_i > PHONEBOOK_LIM
		|| phone_book.contacts[index_i].exists != 1)
		cout << "Your index sucks!" << endl;
	else
		phone_book.contacts[index_i].print_contact();
}

int main(void)
{
	PhoneBook	pb;
	string		cmd;
	Contact		contact;

	contact.exists = 0;
	for (int i = 0; i < PHONEBOOK_LIM; i++)
		pb.contacts[i] = contact;

	while (1)
	{
		cout << "Command [SEARCH/ADD/EXIT]: ";
		cin >> cmd;
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