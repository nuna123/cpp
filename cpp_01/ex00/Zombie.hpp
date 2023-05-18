
#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

class	Zombie
{
	public:
		void	announce( void );
		~Zombie (void);
		Zombie (const char	*name);

	private:
		const char	*name;

};

#endif