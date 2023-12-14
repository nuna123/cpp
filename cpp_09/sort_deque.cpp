#include <iostream>
#include <deque>
#include <algorithm>

void print_d (std::deque<int> *d)
{
	std::cout <<"[";
	std::deque<int>::iterator d_i = d->begin();
	while (d_i != d->end())
	{
		if (d_i != d->begin())
			std::cout <<", ";
		std::cout << *d_i;
		d_i++;
	}
	std::cout <<"]" << std::endl;

}



std::deque<int> *merge_deque(std::deque<int> *p1, std::deque<int> *p2)
{
	std::deque<int> *new_d = new std::deque<int>;
	std::deque<int>::iterator p1_i = p1->begin();
	std::deque<int>::iterator p2_i = p2->begin();



	while (p1_i != p1->end() || p2_i != p2->end())
	{
		if (p1_i == p1->end())
		{
			new_d->push_back(*p2_i);
			p2_i++;
		}
		else if (p2_i == p2->end())
		{
			new_d->push_back(*p1_i);
			p1_i++;
		}
		else
		{
			if (*p2_i < *p1_i)
			{
				new_d->push_back(*p2_i);
				p2_i++;
			}
			else
			{
				new_d->push_back(*p1_i);
				p1_i++;
			}
		}
	}
	return new_d;
}


std::deque<int> *sort_deque(std::deque<int> *deque)
{
	// print_d(deque);
	if (deque->size() < 3)
	{
		if (deque->size() < 2)
			return deque;
		else if (*deque->begin() > *(++deque->begin()))
			std::swap(*deque->begin(), *(++deque->begin()));
		return deque;
	}


	std::deque<int> *new_d;
	std::deque<int> *p1 = new std::deque<int>;
	std::deque<int> *p2 = new std::deque<int>;

	std::deque<int>::iterator it = deque->begin();
	for (int i = 0; i < deque->size(); i++)
	{
		if (i < deque->size() / 2)
			p1->push_front(*it);
		else
			p2->push_front(*it);
		it++;
	}
	delete deque;


	p1 = sort_deque (p1);
	p2 = sort_deque (p2);

	deque = merge_deque(p1, p2);
	delete p1;
	delete p2;

	return deque;
}

int main(void)
{
	///values for deque
		//if the same random number is generated twice,
		//	it will only be added once to the deque since it doesnt allow duplicates.
	int min_value = -100000;
	int max_value = 100000;

	unsigned int size = 20;
	////////////////////

	std::srand(time(NULL));
	std::deque<int> *int_deque = new std::deque<int>;
	int num;


	//creating deque of SIZE random integers within the deque bounds
	for (int i = 0;
		int_deque->size() < size
			&& int_deque->size() < (unsigned int) max_value - min_value;
		i++)
	{
		num = min_value + ( std::rand() % ( max_value - min_value + 1 ));
		int_deque->push_back(num);
	}



	int_deque = sort_deque(int_deque);

	print_d(int_deque);
	delete int_deque;

}