/*
	Exception form from:
		https://rollbar.com/blog/cpp-custom-exceptions/

*/

#include "./Bureaucrat.hpp"

int main(void)
{
	Bureaucrat joe("Joe", 1);
	std::cout << joe<< std::endl<< std::endl;

	try
	{
		joe.gradeUp();
		std::cout << joe<< std::endl<< std::endl;

	} catch (std::exception & e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}


	try
	{
		joe.gradeDown();
		std::cout << joe<< std::endl<< std::endl;

	} catch (std::exception & e)
	{
		std::cout << "exception: " << e.what() << std::endl;
	}



	return 0;
}