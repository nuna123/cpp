#include "./Bureaucrat.hpp"
#include "./Form.hpp"

int main(void)
{
	try
	{
		Form	*importantForm = new Form("importntForm",10, 3);
		Bureaucrat *joe = new Bureaucrat("joe", 100);

		std::cout << *joe<< std::endl<< std::endl;
		std::cout << *importantForm<< std::endl<< std::endl;
		

		joe->signForm(*importantForm);
		delete joe;
		delete importantForm;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}