#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <algorithm>

class PmergeMe
{
	private:
		PmergeMe(const PmergeMe &src);
		const PmergeMe &operator=(const PmergeMe &src);
	public:
		PmergeMe();
		PmergeMe(int argc, char **argv);
		~PmergeMe();

};

#endif