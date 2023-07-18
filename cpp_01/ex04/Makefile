NAME =	no_sed

SRC =	main.cpp
# HEADER =	Zombie.hpp

CC =	c++
FLGS =	-Wall -Wextra -Werror -std=c++98 -g

all: ${NAME}

${NAME}:	${SRC} ${HEADER}
	${CC} ${FLGS} ${SRC} -o ${NAME}

clean:
	rm -rf ${NAME}

fclean:	clean
re:	fclean all

.PHONY:	all clean fclean re
