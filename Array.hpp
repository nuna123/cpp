
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <class T>
class Array
{
	private:
		T				*_items;
		unsigned int	_size;

	public:
		Array(): _items(NULL), _size(0){};
		Array(unsigned int size)
		{
			this->_items = new T[_size];
			this->_size = _size;
		};
		Array (const Array &src){
			this->_items = new T[src->_size];
			this->_size = src->_size;
			for(int i = 0; i < this->_size; i++)
				this->_items[i] = src->_items[i];
		};
		Array &operator=(const Array &src){
			this->_items = new T[src->_size];
			this->_size = src->_size;
			for(int i = 0; i < this->_size; i++)
				this->_items[i] = src->_items[i];
		};
		~Array(){
			delete[] this->_items;
		};

		void print();
};
#endif