#pragma once
#ifndef POINT_HPP
#define POINT_HPP

# include <iostream>
#include <math.h>

#include "Fixed.hpp"

class	Point
{
	private:
		Fixed	const x;
		Fixed	const y;

	public:
		Point ();					//Default constructor
		Point (Fixed x_fixed, Fixed y_fixed);	//Another constructor
		Point (float x_float, float y_float);	//Another constructor
		Point (const Point &point);	//copy constructor
		~Point ();					// Destructor
		Point&	operator=(Point const &point_copy); //Copy assignment operator
													//Invalid! bc members are constant

		Fixed	getX(void) const;
		Fixed	getY(void) const;
};

#endif