#include "Point.hpp"
#include "Fixed.hpp"

#include <iostream>

Fixed triangle_area(Point const a, Point const b, Point const c)
{
//Area A = [ x1(y2 – y3) + x2(y3 – y1) + x3(y1-y2)]/2

	Fixed area;
	area = a.getX() * (b.getY() - c.getY());
	area = area + (b.getX() * (c.getY() - a.getY()));
	area = area + (c.getX() * (a.getY() - b.getY()));
	area = area / 2;

	if (area < 0)
		return (area * -1);
	return area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed triangle_A = triangle_area(point, a, b);
	Fixed triangle_B = triangle_area(point, b, c);
	Fixed triangle_C = triangle_area(point, c, a);

	if (triangle_A == 0
		|| triangle_B == 0
		|| triangle_C == 0)
		return false;
	if (triangle_area(a, b, c) == (triangle_A + triangle_B + triangle_C))
		return true;
	return false;
}