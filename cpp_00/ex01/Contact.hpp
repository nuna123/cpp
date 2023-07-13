#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <iomanip>
#include <cstdlib>

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

#endif