#include "Harl.hpp"

int	Harl_complaint_level(char *argv)
{
	std::string	level_strs[4] = {"DEBUG","INFO","WARNING","ERROR"};

	if (!argv)
		return -1;

	for (int i = 0; i < 4; i++)
	{
		if (argv == level_strs[i])
			return i;
	}
	return -1;
}

void harl_complain (Harl &harl, int level)
{
	switch (level)
	{
		case -1:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
		case 0:
			std::cout << "[DEBUG]" << std::endl;
			harl.complain("DEBUG");
			std::cout << std::endl;
		case 1:
			std::cout << "[INFO]" << std::endl;
			harl.complain("INFO");
			std::cout << std::endl;
		case 2:
			std::cout << "[WARNING]" << std::endl;
			harl.complain("WARNING");
			std::cout << std::endl;
		case 3:
			std::cout << "[ERROR]" << std::endl;
			harl.complain("ERROR");
			std::cout << std::endl;

	}

}

int	main(int argc, char *argv[])
{
	Harl		harl;

	if (argc != 2)
		return(std::cout << "smh not like that" << std::endl, 1);

	harl_complain(harl, Harl_complaint_level(argv[1]));

	return 0;
}