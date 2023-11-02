
#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>
#include <string>

template <typename T>
void iter(T *arr, int arrlen, void (*func)(T &element))
{
	for(int i = 0; i < arrlen; i++)
	{
		func(arr[i]);
	}
}
template <typename U>
void arr_print(U *arr, int arrlen)
{
	for(int i = 0; i < arrlen; i++)
	{
		std::cout << "[" << arr[i] << "]";
		if (i < arrlen - 1 )
		std::cout << ", ";
	}
	std::cout << std::endl;
}

#endif