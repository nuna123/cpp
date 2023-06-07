#include "./Point.hpp"
#include "./Fixed.hpp"

//Constructors
	// Default constructor
	Point::Point (void) : x (0), y (0){}

	//two floats - x and y coors
	Point::Point (float x_float, float y_float) : x (x_float), y (y_float){}

	//two fixed vals - x and y
	Point::Point (Fixed x_fixed, Fixed y_fixed) : x (x_fixed), y (y_fixed){}

	// copy constructor - initialize a previously uninitialized object from some other object's data.
	Point::Point (const Point &point): x(point.getX().toFloat()), y(point.getY().toFloat()){}

Point::~Point () {} // destructor

Point& Point::operator=(const Point &point_copy)
{
	// Point class has two CONST members
	// they cant be reassigned using the assignment operator!
	// FML so much wasted time
	(void)point_copy;
	return (*this);
}

Fixed	Point::getX(void) const
{
	return (this->x);
}
Fixed	Point::getY(void) const
{
	return (this->y);
}