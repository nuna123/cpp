#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

//class Container will be the underlying container that
//	MutantStack is based on. deque by default
//, T is the Type of data.

template <
	typename T,
	typename Container = std::deque<T>
	>
class MutantStack: public std::stack<T, Container>{
	public:
		MutantStack();
		MutantStack(const MutantStack &ms);
		~MutantStack();
		const MutantStack &operator=(const MutantStack &ms);

		typedef typename Container::iterator iterator;

		iterator begin(){return this->c.begin();}
		iterator end(){return this->c.end();}


};

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(){}

template <typename T, class Container>
MutantStack<T, Container>::MutantStack(const MutantStack &ms)
{
	*this = ms;
}

template <typename T, class Container>
MutantStack<T, Container>::~MutantStack(){}

template <typename T, class Container>
const MutantStack<T, Container> &
	MutantStack<T, Container>::operator=(const MutantStack &ms)
{
		std::stack<T, Container>::operator=(ms);
}




#endif