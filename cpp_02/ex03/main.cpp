#include "Point.hpp"
#include "Fixed.hpp"

#include <iostream>
bool bsp( Point const a, Point const b, Point const c, Point const point);
int main( void )
{
	Point a(0, 0);
	Point b(20, 0);
	Point c(10, 30);


	Point pnt(15, 0);

	if (bsp(a, b, c, pnt))
		std::cout << "YAY!" << std::endl;
	else
		std::cout << "NAY!" << std::endl;

	return 0;
}
