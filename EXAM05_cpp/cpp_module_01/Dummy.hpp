#include <iostream>
#pragma once
#include "ASpell.hpp"

class ATarget;
class ASpell;

class Dummy: public ATarget
{
	public:
		Dummy();
		~Dummy();
		Dummy(std::string name);
		const Dummy &operator=(const Dummy &src);
		Dummy(const Dummy &src);

		virtual ATarget *clone() const;
};