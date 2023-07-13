#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include <iostream>
#include <iomanip>
#include <cstdlib>

#include "Contact.hpp"

# define PHONEBOOK_LIM 2

class PhoneBook {
	public:
		Contact contacts[PHONEBOOK_LIM];
		void add_contact(Contact contact);
		void print_contacts (void);

};

#endif