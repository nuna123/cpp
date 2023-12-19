#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "./btc [input file path]!" << std::endl;
		return 1;
	}

	BitcoinExchange *be = new BitcoinExchange();
	be->read_csv("data.csv");

	std::ifstream infile(argv[1]);

	//std::getline(infile, line)
	std::string line;
	std::string date_s, value_s;
	bool first = true;

	while (std::getline(infile, line))
	{
		if (line.find("|") == std::string::npos)
		{
			std::cout << "\tError! Invalid line format. => "
			<< line << std::endl;
		}else{
			date_s = line.substr(0, line.find("|"));
			value_s = line.substr(line.find("|") + 1);

			date_s.erase(date_s.find(" "), 1);
			value_s.erase(value_s.find(" "), 1);
			if (date_s == "date" && value_s == "value" && first)
				first = false;
			else if ((float) std::atof(value_s.c_str()) < 0
			|| std::atol(value_s.c_str()) > 2147483648
			|| std::atol(value_s.c_str()) < -2147483647
			|| (std::atol(value_s.c_str()) == 0 && value_s != "0"))
				std::cout << "\tError! Value invalid. => "
				<< value_s << std::endl;
			else
				be->getValue(date_s,(float) std::atof(value_s.c_str()));
		}

	}

	delete be;

	return 0;
}