
#include "iter.hpp"

void negativy(int &i)
{
	i*= -1;
}
void upperize (std::string &s)
{
	for (unsigned int i = 0; i < s.length(); i++)
		s[i] = toupper(s.at(i));
}

int main( void ) {

	int arrlen = 5;

std::cout << "INT ARR:" << std::endl;
	int		int_arr[arrlen];
	for (int i = 0; i < arrlen; i++)
		int_arr[i] = i + 1;


	::arr_print(int_arr, arrlen);
	::iter(int_arr, arrlen, negativy);
	::arr_print(int_arr, arrlen);


std::cout << "\nSTRING ARR:" << std::endl;

	arrlen = 3;
	std::string str_arr[] = {"hello", "world", "!"};

	::arr_print(str_arr, 3);
	::iter(str_arr, 3, upperize);
	::arr_print(str_arr, 3);



	return 0;
}