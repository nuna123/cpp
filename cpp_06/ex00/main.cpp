#include "./ScalarConverter.hpp"
// #include <Array>

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