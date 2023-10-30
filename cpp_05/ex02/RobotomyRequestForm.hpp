#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include <cstdlib>
# include <time.h>

# include "./AForm.hpp"

class AForm;

class RobotomyRequestForm: public AForm
{
	private:
		std::string	_target;

	public:
		// Constructors
		RobotomyRequestForm(std::string target);
		RobotomyRequestForm(const RobotomyRequestForm &copy);
		
		// Destructor
		~RobotomyRequestForm();
		
		// Operators
		RobotomyRequestForm & operator=(const RobotomyRequestForm &assign);
		
		
		//inherited metod
		virtual	void my_action() const;
		
		//GETTER
		std::string get_target() const;
};

#endif