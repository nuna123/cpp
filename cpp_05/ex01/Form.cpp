#include "Form.hpp"

static void check_grade(int grade)
{
	if (grade > 150)
		throw Form::GradeTooLowException();
	if (grade < 1)
		throw Form::GradeTooHighException();
}

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/


Form::Form(): _name("form"), _signed(0), _grade_tosign(1), _grade_toexec(1)
{
	check_grade(_grade_tosign);
	check_grade(_grade_toexec);
/* 	if (_grade_toexec > 150 || _grade_tosign > 150)
		throw Form::GradeTooLowException();
	if (_grade_toexec <1 || _grade_tosign <1)
		throw Form::GradeTooHighException(); */
}
Form::Form(std::string name, int grade_tosign, int grade_toexec)
	: _name(name), _signed(0), _grade_tosign(grade_tosign), _grade_toexec(grade_toexec)
{
	check_grade(_grade_tosign);
	check_grade(_grade_toexec);
}

Form::Form( const Form & src ):	_name(src.get_name()), _signed(src.get_signed()), _grade_tosign(src.get_grade_tosign()), _grade_toexec(src.get_grade_toexec())
{
	check_grade(_grade_tosign);
	check_grade(_grade_toexec);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &				Form::operator=( Form const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	(void) rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o	<< "Name: "				<< i.get_name() << "\n"
		<< "signed: "			<< i.get_signed() << "\n"
		<< "grade to sign: "	<< i.get_grade_tosign() << "\n"
		<< "grade to execute: "	<< i.get_grade_toexec()<< "\n";
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(Bureaucrat & bur)
{
	if (bur.getGrade() <= this->get_grade_tosign())
	{
		this->_signed = 1;
	}
	else
		throw Form::GradeTooLowException();
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string	Form::get_name() const
{
	return this->_name;
}
bool Form::get_signed() const
{
	return this->_signed;
}
int Form::get_grade_tosign() const
{
	return this->_grade_tosign;
}
int Form::get_grade_toexec() const
{
	return this->_grade_toexec;
}

/*
** ----------------------------- EXCEPTIONS ----------------------------------
*/

	const char * Form::GradeTooHighException::what () const throw ()
	{return (RED "Grade Too High!" NRM);};
	const char * Form::GradeTooLowException::what () const throw ()
	{return (RED "Grade Too Low!" NRM);};



/* ************************************************************************** */