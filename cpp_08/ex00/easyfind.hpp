#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

#define RED "\033[0;91m"
#define NRM "\033[0;39m"


class NotFoundException : public std::exception
{
	virtual const char *what() const throw()
	{return (RED "int not found!" NRM);}
};
template <typename T>
void easyfind (const T &t, int compare)
{

	if ( std::find(t.begin(), t.end(), compare) != t.end())
		std::cout << "Found!" << std::endl;
	else
		std::cout << "Not Found :(" << std::endl;
		// return std::find(t.begin(), t.end(), compare);
/* 	for (typename T::iterator it = t.begin();
		it != t.end();
		it++)
	{
		if (*it == compare)
			return it;
	} */

	// throw NotFoundException();
	// return t.end();
};


#endif