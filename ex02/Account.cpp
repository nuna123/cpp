// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

#include "Account.hpp"

#include <ctime>
#include <iostream>
#include <iomanip>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	std::time_t result = std::time(NULL);

	std::cout << std::setfill('0') <<"[" << 1900 + std::localtime(&result)->tm_year
				<< std::setw(2) << 1 + std::localtime(&result)->tm_mon
				<<  std::setw(2) << std::localtime(&result)->tm_mday
				<<  "_"
				<<  std::setw(2) << std::localtime(&result)->tm_hour
				<<  std::setw(2) << std::localtime(&result)->tm_min
				<<  std::setw(2) << std::localtime(&result)->tm_sec 
				<< "] " << std::flush;
}

int	Account::getNbAccounts( void ){return _nbAccounts;}
int	Account::getTotalAmount( void ){return _totalAmount;}
int	Account::getNbDeposits( void ){return _totalNbDeposits;}
int	Account::getNbWithdrawals( void ){return _totalNbWithdrawals;}

//display accounts:[NUM OF ACCTS];total:[TOTAL AMOUNT];deposits:0;withdrawals:0
void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals()
		<< std::endl;
}

Account::Account( int initial_deposit ) //constructor
{
	_nbAccounts ++;
	_totalAmount += initial_deposit;

	this->_accountIndex = _nbAccounts - 1;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	this->_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "created" << std::endl;
}

Account::~Account( void ) //Destructor
{
	_nbAccounts --;
	_totalAmount -= this->_amount;
	this->_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_totalNbDeposits++;
	_totalAmount += deposit;

	this->_nbDeposits++;
	this->_amount += deposit;
	
	this->_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount - deposit << ";"
				<< "deposit:" << deposit << ";"
				<< "amount:" << _amount << ";"
				<< "nb_deposits:" << this->_nbDeposits
				<< std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	this->_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "p_amount:" << _amount << ";"
				<< "withdrawal:";

	if (this->checkAmount() < withdrawal)
	{
		std::cout << "refused" << std::endl;
		return false;
	}
	_totalNbWithdrawals++;
	_totalAmount -= withdrawal;

	this->_nbWithdrawals++;
	this->_amount -= withdrawal;
	std::cout	<< withdrawal << ";"
				<< "amount:" << _amount << ";"
				<< "nb_withdrawals:" << _nbWithdrawals << std::endl;
	return true;
}

int		Account::checkAmount( void ) const
{
	return this->_amount;
}
void	Account::displayStatus( void ) const
{
	this->_displayTimestamp();
	std::cout	<< "index:" << _accountIndex << ";"
				<< "amount:" << _amount << ";"
				<< "deposits:" << _nbDeposits << ";"
				<< "withdrawals:" << _nbWithdrawals << std::endl;
}