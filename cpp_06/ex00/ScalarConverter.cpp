#include "ScalarConverter.hpp"
std::string	ScalarConverter::_arg;
e_types		ScalarConverter::_type;
char		ScalarConverter::_char;
int			ScalarConverter::_int;
float		ScalarConverter::_float;
double		ScalarConverter::_double;

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
const std::string	&ScalarConverter::get_arg(){return _arg;}
const e_types		&ScalarConverter::get_type(){return _type;}
const char			&ScalarConverter::get_char(){return _char;}
const int			&ScalarConverter::get_int(){return _int;}
const float			&ScalarConverter::get_float(){return _float;}
const double		&ScalarConverter::get_double(){return _double;}

//setters
void		ScalarConverter::set_arg(const std::string &x){_arg = x;}
void		ScalarConverter::set_type(const e_types &x){_type = x;}
void		ScalarConverter::set_char(const char &x){_char = x;}
void		ScalarConverter::set_int(const int &x){_int = x;}
void		ScalarConverter::set_float(const float &x){_float = x;}
void		ScalarConverter::set_double(const double &x){_double = x;}


//METHODS

e_types find_type(std::string str)
{
	std::stringstream	ss(str);
	long int			long_i;
	ss << std::fixed << std::setprecision(5);

	//special cases
	if (str == "nan" || str == "-inf" || str == "+inf" || str == "inf"
		|| str == "-inff" || str == "+inff" || str == "nanf" || str == "inff")
		return (SPECIAL);
	//char
	if(str.length() == 1 && isdigit(str[0]) == false)
	{
		// std::cout << "CHAR" << std::endl;
		ScalarConverter::set_char(str.at(0));
		return CHAR;
	}
	//managing possible errs
	// there are only digits, dot or 'f' or +-
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (i == 0 && (str[i] == '+' || str[i] == '-'))
			continue;
		else if (i == str.length() - 1 && str[i] == 'f')
			continue;
		else if (isdigit(str[i]) == false
			&& str[i] != '.')
			return INVALID;
	}
	//if there is more than one '.'/'f'
	if ((str.find_first_of('.') != str.find_last_of('.'))
		|| (str.find_first_of('f') != str.find_last_of('f')))
		{
			return INVALID;
		}
	//FLOAT
	if(str.find('f') != std::string::npos)
	{
		// std::cout << "FLOAT" << std::endl;
		ScalarConverter::set_float(atof(str.c_str()));
		return FLOAT;
	}
	//DOUBLE
	else if(str.find('.') != std::string::npos)
	{
/* 		double d = 0.0;
		ss << d;
		ss << std::fixed << std::setprecision(12) << d; */
		// std::cout << "DOUBLE" << std::endl;
		ScalarConverter::set_double(static_cast< double > (atof(str.c_str())));
		return DOUBLE;
	}
	else
	{
		ss >> long_i;

		if (long_i < std::numeric_limits<int>::min()
			|| long_i > std::numeric_limits<int>::max())
			return INVALID;
		ScalarConverter::set_int( atoi(str.c_str()));
		// std::cout << "INT" << std::endl;
		return INT;
	}
	return INVALID;
}
void print_special_val(void)
{
	//if (str == "nan" || str == "-inf" || str == "+inf" || str == "inf"
	//	|| str == "-inff" || str == "+inff" || str == "nanf" || str == "inff")
	std::string arr[] = {"nan", "-inf", "inf"};
	std::string str = ScalarConverter::get_arg();
	int idx;

	if (str == "nanf")
		str = "nan";
	if (str.at(str.length() - 1)  == 'f'
		&& str.at(str.length() - 2) == 'f')
		str = str.substr(0, str.length() - 1);

	for (unsigned int i = 0; i < arr->length(); i++)
	{
		if (str == arr[i])
			idx = i;
	}

	std::cout << "char:\timpossible!" << std::endl;
	switch (idx)
	{
		case (0):
			std::cout << "int:\t" << std::numeric_limits<int>::quiet_NaN() << std::endl;
			std::cout << "float:\t" << std::numeric_limits<float>::quiet_NaN() << "f" << std::endl;
			std::cout << "double:\t" << std::numeric_limits<double>::quiet_NaN() << std::endl;
			break;
		case (1):
			std::cout << "int:\t" << -std::numeric_limits<int>::infinity() << std::endl;
			std::cout << "float:\t" << -std::numeric_limits<float>::infinity() << "f" << std::endl;
			std::cout << "double:\t" << -std::numeric_limits<double>::infinity() << std::endl;
			break;
		case (2):
			std::cout << "int:\t" << std::numeric_limits<int>::infinity() << std::endl;
			std::cout << "float:\t" << std::numeric_limits<float>::infinity() << "f" << std::endl;
			std::cout << "double:\t" << std::numeric_limits<double>::infinity() << std::endl;
			break;
	}

}

void ScalarConverter::convert(std::string input)
{
	e_types	type;
	type = find_type(input);


	//if (type == FLOAT) // If the type is float, remove the 'f' at the end, so we cabn take advantage of the stringstream (that can evaluate nan and inf)
//		input.erase(input.size() - 1);
	//std::istringstream ss(input); // Create a stringstream with the input - is used for conversion of the type itself.	std::cout << std::fixed << std::setprecision(1);

	int precision;
	precision = 1;
	if (type == DOUBLE || type == FLOAT)
	{
		precision = input.length() - input.find('.');
		if (type == FLOAT)
			precision -=1;
	}
	std::cout << std::fixed << std::setprecision(precision);

	if (type == INVALID)
	{
		throw ScalarConverter::InvalidInputException();
	}
	set_arg(input);
	set_type(type);

	switch (type)
	{
		case (SPECIAL):
			print_special_val();
			break;
		case (CHAR):
		{
			std::cout << "char:\t\'" << get_char() << "\'" << std::endl;
			std::cout << "int:\t" << (int) get_char() << std::endl;
			std::cout << "float:\t" << (float) get_char() << "f" << std::endl;
			std::cout << "double:\t" << (double) get_char() << std::endl;
			break;
		}
		case (INT):
		{
			if (std::isprint(get_int()))
				std::cout << "char:\t\'" << (char) get_int()<< "\'"  << std::endl;
			else
				std::cout << "char:\tNon displayable!" << std::endl;
			std::cout << "int:\t" << get_int() << std::endl;
			std::cout << "float:\t" << static_cast<float>(get_int())  << "f" << std::endl;
			std::cout << "double:\t" << static_cast< double >(get_int()) << std::endl;
			break;
		}
		case (FLOAT):
		{
			if (std::isprint((char) get_float()))
				std::cout << "char:\t\'" << (char) get_float()<< "\'"  << std::endl;
			else
				std::cout << "char:\tNon displayable!" << std::endl;
			std::cout << "int:\t" << static_cast< int >(get_float()) << std::endl;
			std::cout << "float:\t" << static_cast< float >(get_float()) << "f" << std::endl;
			std::cout << "double:\t" << static_cast< double >(get_float()) << std::endl;
			break;
		}
		case (DOUBLE):
		{
			if (std::isprint((char) get_double()))
				std::cout << "char:\t\'" << (char) get_double()<< "\'"  << std::endl;
			else
				std::cout << "char:\tNon displayable!" << std::endl;
			std::cout << "int:\t" << static_cast< int >(get_double()) << std::endl;
			std::cout << "float:\t" << static_cast< float >(get_double()) << "f" << std::endl;
			std::cout << "double:\t" << (get_double()) << std::endl;
			break;
		}
		default:
			break;
	}


}

const char *ScalarConverter::InvalidInputException::what() const throw()
{return (RED "Invalid Input!" NRM);}