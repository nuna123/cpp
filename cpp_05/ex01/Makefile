NAME	= cpp05_ex01

SRC		= main.cpp Bureaucrat.cpp Form.cpp
C_FLGS	= -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}: ${SRC}
	c++ ${C_FLGS} ${SRC} -o ${NAME}

clean:
	rm -f ${NAME}

fclean: clean
re: clean all