
#include "Array.hpp"


/*
Templates cannot be implemented in a cpp file separate to the header!
	https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file

https://www.geeksforgeeks.org/templates-cpp/
*/
int main( void )
{



	try
	{

		Array<char> arr(5);

		char *c = new char;
		std::cout << *c << std::endl;
		delete c;


		arr.size();

		arr[0] = 'a';
		arr[1] = 'b';

		Array<char> arr2(arr);
		arr[2] = 'c';
		arr[3] = 'd';

		arr.print();
		arr2[0] = 'A';
		arr2[1] = 'B';

		arr = arr2;

		arr.print();
		arr2.print();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	return 0;
}