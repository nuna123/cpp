#include "./Span.hpp"
#include <iostream>
#include <set>
#include <cstdlib>
#include <ctime>
#include <iterator>

int main(void)
{
	std::srand(time(NULL));
	std::set<int> int_set;
	int num;


	for (int i = 0; i < 10; i++)
	{
		num = -1000 + ( std::rand() % ( 1000 - -1000 + 1 ) );
		int_set.insert(num);
	}
	Span *s = new Span(190);
try{
	s->addNumber(int_set.begin(), int_set.end());
	s->addNumber(3023);


	std::cout << "\n" << *s << std::endl;
	std::cout << "LONGEST SPAN: " << s->longestSpan() << std::endl;
	std::cout << "SHORTEST SPAN: " <<s->shortestSpan() << std::endl;
}
catch(std::exception &e)
{std::cout << e.what() << std::endl;}
	delete s;

	return 0;
}