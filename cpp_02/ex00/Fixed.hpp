#pragma once
#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>

class	Fixed
{
	private:
		int					value;
		static const int	fractional_bits;

	public:
		Fixed ();										//Default constructor
		Fixed (const Fixed &fixed);						//copy constructor
		~Fixed ();										// Destructor
		Fixed &operator = (Fixed const &fixed_copy);	//Copy assignment operator
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif