#include <iostream>
 #pragma once

#include "ATarget.hpp"


class ATarget;

class ASpell
{
	protected:
		std::string name;
		std::string effects;

	public:
		ASpell();
		~ASpell();
		ASpell(std::string name, std::string effects);
		const ASpell &operator=(const ASpell &src);
		ASpell(const ASpell &src);

		std::string	getName(void) const;
		std::string	getEffects(void) const;

		virtual ASpell *clone() const = 0;

		void launch(const ATarget &target) const;
};