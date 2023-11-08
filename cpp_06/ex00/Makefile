NAME	= cpp06_ex00

SRC		= main.cpp Bureaucrat.cpp
C_FLGS	= -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}: ${SRC}
	c++ ${C_FLGS} ${SRC} -o ${NAME}

clean:
	rm ${NAME}

fclean: clean
re: clean all