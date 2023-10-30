#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./ShrubberyCreationForm.hpp"
#include "./Intern.hpp"


int main(void)
{
	Intern joe;


		std::cout << std::endl <<std::endl;

	try
	{
		AForm *form = joe.makeForm("presitial pardon", "bb");
		std::cout << *form <<std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr <<"Error in main: " << e.what() << '\n';
	}
		std::cout << std::endl <<std::endl;
 
	return 0;
}