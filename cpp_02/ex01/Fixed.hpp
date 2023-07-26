#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
#include <math.h>

class	Fixed
{
	private:
		int					value;
		static const int	fractional_bits;

	public:
		Fixed (); //Default constructor
		Fixed (const Fixed &fixed); //copy constructor
		~Fixed (); // Destructor
		Fixed &operator = (Fixed const &fixed_copy); //Copy assignment operator

		Fixed (const int);
		Fixed (const float);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		float	toFloat( void ) const;
		int		toInt( void ) const;



};
		std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

/*
	fractional bits are how many of the rightmost bits will be fractional,
		basically where does the fractional point stand.


	to turn it from INT to FLOAT the number basically needs to be transposed, shifted, to
	the right till the point stands in the correct place.

	the other way for turning from FLOAT to INT
*/




#endif