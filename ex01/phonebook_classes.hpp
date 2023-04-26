#include <iostream>
#include <iomanip>
#include <cstdlib>

#ifndef PHONEBOOK_CLASSES_H
# define PHONEBOOK_CLASSES_H

# define PHONEBOOK_LIM 2
class Contact {
	public:
		int			exists;
		int			index;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	number;

		void print_contact ();
};

class PhoneBook {
	public:
		Contact contacts[PHONEBOOK_LIM];
		void add_contact(Contact contact);
		void print_contacts (void);

};

#endif