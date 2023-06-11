// in main  - already have func for finding first division.
// find if its vertical or horizontal, and what point it connects to.
// if horizontal, compare pnt to find to the line's y
// otherwise, compare to x.

//find midpoint, divide in the right way according to comparison
// new line, same point and orientation is flipped (horizontal/ vertical)
 //THIS SHIT STOPS WHEN LINE HITS THE PNT. THEN THE DISTANCE TO THE EDGE OF
 //	THE LINE CAN BE COMPARED TO SEE IF IS IN TRIANGLE
#include "Point.hpp"
#include "Fixed.hpp"

#include <iostream>

// bool fml(Point *divline_A, Point *divline_B, Point *pnt, bool isVertical)
// {
// 	if (isVertical)
// 	{
// 		if (divline_A->getX() == pnt->getX())
// 		{
// 			if ()
// 		}

// 	}

// }