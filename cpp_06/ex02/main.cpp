#include "./classes.hpp"

#include <iostream>
#include <stdint.h>

# include <cstdlib>
# include <time.h>

/*
Base * generate(void);
	It randomly instanciates A, B or C and returns the instance as a Base pointer.
	Feel free to use anything you like for the random choice implementation.

void identify(Base* p);
	It prints the actual type of the object pointed to by p: "A", "B" or "C".

void identify(Base& p);
	It prints the actual type of the object pointed to by p: "A", "B" or "C".
	Using a pointer inside this function is forbidden.
*/

Base *	generate(void)
{
	static int s;
		if (!s)
			srand((unsigned) time(NULL));
	s = 1;
	Base *ret;
	switch (std::rand() % 3)
	{
		case (0):
			ret = new A;
			std::cout << "generating A..." << std::endl;
			break;
		case (1):
			ret = new B;
			std::cout << "generating B..." << std::endl;
			break;
		case (2):
			ret = new C;
			std::cout << "generating C..." << std::endl;
			break;
	}
	return ret;
}

void	identify(Base* p)
{
	try
	{
		A _a = dynamic_cast<A&> (*p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception  &e)
	{}
	try
	{
		B _b = dynamic_cast<B&> (*p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception  &e)
	{}
	try
	{
		C _c = dynamic_cast<C&> (*p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception  &e)
	{}
}

void	identify(Base& p)
{
	try
	{
		A _a = dynamic_cast<A&> (p);
		std::cout << "A" << std::endl;
		return ;
	}
	catch (std::exception  &e)
	{}
	try
	{
		B _b = dynamic_cast<B&> (p);
		std::cout << "B" << std::endl;
		return ;
	}
	catch (std::exception  &e)
	{}
	try
	{
		C _c = dynamic_cast<C&> (p);
		std::cout << "C" << std::endl;
		return ;
	}
	catch (std::exception  &e)
	{}
}


int main(void)
{

	Base *ret = generate();


	identify (ret);
	identify (*ret);


	delete ret;

	return 0;
}