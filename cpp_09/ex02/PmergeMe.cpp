#include "PmergeMe.hpp"

#define SHORTEN true

void print_l (std::list<int> *d)
{
	std::cout <<"[";
	std::list<int>::iterator d_i = d->begin();
	while (d_i != d->end())
	{
		if (d_i != d->begin())
			std::cout <<", ";
		std::cout << *d_i;
		d_i++;
	}
	std::cout <<"]" << std::endl;
}

void print_d (std::deque<int> *d)
{
	std::cout <<"[";
	for (unsigned int i = 0; i < d->size() ; i++)
	{
		if (SHORTEN && i >= 5)
		{
			std::cout <<"...]"<< std::endl;
			return;
		}
		if (i != 0)
			std::cout <<", ";
		std::cout << (*d)[i];
	}
	std::cout <<"]" << std::endl;
}

std::list<int> *merge_list(std::list<int> *p1, std::list<int> *p2)
{
	std::list<int> *new_d = new std::list<int>;
	std::list<int>::iterator p1_i = p1->begin();
	std::list<int>::iterator p2_i = p2->begin();

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

std::list<int> *sort_list(std::list<int> *list)
{
	if (list->size() < 3)
	{
		if (list->size() < 2)
			return list;
		else if (*list->begin() > *(++list->begin()))
			std::swap(*list->begin(), *(++list->begin()));
		return list;
	}
	std::list<int> *p1 = new std::list<int>;
	std::list<int> *p2 = new std::list<int>;

	std::list<int>::iterator it = list->begin();
	for (unsigned int i = 0; i < list->size(); i++)
	{
		if (i < list->size() / 2)
			p1->push_front(*it);
		else
			p2->push_front(*it);
		it++;
	}
	delete list;
	p1 = sort_list (p1);
	p2 = sort_list (p2);
	list = merge_list(p1, p2);
	delete p1;
	delete p2;

	return list;
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

	std::deque<int> *p1 = new std::deque<int>;
	std::deque<int> *p2 = new std::deque<int>;

	std::deque<int>::iterator it = deque->begin();
	for (unsigned int i = 0; i < deque->size(); i++)
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

void PmergeMe::sort(int argc, char **argv)
{
	std::deque<int> *deque = new std::deque<int>;
	std::list<int> *list = new std::list<int>;

	clock_t time_start;

	for (int i = 1; i < argc ; i++)
	{
		for (char *c = argv[i]; *c; c++)
		{
			if (std::atoi(argv[i]) < 0 || !std::isdigit(*c))
			{
				std::cout << "Error!\n\tOnly positive integers allowed." << argv[i]<< std::endl;
				delete deque;
				delete list;
				return;
			}
		}
		deque->push_back(std::atoi(argv[i]));
		list->push_back(std::atoi(argv[i]));
	}

std::cout << "Unsorted list: (" << deque->size() << " items):\n\t";
	print_d(deque);


// std::cout << std::fixed;
std::cout << "\nDEQUE: ";
	time_start = clock();
	deque = sort_deque(deque);

	std::cout << "sorting time: " << (((double)(clock() - time_start)) / CLOCKS_PER_SEC) * 1000 << " ms"<< std::endl;
std::cout << "LIST: ";
	time_start = clock();
	list = sort_list(list);
	std::cout << "sorting time: " << (((double)(clock() - time_start)) / CLOCKS_PER_SEC) * 1000<< " ms"<< std::endl;

std::cout << "\nsorted list: \n\t";
	print_d(deque);
}