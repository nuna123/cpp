NAME = unnecessary_violence

SRCS = HumanA.cpp  HumanB.cpp  main.cpp  Weapon.cpp
HEADERS = HumanA.hpp  HumanB.hpp  Weapon.hpp

CC = c++
FLGS =	-Wall -Wextra -Werror -std=c++98 -g

all: ${NAME}

${NAME}:	${SRCS} ${HEADER}
	${CC} ${FLGS} ${SRCS} -o ${NAME}

clean:
	rm -rf ${NAME}

fclean:	clean
re:	fclean all

.PHONY:	all clean fclean re
