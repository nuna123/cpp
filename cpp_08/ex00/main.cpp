#include "./easyfind.hpp"

#include <set>
#include <vector>


int main(void)
{
	std::set<int>		int_set;
	std::vector<int>	int_vector;

	for (int i = 0; i <= 1560; i++)
	{
		//NOT ADDED INTO VECTOR
		// int_vector.push_back(i);
		int_set.insert(i);
	}

	int TOFIND = 5;

	try
	{
		std::cout << "int vector:\t";
		easyfind(int_vector,TOFIND);
		std::cout << std::endl;

		std::cout << "int set:\t";
		easyfind(int_set,TOFIND);
		std::cout << std::endl;

	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}