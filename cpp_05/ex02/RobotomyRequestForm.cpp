#include "RobotomyRequestForm.hpp"

// Constructors
RobotomyRequestForm::RobotomyRequestForm(std::string target)
	:AForm("RobotomyRequestForm", 72, 45),  _target(target)
{
	std::cout << "\e[0;33mDefault Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy): AForm(copy), _target(copy.get_target())
{
	std::cout << "\e[0;33mCopy Constructor called of RobotomyRequestForm\e[0m" << std::endl;
}


// Destructor
RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "\e[0;31mDestructor called of RobotomyRequestForm\e[0m" << std::endl;
}


// Operators
RobotomyRequestForm & RobotomyRequestForm::operator=(const RobotomyRequestForm &assign)
{
	this->_target = assign.get_target();
	return *this;
}

//getter

std::string RobotomyRequestForm::get_target() const
{
	return this->_target;
}

//methods
void RobotomyRequestForm::my_action()
{
	srand((unsigned) time(NULL));

	std::cout << " ** drilling noises... **"  << std::endl;
	if(std::rand() % 2 == 0)
	{
		std::cout <<
		"... " <<
		this->get_target() <<
		" has been robotomized successfully " << std::endl;
	}
	else
	{
		std::cout <<
		"...Robotomy Failed :(" << std::endl;
	}
}
