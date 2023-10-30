#include "Intern.hpp"

// Constructors
Intern::Intern()
{
	std::cout << "\e[0;33mDefault Constructor called of Intern\e[0m" << std::endl;
}

Intern::Intern(const Intern &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of Intern\e[0m" << std::endl;
}


// Destructor
Intern::~Intern()
{
	std::cout << "\e[0;31mDestructor called of Intern\e[0m" << std::endl;
}


// Operators
Intern & Intern::operator=(const Intern &assign)
{
	(void) assign;
	return *this;
}

//EXCEPTION
const char *Intern::InvalidFormException::what() const throw ()
{return("\e[0;31mInvalid Form Type!\e[0m");};

//METHOD

AForm	*Intern::makeForm(std::string form_name, std::string target)
{

	std::string	simplified_name = "";
	std::string form_types[] =
		{"presidentialpardon", "shrubberycreation", "robotomyrequest"};
	
	AForm	*forms[] =
		{new PresidentialPardonForm(target),
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target)};

 	AForm	*ret;

	for (long unsigned int x = 0; x < form_name.length(); x++)
		if (isalpha(form_name[x])&& !isblank(form_name[x]))
			simplified_name += tolower(form_name[x]);

	for(int i = 0; i < 3; i++)
	{
		if (form_types[i] == simplified_name)
			ret = forms[i];
		else
			delete(forms[i]);
	}
	if (ret)
		return ret;
	throw Intern::InvalidFormException();
	return NULL;
}
