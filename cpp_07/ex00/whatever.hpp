
#ifndef TEMPLATES_HPP
# define TEMPLATES_HPP

#include <iostream>

template <typename T>
void swap(T &a, T &b)
{
	T p;
	p = a;
	a = b;
	b = p;
}

template <typename X>
X min(X a, X b)
{
	if (a > b)
		return b;
	return a;
}

template <typename B>
B max(B a, B b)
{
	if (a < b)
		return b;
	return a;
}
#endif