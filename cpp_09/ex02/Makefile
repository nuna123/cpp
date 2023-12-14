NAME = ./PmergeMe

SRCS = main.cpp PmergeMe.cpp
INCLDS = PmergeMe.hpp

C_FLGS = -Wall -Wextra -Werror -std=c++98

######################################################
######################################################

all: ${NAME}

${NAME}: ${SRCS} ${INCLDS}
	c++ ${C_FLGS} ${SRCS} -o ${NAME}

clean:
	rm -rf ${NAME}

fclean: clean

re: clean all

.PHONY: all clean fclean re