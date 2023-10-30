#include "ShrubberyCreationForm.hpp"

// Constructors
ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
	std::cout << "\e[0;33mDefault Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy): AForm(copy), _target(copy.get_target())
{
	(void) copy;
	std::cout << "\e[0;33mCopy Constructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "\e[0;31mDestructor called of ShrubberyCreationForm\e[0m" << std::endl;
}


// Operators
ShrubberyCreationForm & ShrubberyCreationForm::operator=(const ShrubberyCreationForm &assign)
{
	(void) assign;
	return *this;
}

//getter

std::string ShrubberyCreationForm::get_target() const
{
	return this->_target;
}
//methods
void ShrubberyCreationForm::my_action()
{
	std::ofstream file(this->get_target().append("_shrubbery").c_str());
	file \
<< "                                                         .             \n"
<< "                                              .         ;              \n"
<< "                 .              .              ;%     ;;               \n"
<< "                   ,           ,                :;%  %;                \n"
<< "                    :         ;                   :;%;'     .,         \n"
<< "           ,.        %;     %;            ;        %;'    ,;           \n"
<< "             ;       ;%;  %%;        ,     %;    ;%;    ,%'            \n"
<< "              %;       %;%;      ,  ;       %;  ;%;   ,%;'             \n"
<< "               ;%;      %;        ;%;        % ;%;  ,%;'               \n"
<< "                `%;.     ;%;     %;'         `;%%;.%;'                 \n"
<< "                 `:;%.    ;%%. %@;        %; ;@%;%'                    \n"
<< "                    `:%;.  :;bd%;          %;@%;'                      \n"
<< "                      `@%:.  :;%.         ;@@%;'                       \n"
<< "                        `@%.  `;@%.      ;@@%;                         \n"
<< "                          `@%%. `@%%    ;@@%;                          \n"
<< "                            ;@%. :@%%  %@@%;                           \n"
<< "                              %@bd%%%bd%%:;                            \n"
<< "                                #@%%%%%:;;                             \n"
<< "                                %@@%%%::;                              \n"
<< "                                %@@@%(o);  . '                         \n"
<< "                                %@@@o%;:(.,'                           \n"
<< "                            `.. %@@@o%::;                              \n"
<< "                               `)@@@o%::;                              \n"
<< "                                %@@(o)::;                              \n"
<< "                               .%@@@@%::;                              \n"
<< "                               ;%@@@@%::;.                             \n"
<< "                              ;%@@@@%%:;;;.                            \n"
<< "                          ...;%@@@@@%%:;;;;,..                         \n"
<< std::endl;

	std::cout << "Shrubbery has been created at " <<this->get_target().append("_shrubbery") << "!" << std::endl;
	file.close();
}