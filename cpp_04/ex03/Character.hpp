#ifndef CHARACTER_HPP
#define CHARACTER_HPP

# include <iostream>
# include "ICharacter.hpp"

class Character: private ICharacter
{
	public:
		~Character() {}
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);
};

#endif