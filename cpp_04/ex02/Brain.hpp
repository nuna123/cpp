#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string ideas[100];

	public:
		Brain();
		Brain(Brain const &brain);
		Brain(std::string idea);
		~Brain();
		Brain &operator=(Brain const &brain);
		const std::string get_idea(int index) const;
};

#endif