NAME	= serializer

SRC		= main.cpp Serializer.cpp
 #Data.hpp
C_FLGS	= -Wall -Wextra -Werror -std=c++98 -fsanitize=address -g

all: ${NAME}

${NAME}: ${SRC}
	c++ ${C_FLGS} ${SRC} -o ${NAME}

clean:
	rm -f ${NAME}

fclean: clean
re: clean all