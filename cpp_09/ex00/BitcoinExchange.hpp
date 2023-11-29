#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <cstdlib>
#include <map>

#include <fstream>


#define RED "\033[0;91m"
#define NRM "\033[0;39m"

class BitcoinExchange
{
	private:
		std::map <std::string, float> _values;

	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		const BitcoinExchange &operator =(const BitcoinExchange &src);
		~BitcoinExchange();

		const std::map <std::string, float>	&getValues() const;
		void	addValue(std::string date, float bc);
		void	getValue(std::string date, float er) const;
		void	read_csv(std::string filepath);


		class InvalidDateException: public std::exception
		{
			const virtual char *what() const throw()
			{return (RED "Date invalid!" NRM);}
		};
};

#endif