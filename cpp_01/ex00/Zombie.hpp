#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class	Zombie
{
	public:
		void	announce( void );
		~Zombie (void);
		Zombie (std::string	name);

	private:
		std::string	name;


};

#endif