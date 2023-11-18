NAME	= cpp05_ex03

SRC		= AForm.cpp main.cpp RobotomyRequestForm.cpp Bureaucrat.cpp \
		PresidentialPardonForm.cpp  ShrubberyCreationForm.cpp Intern.cpp
C_FLGS	= -Wall -Wextra -Werror -std=c++98 -g

all: ${NAME}

${NAME}: ${SRC}
	c++ ${C_FLGS} ${SRC} -o ${NAME}

clean:
	rm -f ${NAME}

fclean: clean
re: clean all