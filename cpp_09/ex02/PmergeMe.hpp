#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <deque>
#include <list>
#include <algorithm>
#include <iomanip>
/*

#include <time>
#include <clock>

*/

class PmergeMe
{
	private:
		PmergeMe();
		PmergeMe(const PmergeMe &src);
		const PmergeMe &operator=(const PmergeMe &src);
		~PmergeMe();
	public:
		static void sort(int argc, char **argv);

};

#endif