#include "Dummy.hpp"

Dummy::Dummy(){
	this->type = "Target Practice Dummy";
}

Dummy::~Dummy(){}
// Dummy::Dummy(std::string name, std::string effects):name(name),effects(effects){}

// Dummy::Dummy(const Dummy &src):name(src.getName()),effects(src.getEffects()){}

ATarget *Dummy::clone() const
{
	return (new Dummy());
}
