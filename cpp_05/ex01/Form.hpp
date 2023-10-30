#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>

#include "Bureaucrat.hpp"

#define RED "\033[0;91m"
#define NRM "\033[0;39m"
class Bureaucrat;

class Form
{
	private:
		const std::string	_name;
		bool				_signed; // 0 by default
		const int			_grade_tosign;
		const int			_grade_toexec;

	public:

		Form();
		Form(std::string name, int grade_tosign, int grade_toexec);
		Form( Form const & src );
		~Form();

		Form &		operator=( Form const & rhs );

		std::string get_name() const;
		bool get_signed() const;
		int get_grade_tosign() const;
		int get_grade_toexec() const;


		void beSigned(Bureaucrat & bur);

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

};

std::ostream &			operator<<( std::ostream & os, Form const & i );

#endif /* ************************************************************ FORM_H */