#include "RPN.hpp"

#define DEBUG false

static void	operate(char expr, std::stack<int> &my_stack)
{
	int first, second;

	if (my_stack.size() < 2)
	{
		if(DEBUG)
			std::cerr << "Error: Less than two values in stack by operation: " << expr << std::endl;
		throw NoBueno();
	}

	first = my_stack.top();
	my_stack.pop();
	second = my_stack.top();
	my_stack.pop();

	switch (expr)
	{
		case '+':
			my_stack.push(second + first);
			break;
		case '-':
			my_stack.push(second - first);
			break;
		case '*':
			my_stack.push(second * first);
			break;
		case '/':
			my_stack.push(second / first);
			break;
		default:
		{
			if(DEBUG)
				std::cerr << "Error: operator unrecognized: " << expr << std::endl;
			throw NoBueno();
		}
	}

	if (DEBUG)
	{
		std::cout << second
		<< expr
		<< first
		<< " = "
		<< my_stack.top()
			<< std::endl;
	}

}

static bool valid_val(std::string s)
{
	if (s.length() == 1 && !std::isdigit(s.at(0)))
		return false;
	for (std::string::iterator i = s.begin(); i != s.end(); i++)
	{
		if (i == s.begin() && s.length() > 1 &&
			(!std::isdigit(*i) && *i != '+' && *i != '-'))
			return false;
		if (i != s.begin() && !std::isdigit(*i))
			return false;
	}
	return true;
}

static bool valid_expr(std::string s)
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

		if(expr.find(" ") == std::string::npos)
		{
			val = expr;
			expr = "";
		}
		else{
			val = expr.substr(0, expr.find(" "));
			expr = expr.substr(expr.find(" ") + 1);
		}

		if (valid_val(val))
		{
			if (DEBUG)
				std::cout << "pushing " << val<< std::endl;
			my_stack.push(std::atoi(val.c_str()));
		}
		else if (valid_expr(val))
			operate(val.at(0), my_stack);
		else
		{
			if(DEBUG)
				std::cerr << "Error: invalid value " << val << std::endl;
			throw NoBueno();
		}
	}

	if (my_stack.size() != 1)
	{
		if(DEBUG)
			std::cerr << "Error: incorrect num of values left in stack by the end of expression " << std::endl;
		throw NoBueno();
	}
	return my_stack.top();
}
