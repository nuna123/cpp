NAME =	Fixed_useful

SRC =	main.cpp Fixed.cpp
HEADER =	Fixed.hpp

CC =	c++
FLGS =	-Wall -Wextra -Werror -std=c++98 -g

all: ${NAME}

${NAME}:	${SRC} ${HEADER}
	@ ${CC} ${FLGS} ${SRC} -o ${NAME}
	@ echo '\033[0;32m' ${NAME} "created!" '\033[0m'
	@ ./${NAME}

clean:
	@ rm -rf ${NAME}
	@ echo '\033[0;31m' ${NAME} "deleted!" '\033[0m'

run:
	@ ./${NAME}

fclean:	clean
re:	fclean all

.PHONY:	all clean fclean re run
