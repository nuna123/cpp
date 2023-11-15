#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <iomanip>
# include <typeinfo>
# include <cmath>
# include <limits>

#define RED "\033[0;91m"
#define NRM "\033[0;39m"

enum e_types
	{
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		SPECIAL,
		INVALID
	};

//static class:
//			only has static members, which are values
//			shared by all members of the class
//			and static methods, which can only access static members.
class ScalarConverter
{
	public:
		// Constructors
		ScalarConverter();
		ScalarConverter(const ScalarConverter &copy);

		// Destructor
		~ScalarConverter();

		// Operators
		ScalarConverter & operator=(const ScalarConverter &assign);

		//method
		static void convert(std::string str);

		//getters
		static const std::string	&get_arg();
		static const e_types		&get_type();
		static const char			&get_char();
		static const int			&get_int();
		static const float			&get_float();
		static const double			&get_double();

		//setter
		static void					set_arg(const std::string &x);
		static void					set_type(const e_types &x);
		static void					set_char(const char &x);
		static void					set_int(const int &x);
		static void					set_float(const float &x);
		static void					set_double(const double &x);

	private:
		static std::string	_arg;
		static e_types		_type;
		static char			_char;
		static int			_int;
		static float		_float;
		static double		_double;

		class InvalidInputException: public std::exception
		{
			public:
				const virtual char *what() const throw();

		};
};

#endif