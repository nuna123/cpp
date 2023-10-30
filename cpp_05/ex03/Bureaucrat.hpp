#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

#define RED "\033[0;91m"
#define NRM "\033[0;39m"

#include "AForm.hpp"
class AForm;

class Bureaucrat
{

	private:
		const std::string	_name;
		int					_grade;


	public:

		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		Bureaucrat &		operator=( Bureaucrat const & rhs );

		int getGrade() const;
		std::string getName() const;

		void gradeUp();
		void gradeDown();
		void signForm(AForm &AForm);
		void executeForm(AForm const & form);


//--------------------EXCEPTIONS----------------------------
// the original std::exception prototype:
//		virtual const char* what() const throw();

		class GradeTooHighException : public std::exception {
			public:
				const virtual char * what () const throw ();
		};

		class GradeTooLowException : public std::exception {
			public:
				const virtual char * what () const throw();
		};


};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );

#endif /* ****************************************************** BUREAUCRAT_H */