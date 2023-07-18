#include <iostream>
#include <string>
#include <cstdlib>
#include <cstdio>


int	main(void)
{
	std::string	string = "HI THIS IS BRAIN";
	std::string	*stringPTR = &string;
	std::string	&stringREF = string;

	std::cout	<<	"string address: " << &string
				<< "\nstringPTR address: " << &stringPTR
				<< "\nstringREF address: " << &stringREF
				<< std::endl;

	std::cout	<< "\nstring value: " << string
				<< "\nstringPTR value: " << *stringPTR
				<< "\nstringREF value: " << stringREF
				<< std::endl;

	return (0);
}