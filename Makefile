NAME = Containers

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98 -g -fsanitize=address

OBJ = $(SRC:.cpp=.o)

SRC =	main.cpp

LIB =	./vector.hpp\
		./vector.ipp\
		./utils/iterator.hpp\
		./utils/random_access_iterator.hpp\
		./utils/type_traits.hpp\

all : $(NAME)

$(NAME) : $(OBJ) $(LIB)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(LIB)
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm -fr $(NAME)

fclean : clean
	rm -fr $(OBJ)

re : fclean all
