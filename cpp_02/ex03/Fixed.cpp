#include "./Fixed.hpp"


const int	Fixed::fractional_bits = 8;

 //CONSTRUCTORS
	Fixed::Fixed(void) : value (0)
	{
		// std::cout << "Default constructor called" <<std::endl;
	}

	Fixed::Fixed(const int num) : value (num << this->fractional_bits)
	{
		// std::cout << "const int constructor called" <<std::endl;
	}

	Fixed::Fixed(const float num)
	{
		float floo = num;
		//BASICALLY SHIFTING
		for (int c = 0; c < this->fractional_bits; c++)
			floo *= 2;
		this->value = roundf( floo );

		// std::cout << "const float constructor called" <<std::endl;
	}

	Fixed::Fixed (const Fixed &fixed) //COPY CONSTRUCTOR
	{
		// std::cout << "Copy constructor called" <<std::endl;
		this->value = fixed.getRawBits();
	}

Fixed::~Fixed (void)
{
	// std::cout << "Destructor called" <<std::endl;
}

Fixed &Fixed::operator = (const Fixed &fixed_copy)
{
	// std::cout << "Copy assignment operator called" <<std::endl;
	this->value = fixed_copy.getRawBits();
	return (*this);
}


// MEMBER FUNCTIONS

int	Fixed::getRawBits (void) const
{
	return this->value;
}

void	Fixed::setRawBits(int const raw)
{
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


//OVERLOADING
	std::ostream &operator<<(std::ostream& os, const Fixed& fixed)
	{
		return (os << fixed.toFloat());
	}

	//comparison operators
	bool Fixed::operator>(Fixed const& fixed)
	{
		return (this->toInt() > fixed.toInt());
	}
	bool Fixed::operator<(Fixed const& fixed)
	{
		return (this->toInt() < fixed.toInt());
	}
	bool Fixed::operator<=(Fixed const& fixed)
	{
		return (this->toInt() <= fixed.toInt());
	}
	bool Fixed::operator>=(Fixed const& fixed)
	{
		return (this->toInt() >= fixed.toInt());
	}
	bool Fixed::operator==(Fixed const& fixed)
	{
		return (this->toInt() == fixed.toInt());
	}
	bool Fixed::operator!=(Fixed const& fixed)
	{
		return (this->toInt() != fixed.toInt());
	}

	//comparison operators
	Fixed Fixed::operator+(Fixed const& fixed)
	{
		Fixed res(this->toFloat() + fixed.toFloat());
		return (res);
	}
	Fixed Fixed::operator-(Fixed const& fixed)
	{
		Fixed res(this->toFloat() - fixed.toFloat());
		return (res);
	}
	Fixed Fixed::operator*(Fixed const& fixed)
	{
		Fixed res(this->toFloat() * fixed.toFloat());
		return (res);
	}
	Fixed Fixed::operator/(Fixed const& fixed)
	{
		Fixed res(this->toFloat() / fixed.toFloat());
		return (res);
	}


	// increase, decrease prefix and postfix
	Fixed& Fixed::operator++(void)
	{
		this->setRawBits(this->getRawBits() + 1);
		return (*this);
	}
	Fixed& Fixed::operator--(void)
	{
		this->setRawBits(this->getRawBits() - 1);
		return (*this);
	}

	Fixed Fixed::operator ++ (int val)
	{
		Fixed temp;
		temp = *this;
		if (!val)
			val = 1;
		this->setRawBits(this->getRawBits() + val);
		return (temp);
	}
	Fixed Fixed::operator -- (int val) {
		Fixed temp;
		temp  = *this;
		if (!val)
			val = 1;
		this->setRawBits(this->getRawBits() - val);
		return (temp);
	}

//member functions
		Fixed& Fixed::min(Fixed& fixed_1, Fixed& fixed_2)
		{
			if (fixed_1 > fixed_2)
				return (fixed_2);
			return (fixed_1);
		}
		const Fixed& Fixed::min(Fixed const& fixed_1, Fixed const& fixed_2)
		{
			if (fixed_1.getRawBits() > fixed_2.getRawBits())
				return (fixed_2);
			return (fixed_1);
		}
		Fixed& Fixed::max(Fixed& fixed_1, Fixed& fixed_2)
		{
			if (fixed_1 < fixed_2)
				return (fixed_2);
			return (fixed_1);
		}
		const Fixed& Fixed::max(Fixed const& fixed_1, Fixed const& fixed_2)
		{
			if (fixed_1.getRawBits() < fixed_2.getRawBits())
				return (fixed_2);
			return (fixed_1);
		}