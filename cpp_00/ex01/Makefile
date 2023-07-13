NAME =	phonebook

SRC =	main.cpp PhoneBook.cpp Contact.cpp
HEADER =	Contact.hpp	PhoneBook.hpp

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
