//
//	https://www-stone.ch.cam.ac.uk/documentation/rrf/rpn.html
//

#include "RPN.hpp"

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		std::cerr
			<< "provide a Reverse Polish Notation mathematical expression. bitch."
			<< std::endl;
	}
	else if (argc > 2)
	{
		std::cerr
			<< "provide just one Reverse Polish Notation mathematical expression. bitch."
			<< std::endl;
	}
	else
	{
		try
		{
			// evaluate_expression(argv[1]);
			std::cout
			<< argv[1]
			<< " => "
			<< evaluate_expression(argv[1])
			<< std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << "ERROR! something went wrong:(" << std::endl;
		}
	}

	return 0;
}