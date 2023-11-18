#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./Intern.hpp"


int main(void)
{
	Intern	joe;
	AForm	*form;

		std::cout << std::endl <<std::endl;

	try
	{
		// options: robotomy request, presidential pardon, shrubbery creation
		// form = joe.makeForm("some unexisting pardon", "bb");

		form = joe.makeForm("RobotomyRequest", "bb");

		std::cout <<"---------------------------" << std::endl;
		std::cout << *form;
		std::cout <<"---------------------------" << std::endl;

		delete form;

	}
	catch(const std::exception& e)
	{
		std::cout <<"---------------------------" << std::endl;
		std::cout <<"Error in main: " << e.what() << std::endl;
	}
	std::cout <<"---------------------------" << std::endl;

// std::cout << std::endl <<std::endl;

	return 0;
}