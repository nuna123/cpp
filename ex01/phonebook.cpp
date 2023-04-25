#include "phonebook.hpp"

using namespace std;

void	add_contact (PhoneBook *phone_book)
{
	Contact	contact;
	string	first_name;
	string	last_name;
	string	nickname;
	string	number;


	cout << "\tFirst Name : ";
		cin >> first_name;
	cout << "\tLast Name : ";
		cin >> last_name;
	cout << "\tNickname : ";
		cin >> nickname;
	cout << "\tPhone Number : ";
		cin >> number;
	contact.set_contact (first_name, last_name, nickname, number);
	cout << "\tDarkest Secret : ";
		cin >> first_name;
	phone_book->add_contact(contact);
}


int main(void)
{
	PhoneBook	pb;
	string		cmd;

	while (1)
	{
		cout << "Command : ";
		cin >> cmd;
		if (cmd == "ADD")
			add_contact(&pb);
		else if (cmd == "PRINT")
			pb.print_contacts();
		else if (cmd == "EXIT")
			break;
	}
	

	return 0;
}