#include "Point.hpp"
#include "Fixed.hpp"

#include <iostream>

float	findSqrt(float x)
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

bool	point_on_line (Point linepnt_a, Point linepnt_b, Point point)
{
	//really youre the man
	float rat_1 = (linepnt_a.getX().toFloat() - linepnt_b.getX().toFloat());
	rat_1 /= (linepnt_a.getY().toFloat() - linepnt_b.getY().toFloat());

	float rat_2 = (linepnt_a.getX().toFloat() - point.getX().toFloat());
	rat_1 /= (linepnt_a.getY().toFloat() - point.getY().toFloat());

	return (rat_1 == rat_2);
}

//get x coordinate with a given y and pnt a/b of the line
//WILL RETURN NULL IF Ay == By
//WILL RETURN NULL IF point is on either edge of the line
Point	*get_line_x(Point linepnt_a, Point linepnt_b, float y_coor)
{
	//		y1 - y2
	// m = ----------
	//		x1 - x2
	float	slope = (linepnt_a.getY().toFloat() - linepnt_b.getY().toFloat());

	if (linepnt_a.getX().toFloat() - linepnt_b.getX().toFloat() && slope)
		slope /= (linepnt_a.getX().toFloat() - linepnt_b.getX().toFloat());
	else
		slope = 0;

	// b = y - mx
	float	b = linepnt_a.getY().toFloat() - (slope * linepnt_a.getX().toFloat());

	//		y - b
	// x = -------
	//		  m
	float	x = (y_coor - b);
	if (slope)
		 x/= slope;
	if ((x < linepnt_a.getX().toFloat()) && (x > linepnt_b.getX().toFloat()))
		return (new Point(x, y_coor));
	if ((x > linepnt_a.getX().toFloat()) && (x < linepnt_b.getX().toFloat()))
		return (new Point(x, y_coor));
	return (NULL);
}

//get y coordinate with a given x and pnt a/b of the line
//WILL RETURN NULL IF Ax == Bx
//WILL RETURN NULL IF point is on either edge of the line
Point	*get_line_y(Point linepnt_a, Point linepnt_b, float x_coor)
{
	//		y1 - y2
	// m = ----------
	//		x1 - x2
	float	slope = (linepnt_a.getY().toFloat() - linepnt_b.getY().toFloat());

	if (linepnt_a.getX().toFloat() - linepnt_b.getX().toFloat() && slope)
		slope /= (linepnt_a.getX().toFloat() - linepnt_b.getX().toFloat());
	else
		slope = 0;

	// b = y - mx
	float	b = linepnt_a.getY().toFloat() - (slope * linepnt_a.getX().toFloat());

	// y = mx + b
	float	y = (slope * x_coor) + b;

	if ((y < linepnt_a.getY().toFloat()) && (y > linepnt_b.getY().toFloat()))
		return (new Point(x_coor, y));
	if ((y > linepnt_a.getY().toFloat()) && (y < linepnt_b.getY().toFloat()))
		return (new Point(x_coor, y));
	return (NULL);
}

Point	*find_first_division(Point pnt_A, Point pnt_B, Point pnt_C)
{
	Point* pnt_a_edge, *pnt_b_edge, *pnt_c_edge;
	pnt_a_edge = get_line_x (pnt_B, pnt_C, pnt_A.getY().toFloat());
	if (!pnt_a_edge)
		pnt_a_edge = get_line_y (pnt_B, pnt_C, pnt_A.getX().toFloat());

	pnt_b_edge = get_line_x (pnt_A, pnt_C, pnt_B.getY().toFloat());
	if (!pnt_b_edge)
		pnt_b_edge = get_line_y (pnt_A, pnt_C, pnt_B.getX().toFloat());

	pnt_c_edge = get_line_x (pnt_A, pnt_B, pnt_C.getY().toFloat());
	if (!pnt_c_edge)
		pnt_c_edge = get_line_y (pnt_A, pnt_B, pnt_C.getX().toFloat());

	// std::cout << *pnt_b_edge << std::endl;

	if (!pnt_a_edge)
		std::cout << "WTF A \n" ;
	else
		std::cout << *pnt_a_edge << std::endl;
	if (!pnt_b_edge)
		std::cout << "WTF B \n" ;
	else
		std::cout << *pnt_b_edge << std::endl;
	if (!pnt_c_edge)
		std::cout << "WTF C \n" ;
	else
		std::cout << *pnt_c_edge << std::endl;

	return NULL;
	//EDGES ARE NOT BEING INITIALIZED COMPLETELY



	Fixed*	dis_A, *dis_B, *dis_C;
	dis_A = get_points_distance(pnt_A, *pnt_a_edge);
	dis_B = get_points_distance(pnt_B, *pnt_b_edge);
	dis_C = get_points_distance(pnt_C, *pnt_c_edge);

	if (*dis_A >= *dis_B)
	{
		delete (pnt_b_edge);
		delete (dis_B);
		if (*dis_A >= *dis_C)
		{
			delete (pnt_c_edge);
			delete (dis_C);
			delete (dis_A);
			return (pnt_a_edge);
		}
		else if (*dis_A < *dis_C)
		{
			delete (pnt_a_edge);
			delete (dis_A);
			delete (dis_C);
			return (pnt_c_edge);
		}
	}
	else if (*dis_B > *dis_A)
	{
		delete (pnt_a_edge);
		delete (dis_A);
		if (*dis_B >= *dis_C)
		{
			delete (pnt_c_edge);
			delete (dis_C);
			delete (dis_B);
			return (pnt_b_edge);
		}
		else if (*dis_B < *dis_C)
		{
			delete (pnt_b_edge);
			delete (dis_B);
			delete (dis_C);
			return (pnt_c_edge);
		}
	}
	return NULL;
}

int main( void )
	{

	Point a(5, 5);
	Point b(3, 0);
	Point c(0, 10);

	Point *wtf_ol = find_first_division(a, b, c);

	if (wtf_ol)
		std::cout << "OMFG\n" ;


	delete(wtf_ol);


	return 0;
}

/*
	// TESTS FOR GET_LINE_X AND GET_LINE_Y
	Point a(-5, -5);
	Point b(5, 5);


	Point *pnt = get_line_x(a, b, 2);
	if (!pnt)
		std::cout << "NO POINT :(" << std::endl;
	else
		std::cout << "\nPOINT\n\tx: " << pnt->getX().toFloat()<< std::endl << "\ty: " << pnt->getX().toFloat() << std::endl;
	delete (pnt);

	pnt = get_line_y(a, b, -1);
	if (!pnt)
		std::cout << "NO POINT :(" << std::endl;
	else
		std::cout << "\nPOINT\n\tx: " << pnt->getX().toFloat()<< std::endl << "\ty: " << pnt->getX().toFloat() << std::endl;
	delete (pnt);
*/