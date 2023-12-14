#include "MutantStack.hpp"


int main(){
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);

	std::cout << mstack.top() << std::endl;

	mstack.pop();
	std::cout << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator start_it = mstack.begin();
	MutantStack<int>::iterator end_it = mstack.end();
	++start_it;
	--start_it;
	while (start_it != end_it)
	{
		std::cout << *start_it << std::endl;
		++start_it;
	}
	return 0;
}