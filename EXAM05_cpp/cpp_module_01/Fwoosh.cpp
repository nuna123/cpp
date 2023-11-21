#include "Fwoosh.hpp"

Fwoosh::Fwoosh(){
	this->name = "Fwoosh";
	this->effects = "fwooshed";
}

Fwoosh::~Fwoosh(){}
// Fwoosh::Fwoosh(std::string name, std::string effects):name(name),effects(effects){}

// Fwoosh::Fwoosh(const Fwoosh &src):name(src.getName()),effects(src.getEffects()){}

ASpell *Fwoosh::clone() const
{
	return (new Fwoosh());
}
