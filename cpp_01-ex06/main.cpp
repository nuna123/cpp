#include "Harl.hpp"

int	main(int argc, char *argv[])
{
	Harl		harl;
	std::string	level_strs[4] = {"DEBUG","INFO","WARNING","ERROR"};

	if (argc != 2)
		return(std::cout << "smh not like that" << std::endl, 1);

	for (int level = 0; level < 4; level++)
	{
		if (argv[1] == level_strs[level])
		{
			for (int i = level; i < 4; i++)
			{
				std::cout << "[ " << level_strs[i] << " ]" << std::endl;
				harl.complain(level_strs[i]);
			}
			return (0);
		}
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;

/* 	harl.complain("DEBUG");
	harl.complain("INFO");
	harl.complain("WARNING");
	harl.complain("ERROR");
	harl.complain("Garbage"); */
	return 0;
}