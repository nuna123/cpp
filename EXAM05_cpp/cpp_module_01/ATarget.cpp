
#include "ATarget.hpp"



ATarget::ATarget():type() {}
ATarget::~ATarget(){}
ATarget::ATarget(std::string type): type (type){}
const ATarget &ATarget::operator=(const ATarget &src)
{
	if (this == &src)
		return *this;
	this->type = src.getType();

	return *this;
}
// ATarget::ATarget(const ATarget &src);

std::string	ATarget::getType(void) const{return this->type;}

void ATarget::getHitBySpell(const ASpell &spell) const
{
	std::cout	<< this->getType()
				<< " has been "
				<< spell.getEffects()
				<< "!" << std::endl;
}