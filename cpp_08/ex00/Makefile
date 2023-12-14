NAME =	./easyfind

SRC =	main.cpp

CC =	c++
FLGS =	-Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}:	${SRC}
	${CC} ${FLGS} ${SRC} -o ${NAME}

clean:
	rm -rf ${NAME}

fclean:	clean
re:	fclean all

.PHONY:	all clean fclean re