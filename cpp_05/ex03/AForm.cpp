#include "AForm.hpp"

static void check_grade(int grade)
{
	if (grade > 150)
		throw AForm::GradeTooLowException();
	if (grade < 1)
		throw AForm::GradeTooHighException();
}

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/


AForm::AForm(): _name("default"), _signed(false), _grade_tosign(1), _grade_toexec(1)
{
	check_grade(_grade_tosign);
	check_grade(_grade_toexec);
}
AForm::AForm(std::string name, int grade_tosign, int grade_toexec)
	: _name(name), _signed(0), _grade_tosign(grade_tosign), _grade_toexec(grade_toexec)
{
	check_grade(_grade_tosign);
	check_grade(_grade_toexec);
}

AForm::AForm( const AForm & src ):	_name(src.get_name()), _signed(src.get_signed()),
									_grade_tosign(src.get_grade_tosign()), _grade_toexec(src.get_grade_toexec())
{
	check_grade(_grade_tosign);
	check_grade(_grade_toexec);
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

AForm::~AForm()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

AForm &				AForm::operator=( AForm const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	(void) rhs;
	return *this;
}

std::ostream &			operator<<( std::ostream & o, AForm const & i )
{
	o	<< "Name:\t\t\t"			<< i.get_name() << "\n"
		<< "signed:\t\t\t"			<< i.get_signed() << "\n"
		<< "grade to sign:\t\t"		<< i.get_grade_tosign() << "\n"
		<< "grade to execute:\t"	<< i.get_grade_toexec()<< "\n";
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/
void	AForm::execute(Bureaucrat const & executor) const
{
	if (executor.getGrade() > this->get_grade_toexec())
	{
		throw AForm::GradeTooLowException();
	}
	else if (this->get_signed() == false)
	{
		throw AForm::FormUnsigned();
	}
	else
		this->my_action();
}

void AForm::beSigned(Bureaucrat &bur)
{
	if (bur.getGrade() <= this->get_grade_tosign())
	{
		this->_signed = true;
		std::cout << "Form \"" << this->get_name() <<
		"\" has been signed by " << bur.getName() << std::endl;
	}
	else
		throw AForm::GradeTooLowException();
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/
std::string	AForm::get_name() const
{
	return this->_name;
}
bool AForm::get_signed() const
{
	return this->_signed;
}
int AForm::get_grade_tosign() const
{
	return this->_grade_tosign;
}
int AForm::get_grade_toexec() const
{
	return this->_grade_toexec;
}

/*
** ----------------------------- EXCEPTIONS ----------------------------------
*/

	const char * AForm::GradeTooHighException::what () const throw ()
	{return (RED "Grade Too High!" NRM);};
	const char * AForm::GradeTooLowException::what () const throw ()
	{return (RED "Grade Too Low!" NRM);};
	const char * AForm::FormUnsigned::what () const throw ()
	{return (RED "Form is unsigned!" NRM);};



/* ************************************************************************** */