NAME	= cpp05_ex02

SRC		= AForm.cpp main.cpp RobotomyRequestForm.cpp Bureaucrat.cpp  PresidentialPardonForm.cpp  ShrubberyCreationForm.cpp
C_FLGS	= -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}: ${SRC}
	c++ ${C_FLGS} ${SRC} -o ${NAME}

clean:
	rm ${NAME}

fclean: clean
re: clean all