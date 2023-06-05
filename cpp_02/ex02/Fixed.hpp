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

		//COMPARISON OPERATORS
 		bool operator>(Fixed const& fixed);
		bool operator<(Fixed const& fixed);
		bool operator<=(Fixed const& fixed);
		bool operator>=(Fixed const& fixed);
		bool operator==(Fixed const& fixed);
		bool operator!=(Fixed const& fixed);

		//ARITHMATIC OPERATORS
		Fixed operator+(Fixed const& fixed);
		Fixed operator-(Fixed const& fixed);
		Fixed operator*(Fixed const& fixed);
		Fixed operator/(Fixed const& fixed);

		//INCREASE / DECREASE OPERATORS
		Fixed& operator++(void);
		Fixed& operator--(void);
		Fixed operator ++ (int val);
		Fixed operator -- (int val);

		//member functions
		static Fixed& min(Fixed& fixed_1, Fixed& fixed_2);
		static const Fixed& min(Fixed const& fixed_1, Fixed const& fixed_2);
		static Fixed& max(Fixed& fixed_1, Fixed& fixed_2);
		static const Fixed& max(Fixed const& fixed_1, Fixed const& fixed_2);

};
		std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
#endif