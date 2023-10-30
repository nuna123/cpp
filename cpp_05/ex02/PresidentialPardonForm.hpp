#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>

# include "./AForm.hpp"

class AForm;

class PresidentialPardonForm: public AForm
{
	private:
		std::string	_target;

	public:
		// Constructors
		PresidentialPardonForm(std::string target);
		PresidentialPardonForm(const PresidentialPardonForm &copy);
		
		// Destructor
		~PresidentialPardonForm();
		
		// Operators
		PresidentialPardonForm & operator=(const PresidentialPardonForm &assign);
		
		//inherited metod
		virtual	void my_action();
		
		//GETTER
		std::string get_target() const;

};

#endif