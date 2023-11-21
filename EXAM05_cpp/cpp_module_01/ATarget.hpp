#include <iostream>
#pragma once
#include "ASpell.hpp"

class ASpell;

class ATarget
{
	protected:
		std::string type;

	public:
		ATarget();
		~ATarget();
		ATarget(std::string name);
		const ATarget &operator=(const ATarget &src);
		ATarget(const ATarget &src);

		std::string	getType(void) const;
		void getHitBySpell(const ASpell &spell) const;

		virtual ATarget *clone() const = 0;
};