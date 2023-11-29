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
		evaluate_expression(argv[1]);
	return 0;
}