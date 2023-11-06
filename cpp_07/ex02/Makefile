NAME	= cpp07_ex02

SRC		= main.cpp
C_FLGS	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

all: ${NAME}

${NAME}: ${SRC} ./*.hpp
	c++ ${C_FLGS} ${SRC} -I./ -o ${NAME}

clean:
	rm -rf ${NAME}

fclean: clean
re: clean all