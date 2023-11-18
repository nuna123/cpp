#include "PresidentialPardonForm.hpp"

// Constructors
PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target)
{
	std::cout << "\e[0;33mConstructor called of PresidentialPardonForm\e[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy): AForm(copy), _target(copy.get_target())
{
	std::cout << "\e[0;33mCopy Constructor called of PresidentialPardonForm\e[0m" << std::endl;
}


// Destructor
PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "\e[0;31mDestructor called of PresidentialPardonForm\e[0m" << std::endl;
}


// Operators
PresidentialPardonForm & PresidentialPardonForm::operator=(const PresidentialPardonForm &assign)
{
	// (void) assign;
	AForm::operator=(assign);
	this->_target = assign.get_target();
	return *this;
}

//getter

std::string PresidentialPardonForm::get_target() const
{
	return this->_target;
}

//methods
void PresidentialPardonForm::my_action() const
{
	std::cout << this->get_target() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}