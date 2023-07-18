#include "Harl.hpp"

void	Harl::debug( void ){std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;}; // level DEBUG
void	Harl::info( void ){std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" <<std::endl;} // level INFO
void	Harl::warning( void ){std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." <<std::endl;} // level WARNING
void	Harl::error( void ){std::cout << "This is unacceptable! I want to speak to the manager now." <<std::endl;} // level ERROR

void	Harl::complain( std::string level )
{
	void (Harl::*methodPtrs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string level_strs[4] = {"DEBUG","INFO","WARNING","ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == level_strs[i])
		{
			(this->*methodPtrs[i])();
			return ;
		}
	}
	std::cout << "ERR! Harl doesnt know how to do that." << std::endl;
}
