#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	this->_values = src.getValues();
}

const BitcoinExchange &BitcoinExchange::operator =(const BitcoinExchange &src)
{
	this->_values = src.getValues();
	return *this;
}

BitcoinExchange::~BitcoinExchange()
{}

const std::map <std::string, float> &BitcoinExchange::getValues() const
{
	return _values;
}

//METHODS

static void check_date_validity(std::string &date)
{
	std::string tmp;
	std::string newstr = date;
	int year;
	int month;
	int day;

	//year
	year = std::atoi (date.substr(0, date.find('-')).c_str());
	if (year < 0 || year > 9999)
	{
		std::cout << "\tError: year invalid!";
		throw BitcoinExchange::InvalidDateException();
	}

	//month
	newstr = newstr.substr(newstr.find('-') + 1);

	month = std::atoi(newstr.substr(0, newstr.find('-')).c_str());
	if (month < 1 || month > 12)
	{
		std::cout << "\tError: month invalid!";
		throw BitcoinExchange::InvalidDateException();
	}

	//day
	newstr = newstr.substr(newstr.find('-') + 1);
	if (newstr.find("-") != std::string::npos)
	{
		std::cout << "\tError: format invalid!";
		// std::cout << newstr.find("-") ;
		throw BitcoinExchange::InvalidDateException();
	}
	
	day = std::atoi(newstr.c_str());
		//find out ho many days are in that month
	int daysInMonth;
	switch (month) {
	case 2:  // February
		daysInMonth = (year % 4 == 0) ? 29 : 28; //leap year
		break;
	case 4: case 6: case 9: case 11:  // April, June, September, November
		daysInMonth = 30;
		break;
	default:
		daysInMonth = 31;
		break;
	}
	if (day < 0 || day > daysInMonth)
		{
		std::cout << "\tError: day invalid!" << std::endl;
		throw BitcoinExchange::InvalidDateException();
	}
}

void	BitcoinExchange::addValue(std::string date, float bc)
{
	//check  that date is valid, if it is, add to map
	try
	{
		check_date_validity(date);
	
		this->_values.insert(
		std::pair<std::string, float>(date, bc));
	}catch (std::exception &e)
	{	std::cout << e.what() << std::endl;}

}


void	BitcoinExchange::getValue(std::string date, float er) const
{
	std::map<std::string, float>::const_iterator val;
	try
	{	
		//check if date is valid
		check_date_validity(date);
		// std::cout << "date ok!" << std::endl;


		if (_values.find(date) == _values.end())
			val = (--_values.lower_bound(date));
		else
			val = (_values.find(date));
	
		if ( er * val->second > 2147483648
			|| er * val->second < -2147483647)
		{
			std::cout << "\tError: output too large. ("
			<< er << " * " << val->second << ")" << std::endl;
			return;
		}
		std::cout
			<< date
			<< " => "
			<< er
			<< " = "
			<< er * val->second
			<< std::endl;
	}catch (std::exception &e)
	{
			// std::cout << e.what();
			std::cout << " => " << date.c_str()<< std::endl;
	}


}

void	BitcoinExchange::read_csv(std::string filepath)
{
	std::ifstream infile(filepath.c_str());
	std::string tmp_line;
	std::string date, value;

	infile >> tmp_line;
	while (infile >> tmp_line)
	{
		date = tmp_line.substr(0, tmp_line.find(","));
		value = tmp_line.substr(tmp_line.find(",") + 1);

		if (std::atol(value.c_str()) > 2147483648
		 || std::atol(value.c_str()) < -2147483647)
			std::cout << "\tError: invalid Value! =>"
			<< tmp_line
			<< std::endl;
		else
			addValue(date, (float) std::atof(value.c_str()));
	}
}

