#include <iostream>
# include <sstream>
# include <iomanip>

int main(void)
{
	double d = 12.345678;
	float f = static_cast<float>(d);

	std::cout << std::setprecision(10);
	std::cout	<< "\tdouble:\t" << d
				<< "\n\tfloat:\t" << f
				<< std::endl;

	return 0;
}