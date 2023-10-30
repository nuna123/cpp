#include "./Bureaucrat.hpp"
#include "./AForm.hpp"
#include "./RobotomyRequestForm.hpp"
#include "./PresidentialPardonForm.hpp"
#include "./ShrubberyCreationForm.hpp"


int main(void)
{
	
	Bureaucrat	low_beau("Lowgrade Bur", 120);
	Bureaucrat	high_beau("Highgrade Bur", 1);

	PresidentialPardonForm	ppf("Moe");
	ShrubberyCreationForm	scf("home");
	RobotomyRequestForm		rrf("MoesWife");

		std::cout << std::endl <<std::endl;

	try
	{

		ppf.execute(high_beau);
		scf.execute(high_beau);
		rrf.execute(low_beau);


	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
		std::cout << std::endl <<std::endl;

	return 0;
}