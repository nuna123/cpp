# include "Array.hpp"
/*
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Templates cannot be implemented in a cpp file separate to the header!
	https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file
	this file is only left for reference, taken out of makefile
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/
//Constructors
template <class T>
Array<T>::Array()
{
	this->_items = NULL;
	this->_size = 0;
};
template <class T>
Array<T>::Array(unsigned int size)
{
	this->_items = new T[size];
	this->_size = size;
};;
template <class T>
Array<T>::Array (const Array &src)
{
	this->_items = new T[src->_size];
	this->_size = src->_size;
	for(int i = 0; i < this->_size; i++)
		this->_items[i] = src->_items[i];
};
template <class T>
Array<T> &Array<T>::operator=(const Array<T> &src)
{
	this->_items = new T[src->_size];
	this->_size = src->_size;
	for(int i = 0; i < this->_size; i++)
		this->_items[i] = src->_items[i];
};

template <class T>
Array<T>::~Array()
{
	delete[] this->_items;
};

template <class T>
void Array<T>::print(void)
{
	for(int i = 0; i < this->size; i++)
	{
		std::cout << "[" << this->items[i] << "]";
		if (i < this->size - 1 )
		std::cout << ", ";
	}
	std::cout << std::endl;
};