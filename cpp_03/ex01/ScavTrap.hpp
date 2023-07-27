#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap
{
	private:
		bool	GateKeepMode;
	public:
		ScavTrap(void);
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &scavTrap);
		~ScavTrap(void);

		ScavTrap& operator=(ScavTrap const &scavTrap);
		void	guardGate(void);

		void		attack(const std::string& target);

};



////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////		INFO	////////////////////////////////////////////
/*
	In C++, derived classes cannot inherit the constructors of their base classes
	-- nor can they inherit assignment operators.
	VISIBILITY MODES:
		private:
			When the base class is privately inherited by the derived class,
			PUBLIC members of the base class becomes the PRIVATE members of the derived class.
			Therefore, the public members of the base class are not accessible by the objects
			of the derived class only by the member functions of the derived class.
		Public:
			When the base class is publicly inherited by the derived class,
			PUBLIC members of the base class also become the PUBLIC members of the derived class.
			Therefore, the public members of the base class are accessible by the objects
			of the derived class as well as by the member functions of the base class.

	The private members of the base class are never inherited.
	To solve this - the PROTECTED mode exists. the members declared as protected
	will be accessible to all the member functions within the class as well as
	the class immediately derived from it.
*/
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
#endif