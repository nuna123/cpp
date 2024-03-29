
#include	"DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap didi("didi");

	didi.stats();

	std::cout << std::endl;
	didi.whoAmI();

	std::cout << std::endl;
	didi.attack("ATTACKEE");
}

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
	will be accessible as PRIVATE both in the base and derived class.
*/
////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////
