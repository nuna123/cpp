
#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 3)
		std::cout << "Error!\n\tWe need an array to do the thing" << std::endl;
	else
		PmergeMe::sort(argc, argv);

	return 0;
}