#include "./Fixed.hpp"
/*
Fixed (); //Default constructor
Fixed (const Fixed &fixed); //copy constructor
~Fixed (); // Destructor
Fixed & operator = (const Fixed &fixed); //Copy assignment operator
int		getRawBits(void) const;
void	setRawBits(int const raw);
*/

Fixed::Fixed(void) : value (0)
{
	std::cout << "Default constructor called" <<std::endl;
}

Fixed::Fixed (const Fixed &fixed)
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
	std::cout << "getRawBits member function called" <<std::endl;

	return this->value;
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" <<std::endl;

	this->value = raw;
}