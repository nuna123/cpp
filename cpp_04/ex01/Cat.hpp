#ifndef CAT_HPP
#define CAT_HPP

#include "Brain.hpp"
#include "Animal.hpp"

class Cat: public Animal
{
	private:
		Brain *brain;

	public:
		Cat();
		~Cat();
		Cat(const Cat &cat);
		Cat &operator=(const Cat &cat);
		void		make_sound(void) const;
		const Brain	&get_brain(void) const;

};

#endif