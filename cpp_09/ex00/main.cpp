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
	(void) argv;

	std::ifstream infile(argv[1]);
	
	//std::getline(infile, line)
	std::string line;
	std::string date_s, value_s;

	while (std::getline(infile, line))
	{
		if (line.find("|") == std::string::npos)
		{
			std::cout << "\tError! Invalid line format. => "
			<< line << std::endl;
		}else{
			date_s = line.substr(0, line.find("|"));
			value_s = line.substr(line.find("|") + 1);

			if ((float) std::atof(value_s.c_str()) < 0
			||std::atol(value_s.c_str()) > 2147483648
			|| std::atol(value_s.c_str()) < -2147483647)
				std::cout << "\tError! Value invalid. => "
				<< line << std::endl;
			else
				be->getValue(date_s,(float) std::atof(value_s.c_str()));
		}

	}

/* 
	std::ifstream infile(argv[1]);
	std::string tmp_line, date;
	std::string val1, val2, val3;
	float value;


	infile >> val1 >> val2 >> val3;

	
	while (infile >> date >> val1 >> val2)
	{
		// date = tmp_line.substr(0, tmp_line.find("|"));
		value = (float) std::atof(val2.c_str());

		if (value < 0)
			std::cout << "\tError: not a positive number. => "
			 << date
			 << " | "
			 << value
			 << std::endl;

		be->getValue(date, value);
	}

 */
	delete be;

	return 0;
}