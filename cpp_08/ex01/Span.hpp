#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <set>
#include <algorithm>

#define RED "\033[0;91m"
#define NRM "\033[0;39m"
//a set is an associative container, keeps elements
//	in sorted order regardless o the order they wwere inserted.

class Span
{
	private:
		std::set<int>	_ints;
		const unsigned int		_max_size;
		Span();

	public:
		Span(unsigned int max_size);
		~Span();
		const Span &operator=(const Span &src);
		Span(const Span &src);

		const unsigned int	&getMaxSize() const;
		const std::set<int>	&getInts() const;

		void	addNumber(int num);
		void	addNumber
			(std::set<int>::iterator first, std::set<int>::iterator last);
		int		longestSpan() const;
		int		shortestSpan() const;

		class SpanFullException: public std::exception
		{
			virtual const char *what() const throw()
			{return RED "Span is full!" NRM;}
		};
		class SpanEmptyException: public std::exception
		{
			virtual const char *what() const throw()
			{return RED "Span is Empty!" NRM;}
		};
};

std::ostream &operator << (std::ostream &o, const Span &span);

#endif
