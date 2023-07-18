#include "Harl.hpp"
#include <iostream>



int	main(int argc, char **argv)
{
	if (argc != 2)
		return (std::cout << "Give Harl something to do! [DEBUG/INFO/WARNING/ERROR]" << std::endl, 1);
	Harl harl;
	harl.complain(argv[1]);
	return 0;
}