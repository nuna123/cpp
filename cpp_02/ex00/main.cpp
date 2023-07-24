#include "Fixed.hpp"


int main( void ) {
	Fixed a;



	Fixed b( a );



	Fixed c;



	c = b;




	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}


/*
int main( void ) {

	Fixed a;
	a.setRawBits(5);

	Fixed b;
	b = a; //copy assignment operator

	std::cout << "\n\n" << std::endl;

	std::cout << "address of A: " << &a <<std::endl;
	std::cout << "address of B: " << &b << "\n\n" << std::endl;

	return 0;
}
 */
/*
https://dev.to/tomislavkraljic/c-copy-constructors-5cij

	Copy constructor
		- is called when a new object is created from an existing object,
			as a copy of the existing object
		-creates a separate memory block for the new object.

	Copy Assignment operator
		- called when an already initialized object is assigned
			a new value from another existing object.
		- does not create a separate memory block or new memory space.



	THE DEFAULT SYSTEM COPY ASSIGNMENT OPERATOR IS ONLY 'SHALLOW COPYING' THE OBJECT
	THAT ISNT GOOD
	shallow copying means a new mwmory block is not created. instead the new object would
	poing to the old object's memory. then if the old object is deleted or changed, the new one would too,
	The instructions call to not replicate this behaviour, but correct it by overloading the = operator.

*/
