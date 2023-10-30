#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include <string>

#include "Bureaucrat.hpp"

#define RED "\033[0;91m"
#define NRM "\033[0;39m"
class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_signed; // 0 by default
		const int			_grade_tosign;
		const int			_grade_toexec;

	public:

		AForm();
		AForm(std::string name, int grade_tosign, int grade_toexec);
		AForm( AForm const & src );
		virtual ~AForm() = 0;

		AForm &		operator=( AForm const & rhs );

		std::string get_name() const;
		bool get_signed() const;
		int get_grade_tosign() const;
		int get_grade_toexec() const;


		void beSigned(Bureaucrat &bur);
		virtual	void my_action() const = 0;
		void execute(Bureaucrat const & executor) const;

		class GradeTooHighException: public std::exception
		{
			public:
				const virtual char *what () const throw();

		};

		class GradeTooLowException: public std::exception
		{
			public:
				const virtual char *what () const throw();
		};

		class FormUnsigned: public std::exception
		{
			public:
				const virtual char *what () const throw();
		};

};

std::ostream &			operator<<( std::ostream & os, AForm const & i );

#endif /* ************************************************************ AForm_H */