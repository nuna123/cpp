#include <iostream>

class Harl
{
	private:
		void	debug( void ); // level 1
		void	info( void ); // level 2
		void	warning( void ); // level 3
		void	error( void ); // level 4

	public:
		void	complain( std::string level );
};