#include "ScalarConverter.hpp"

// Constructors
ScalarConverter::ScalarConverter()
{
	std::cout << "\e[0;33mDefault Constructor called of ScalarConverter\e[0m" << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy)
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of ScalarConverter\e[0m" << std::endl;
}


// Destructor
ScalarConverter::~ScalarConverter()
{
	std::cout << "\e[0;31mDestructor called of ScalarConverter\e[0m" << std::endl;
}


// Operators
ScalarConverter & ScalarConverter::operator=(const ScalarConverter &assign)
{
	(void) assign;
	return *this;
}

//getters
std::string	ScalarConverter::get_arg(){return _arg;}
e_types		ScalarConverter::get_type(){return _type;}
char		ScalarConverter::get_char(){return _char;}
int			ScalarConverter::get_int(){return _int;}
float		ScalarConverter::get_float(){return _float;}
double		ScalarConverter::get_double(){return _double;}

//setters
void		ScalarConverter::set_arg(std::string x){_arg = x;}
void		ScalarConverter::set_type(e_types x){_type = x;}
void		ScalarConverter::set_char(char x){_char = x;}
void		ScalarConverter::set_int(int x){_int = x;}
void		ScalarConverter::set_float(float x){_float = x;}
void		ScalarConverter::set_double(double x){_double = x;}


//METHODS

e_types find_type(std::string str)
{
	//char
	if(str.length() == 1 && isdigit(str[0]) == false)
	{
		ScalarConverter::set_char(str.at(0));
		return CHAR;
	}

	// there are only digits, dot or 'f' or +-
	for (int i = 0; i < str.length(); i++)
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			i = i;
		else if (i == str.length() - 1 && str[i] == 'f')
			i = i;
		else if (isdigit(str[i]) == false
			&& str[i] != '.')
			return INVALID;
	}
	//if there is more than one '.'/'f'
	if ((str.find_first_of('.') != str.find_last_of('.'))
		|| (str.find_first_of('f') != str.find_last_of('f')))
		return INVALID;

	//int
	int i;
	std::string s;
	if(str.find('.') == std::string::npos)
	{
		s = str;
		if(isdigit(str.at(0)) == false)
			s = str.substr(0, str.length());
		i = atoi(str.c_str());

		return INT;
	}

	//float
	else if(str.find('f') != std::string::npos)
		return FLOAT;
	else
		return DOUBLE;
	

	//double

	
}
void ScalarConverter::convert(std::string str)
{
	e_types	type;

	type = find_type(str);
	if (type == INVALID)
		return ;
	set_arg(str);
	set_type(type);
	

}

