
#include "Array.hpp"


/*
Templates cannot be implemented in a cpp file separate to the header!
	https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file

https://www.geeksforgeeks.org/templates-cpp/
*/
int main( void )
{

	Array<char> *arr;

	try
	{
		arr = new Array<char>(2);
		arr->print();
		arr[0] = '1';
		arr[1] = '2';
		int * a = new int();
		std::cout << *a << std::endl;

		delete arr;
		delete a;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return 0;
}