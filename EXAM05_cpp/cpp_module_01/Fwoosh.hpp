#include <iostream>

#include "ASpell.hpp"

class ASpell;

class Fwoosh : public ASpell
{
	public:
		Fwoosh();
		~Fwoosh();
		const Fwoosh &operator=(const Fwoosh &src);
		Fwoosh(const Fwoosh &src);
		
		virtual ASpell *clone() const;

};