
#pragma once
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
		void	set_name(char	*name);
		~Zombie (void);

	private:
		const char	*name;

};

Zombie* zombieHorde( int N, std::string name );

#endif