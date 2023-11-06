
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

#define RED "\033[0;91m"
#define NRM "\033[0;39m"

template <class T>
class Array
{
	private:
		T				*_items;
		unsigned int	_size;

	public:
		Array();
		Array(unsigned int size);
		Array (const Array &src);
		Array &operator=(const Array &src);
		~Array();

		void	print();
		int		size() const;
		T &operator [](unsigned int i);



		class OutOfBoundException : public std::exception
		{
			const virtual char *what() const throw()
			{return (RED "Index Out Of Bounds !" NRM);}
		};

};



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
};
template <class T>
Array<T>::Array (const Array &src)
{
	this->_items = new T[src._size];
	this->_size = src._size;
	for(unsigned int i = 0; i < this->_size; i++)
		this->_items[i] = src._items[i];
};
template <class T>
Array<T> &Array<T>::operator=(const Array<T> &src)
{
	delete[] this->_items;
	this->_items = new T[src._size];
	this->_size = src._size;
	for(unsigned int i = 0; i < this->_size; i++)
		this->_items[i] = src._items[i];
	return *this;
};

template <class T>
Array<T>::~Array()
{
	delete[] this->_items;
};

template <class T>
void Array<T>::print(void)
{
	for(unsigned int i = 0; i < this->_size; i++)
	{
		std::cout << "[" << this->_items[i] << "]";
		if (i < this->_size - 1 )
		std::cout << ", ";
	}
	std::cout << std::endl;
};
template <class T>
int Array<T>::size(void) const {return this->_size;}

template <class T>
T &Array<T>::operator[](unsigned int i)
{
	if (i < 0 || i >= this->_size)
		throw Array<T>::OutOfBoundException();
	else
		return this->_items[i];

};


#endif