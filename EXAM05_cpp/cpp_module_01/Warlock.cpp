
#include "Warlock.hpp"

/*Warlock::Warlock():name ("default_name"), title ("default_title")
{}*/
Warlock::~Warlock()
{
	delete this->spells;
	std::cout	<< this->getName() <<  ": My job here is done!" << std::endl;

}
Warlock::Warlock(std::string name, std::string title):name (name), title (title), spells(new std::vector<ASpells *>)
{
	std::cout	<< this->getName() <<  ": This looks like another boring day." << std::endl;
}
/*const Warlock &Warlock::operator=(const Warlock &src)
{
	if (this == &src)
		return *this;

	this->name = src.getName();
	this->title = src.getTitle();

	return *this;
}
Warlock::Warlock(const Warlock &src):name (src.getName()), title (src.getTitle())
{}*/

const std::string &Warlock::getName(void) const { return this->name; }
const std::string &Warlock::getTitle(void) const { return this->title; }

// void Warlock::setName (const std::string &name){this->name = name;}
void Warlock::setTitle (const std::string &title){this->title = title;}


void Warlock::introduce() const
{
	std::cout	<< this->getName() <<  ": "
				<< "I am " << this->getName()
				<< ", " << this->getTitle()
				<< "!" <<std::endl;

}


void Warlock::learnSpell(ASpell *spell_ptr)
{
	this->spells.
}

