#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>
# include <string>
#include <stdlib.h>
enum e_types
	{
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		UNSET,
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
		static std::string	get_arg();
		static e_types		get_type();
		static char			get_char();
		static int			get_int();
		static float		get_float();
		static double		get_double();

		//setter
		static void			set_arg(std::string x);
		static void			set_type(e_types x);
		static void			set_char(char x);
		static void			set_int(int x);
		static void			set_float(float x);
		static void			set_double(double x);

	private:
		static std::string	_arg;
		static e_types		_type;
		static char			_char;
		static int			_int;
		static float		_float;
		static double		_double;

};

#endif