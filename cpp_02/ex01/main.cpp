#include "Fixed.hpp"

#include <iostream>
#include <cstdio>


/* int main( void ) {


	Fixed mynum(1.1f);

	// std::cout << mynum.toInt() << std::endl;
	std::cout << mynum.getRawBits()<< std::endl;
	std::cout << mynum.toFloat() << std::endl;

	// num = roundf( floaty * ( 1 << 8 ) );


	//BASICALLY SHIFTING
	for (int c = 0; c < 8; c++)
		floaty *= 2;
	num = roundf( floaty );


	return 0;
} */


int main( void ) {
Fixed a;
Fixed const b( 10 );
Fixed const c( 42.42f );
Fixed const d( b );
a = Fixed( 1234.4321f );
std::cout << "a is " << a << std::endl;
std::cout << "b is " << b << std::endl;
std::cout << "c is " << c << std::endl;
std::cout << "d is " << d << std::endl;
std::cout << "a is " << a.toInt() << " as integer" << std::endl;
std::cout << "b is " << b.toInt() << " as integer" << std::endl;
std::cout << "c is " << c.toInt() << " as integer" << std::endl;
std::cout << "d is " << d.toInt() << " as integer" << std::endl;
return 0;
}