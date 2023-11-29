#include "RPN.hpp"

class NoBueno: public std::exception
{
	const virtual char *what() const throw()
	{return  "Problemo :(";}
};

void	operate(char expr, std::stack<int> &my_stack)
{
	int first, second;
	std::cout << "SIZE " << my_stack.size() << std::endl;

	if (my_stack.size() < 2)
	{
		std::cout << "1" << std::endl;
		throw NoBueno();

	}

	first = my_stack.top();
	my_stack.pop();
	second = my_stack.top();
	my_stack.pop();

	std::cout << "First: " << first
		<< "second: " << second << std::endl;
	switch (expr)
	{
		case '+':
			my_stack.push(second + first);
			std::cout << ">>>+" << std::endl;
			break;
		case '-':
			my_stack.push(second - first);
			std::cout << ">>>-" << std::endl;
			break;
		case '*':
			my_stack.push(second * first);
			std::cout << ">>>*" << std::endl;
			break;
		case '/':
			my_stack.push(second / first);
			std::cout << ">>>/" << std::endl;
			break;
		default:
			{
		std::cout << "2" << std::endl;
		throw NoBueno();

	}
	}
}



bool valid_val(std::string s)
{
	if (s.length() == 1 && !std::isdigit(s.at(0)))
		return false;
	for (std::string::iterator i = s.begin(); i != s.end(); i++)
	{
		if (i == s.begin() && s.length() > 1 &&
			(!std::isdigit(*i) || *i != '+' || *i != '-'))
			return false;
		if (i != s.begin() && !std::isdigit(*i))
			return false;
	}
	return true;
}

bool valid_expr(std::string s)
{
	if (s.length() == 1 &&
		(
			s[0] == '+'
			|| s[0] == '-'
			|| s[0] == '*'
			|| s[0] == '/'
		))
		return true;
	return false;
}


int evaluate_expression ( char *e)
{
	//create a stack
	//if value is a number, push to stack
	//if value is an operation, operate on top two members of stack

	std::stack<int> my_stack;
	std::string expr(e);
	std::string val;

	while (!expr.empty())
	{

		std::cout << my_stack.size() << std::endl;
		if(expr.find(" ") == std::string::npos)
		{
			val = expr;
			expr = "";
		}
		else{
			val = expr.substr(0, expr.find(" "));
			expr = expr.substr(expr.find(" ") + 1);
		}
			std::cout << "VAL: [" << val << "]"<< std::endl;

		if (valid_val(val))
			my_stack.push(std::atoi(val.c_str()));
		else if (valid_expr(val))
			operate(val.at(0), my_stack);
		else
		{
			std::cout << "3" << std::endl;
			std::cout <<"{" << val <<"}"<< std::endl;
			throw NoBueno();
		}
	}

	std::cout << my_stack.size() << std::endl;
	std::cout << my_stack.top() << std::endl;
	return 0;
}
