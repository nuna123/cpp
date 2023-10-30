#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include <string>

# include "./AForm.hpp"

class AForm;

class ShrubberyCreationForm: public AForm
{
	private:
		std::string	_target;

	public:
		// Constructors
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm &copy);
		
		// Destructor
		~ShrubberyCreationForm();
		
		// Operators
		ShrubberyCreationForm & operator=(const ShrubberyCreationForm &assign);
		
		
		//inherited metod
		virtual	void my_action() const;
		
		//GETTER
		std::string get_target() const;
};

#endif