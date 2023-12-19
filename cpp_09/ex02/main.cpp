
#include "PmergeMe.hpp"

int main(int argc, char *argv[])
{
	if (argc < 3)
		std::cout << "Error!\n\tWe need an array to do the thing" << std::endl;
	else
		PmergeMe::sort(argc, argv);

/*   double b = 2006.0;
  double c = 1.0e-10;

  std::cout.precision(5);

  std::cout << "default:\n";
  std::cout << (float) 33 / 1000000 << '\n' << b << '\n' << c << '\n';

  std::cout << '\n';

  std::cout << "fixed:\n" << std::fixed;
  std::cout << (float) 33 / 1000000  << '\n' << b << '\n' << c << '\n';

  std::cout << '\n';

  std::cout << "scientific:\n" << std::scientific;
  std::cout << (float) 33 / 1000000  << '\n' << b << '\n' << c << '\n'; */
	return 0;
}