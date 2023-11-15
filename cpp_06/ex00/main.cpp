#include "./ScalarConverter.hpp"
// #include <Array>



/*
notes:
	convertion to char uses modulo of 128- the ascii table.
	trying to display int to display int '42345' will show as 'i'.

	Float is less accurate than double, precision may be lost in conversion

	Static class is defined by its methods being accessible
		without an instance of the class.
*/


int main(int argc, char **argv)
{
	if (argc != 2)
		return 1;
	ScalarConverter *sc = new ScalarConverter();
	std::cout <<std::endl<< "----------------------" <<std::endl;

	try
	{
		sc->convert(argv[1]);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() <<std::endl;
	}
	std::cout << "----------------------" <<std::endl<<std::endl;
	delete(sc);
	return 0;
}