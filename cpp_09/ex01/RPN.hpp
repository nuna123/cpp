#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <cstdlib>

class NoBueno: public std::exception
{
	const virtual char *what() const throw()
	{return  "Problemo :(";}
};

int	evaluate_expression ( char *expr);

#endif