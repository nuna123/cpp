#include "./Span.hpp"


int main(void)
{

	///values for set
		//if the same random number is generated twice,
		//	it will only be added once to the set since it doesnt allow duplicates.
	int min_value = -100000;
	int max_value = 100000;

	unsigned int size = 10000;
	////////////////////

	std::srand(time(NULL));
	std::set<int> int_set;
	int num;


	//creating set of SIZE random integers within the set bounds
	for (int i = 0;
		int_set.size() < size
			&& int_set.size() < (unsigned int) max_value - min_value;
		i++)
	{
		num = min_value + ( std::rand() % ( max_value - min_value + 1 ));
		int_set.insert(num);
	}
	std::cout << "\nint set size: " << int_set.size() << std::endl;



	Span *s = new Span(100000);
	try
	{
		s->addNumber(int_set.begin(), int_set.end());
		s->addNumber(3023);


	std::cout << "\n" << *s << "\n" << std::endl;

	std::cout << "size: " << s->getSize() << "\n" << std::endl;
	std::cout << "LONGEST SPAN: " << s->longestSpan() << std::endl;
	std::cout << "SHORTEST SPAN: " <<s->shortestSpan() << std::endl;
}
catch(std::exception &e)
{std::cout << e.what() << std::endl;}
	delete s;

	return 0;
}