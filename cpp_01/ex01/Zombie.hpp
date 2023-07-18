#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class	Zombie
{
	public:
		void	announce( void );
		void	set_name(std::string	name);
		~Zombie (void);

	private:
		std::string	name;

};

Zombie* zombieHorde( int N, std::string name );

#endif