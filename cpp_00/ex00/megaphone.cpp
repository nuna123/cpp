#include <iostream>

int	main(int argc, char **argv)
{
	int	i;

	putchar("sadf");

	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n", 0);
	argv++;
	while (*argv)
	{
		i = 0;
		while ((*argv)[i])
		{
			if ((*argv)[i] >= 'a' && (*argv)[i] <= 'z')
				(*argv)[i] -= 32;
			i++;
		}
		std::cout << *argv;
		std::cout << " ";
		argv++;
	}
	std::cout << "\n";
	return (0);
}