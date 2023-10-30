#include "Bureaucrat.hpp"
#include <cstring>


/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : _name("defBureaucrat"), _grade(1)
{std::cout<< "Bureaucrat created!" <<std::endl;}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	std::cout<< "Bureaucrat created!" <<std::endl;
	if(grade < 1)
	{
		_grade = 1;
		throw Bureaucrat::GradeTooHighException();
	}
	if(grade > 150)
	{
		_grade = 150;
		throw Bureaucrat::GradeTooLowException();
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ): _name(src._name), _grade(src._grade)
{std::cout<< "Bureaucrat Copy Construtor!" <<std::endl;}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{std::cout<< "Bureaucrat deleted!" <<std::endl;}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &				Bureaucrat::operator=( Bureaucrat const & src )
{
	std::cout<< "Bureaucrat copy assignment operator!" <<std::endl;
	//name is const, cant be changed after initialization
	this->_grade = src.getGrade();
		return *this;
}

std::ostream &			operator<<( std::ostream & os,const Bureaucrat & bur)
{
	os  << bur.getName() << ", bureaucrat grade " << bur.getGrade();
	return os;
}


/*
** --------------------------------- METHODS ----------------------------------
*/
void Bureaucrat::gradeUp()
{

	if(this->getGrade() - 1 < 1)
	{
		_grade = 1;
		throw Bureaucrat::GradeTooHighException();
	}
	else
	{
		_grade -= 1;
		std::cout<< "bureaucrat: grade up!" <<std::endl;
	}

}
void Bureaucrat::gradeDown()
{
	
	if(this->getGrade() + 1 > 150)
	{
		_grade = 150;
		throw Bureaucrat::GradeTooLowException();
	}
	else
	{
		_grade += 1;
		std::cout<< "bureaucrat: grade down!" <<std::endl;
	}
			

}

void Bureaucrat::signForm(AForm &form)
{
	try 
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.get_name() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << this->getName()
		<< " could not sign " << form.get_name()
		<< " because " << e.what() << std::endl;
	}
}
void Bureaucrat::executeForm(AForm const & form)
{
	try 
	{
		form.execute(*this);
		std::cout << this->getName() << " signed " << form.get_name() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout <<"ERROR! " << this->getName()
		<< " could not execute " << form.get_name()
		<< " because " << e.what() << std::endl;
	}
}

/*
** ---------------------------EXCEPTION CLASSES ------------------------------
*/

const char * Bureaucrat::GradeTooHighException::what () const throw ()
{return (RED "Grade Too High!" NRM);};
const char * Bureaucrat::GradeTooLowException::what () const throw ()
{return (RED "Grade Too Low!" NRM);};

 
/*
** --------------------------------- ACCESSOR ---------------------------------
*/
		int Bureaucrat::getGrade() const {return _grade;}
		std::string Bureaucrat::getName() const {return _name;}

/* ************************************************************************** */