#include "Span.hpp"

// private
Span::Span() : _max_size(0) {}

Span::Span(unsigned int max_size) : _max_size(max_size) {}
Span::~Span() {}
const Span &Span::operator=(const Span &src)
{
	this->_ints = src.getInts();
	return *this;
}

Span::Span(const Span &src)
	: _ints(src.getInts()), _max_size(src.getMaxSize())
{
}

const unsigned int &Span::getMaxSize() const { return this->_max_size; }

void Span::addNumber(int num)
{
	if (this->_ints.size() >= this->getMaxSize())
		throw SpanFullException();
	this->_ints.insert(num);
	// std::cout << "Span: added " << num << std::endl;
}

void Span::addNumber
	(std::set<int>::iterator first, std::set<int>::iterator last)
{	
	this->_ints.insert(first, last);
	if (this->_ints.size() > this->getMaxSize())
		throw SpanFullException();
	/* 
	std::cout << "Span: added:";
	while (first != last)
	{
		std::cout << *first << " ";
		first++;
	}
	std::cout << std::endl;

 */
}

const std::set<int> &Span::getInts() const
{
	return (_ints);
}
int Span::longestSpan() const
{
	if (this->_ints.size() < 2)
		throw SpanEmptyException();
	return (*(this->_ints.rbegin()) - *(this->_ints.begin()));
}

int Span::shortestSpan() const
{
	if (this->_ints.size() < 2)
		throw SpanEmptyException();
	int shortest_span = *(this->_ints.rbegin());

	std::set<int>::iterator prev = this->_ints.begin();
	for (std::set<int>::iterator i = this->_ints.begin()++;
		i != this->_ints.end(); i++)
	{
		if (i != this->_ints.begin() &&
			*i - *(prev) < shortest_span)
		{
			shortest_span = (*i - *(prev));
		}
		prev = i;
	}
	return shortest_span;
}

std::ostream &operator << (std::ostream &o, const Span &span)
{
	std::set<int> int_set = span.getInts();

	o << "[";
	for(std::set<int>::iterator i = int_set.begin();
		i != int_set.end();
		i++)
		{
			o << *i;
			if(*i != *int_set.rbegin())
				o << ", ";
		}
	o << "]";
	return o;
}
