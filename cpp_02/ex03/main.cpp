#include "Point.hpp"
#include "Fixed.hpp"

#include <iostream>

float findSqrt(float x)
{
	// for 0 and 1, the square roots are themselves
	if (x < 2)
		return x;

	float y = x;
	float z = (y + (x / y)) / 2;

	while (y - z) {
		y = z;
		z = (y + (x / y)) / 2;
	}
	return z;
}

Fixed	*get_points_distance(Point pnt_a, Point pnt_b)
{
	Fixed	distance;

	// thank u pythagoras
	float y_dif = pnt_a.getY().toFloat() - pnt_b.getY().toFloat();
	y_dif *= y_dif;

	float x_dif = pnt_a.getX().toFloat() - pnt_b.getX().toFloat();
	x_dif *= x_dif;

	float dis = findSqrt(y_dif + x_dif);
	return (new Fixed(dis));
}

bool point_on_line (Point linepnt_a, Point linepnt_b, Point point)
{
	//really youre the man
	float rat_1 = (linepnt_a.getX().toFloat() - linepnt_b.getX().toFloat());
	rat_1 /= (linepnt_a.getY().toFloat() - linepnt_b.getY().toFloat());

	float rat_2 = (linepnt_a.getX().toFloat() - point.getX().toFloat());
	rat_1 /= (linepnt_a.getY().toFloat() - point.getY().toFloat());

	return (rat_1 == rat_2);
}

int main( void )
	{

		Point a(0, 4);
		Point b(0, 2);
		Point pnt(4, 2);
		std::cout << point_on_line(a, b, pnt) << std::endl;

		// delete (dis);
	return 0;
}