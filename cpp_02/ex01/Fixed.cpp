#include "./Fixed.hpp"
/*
Fixed (); //Default constructor
Fixed (const Fixed &fixed); //copy constructor
~Fixed (); // Destructor
Fixed & operator = (const Fixed &fixed); //Copy assignment operator
int		getRawBits(void) const;
void	setRawBits(int const raw);
*/


const int	Fixed::fractional_bits = 8;

 //CONSTRUCTORS
Fixed::Fixed(void) : value (0)
{
	std::cout << "Default constructor called" <<std::endl;
}

Fixed::Fixed(const int num) : value (num << this->fractional_bits)
{
	std::cout << "const int constructor called" <<std::endl;
}

Fixed::Fixed(const float num)
{
	float floo = num;
	//BASICALLY SHIFTING
	for (int c = 0; c < this->fractional_bits; c++)
		floo *= 2;
	this->value = roundf( floo );

	std::cout << "const float constructor called" <<std::endl;
}

Fixed::Fixed (const Fixed &fixed) //COPY CONSTRUCTOR
{
	std::cout << "Copy constructor called" <<std::endl;
	*this = fixed;
}

Fixed::~Fixed (void)
{
	std::cout << "Destructor called" <<std::endl;
}

Fixed &Fixed::operator = (const Fixed &fixed_copy)
{
	std::cout << "Copy assignment operator called" <<std::endl;
	this->value = fixed_copy.getRawBits();
	return (*this);
}

int	Fixed::getRawBits (void) const
{
	return this->value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" <<std::endl;

	this->value = raw;
}

float	Fixed::toFloat( void ) const
{
	float	retval;
	retval = this->getRawBits();
	for (int c = 0; c < this->fractional_bits; c++)
		retval /= 2;
	return (retval);
}

int		Fixed::toInt( void ) const
{
	return (this->getRawBits() >> this->fractional_bits);
}

std::ostream &operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}