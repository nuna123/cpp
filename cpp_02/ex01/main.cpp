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
	Fixed  *a = new Fixed();
	std::cout << std::endl;

	Fixed *b = new Fixed(*a);

	// b = a;





(void) b;


	std::cout << std::endl;
/* 	delete(a);
	delete(b); */



	return 0;
}