#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>

# include "./AForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./ShrubberyCreationForm.hpp"


class AForm;

class Intern
{
	public:
		// Constructors
		Intern();
		Intern(const Intern &copy);
		
		// Destructor
		~Intern();
		
		// Operators
		Intern & operator=(const Intern &assign);

		//exception
		class InvalidFormException : public std::exception
		{
			public:
				const virtual char *what() const throw ();
		};

		//method
		AForm	*makeForm(std::string form_name, std::string form_target);
		
	private:
		
};

#endif