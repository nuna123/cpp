#include "ASpell.hpp"

ASpell::ASpell():name(),effects(){}

ASpell::~ASpell(){}
ASpell::ASpell(std::string name, std::string effects):name(name),effects(effects){}

const ASpell &ASpell::operator=(const ASpell &src)
{
	if (this == &src)
		return *this;
	name = src.getName();
	effects = src.getEffects();
	return *this;
}

// ASpell::ASpell(const ASpell &src):name(src.getName()),effects(src.getEffects()){}

std::string	ASpell::getName(void) const{return this->name;}
std::string	ASpell::getEffects(void) const{ return this->effects;}


void ASpell::launch(const ATarget &target) const
{
	target.getHitBySpell(*this);
}
