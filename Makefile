NAME = ft_containers

CC = Clang++

FLAGS = -Wall -Werror -Wextra -std=c++98 -g -fsanitize=address

OBJ = $(SRC:.cpp=.o)

SRC =	main.cpp

LIB =	./containers/vector.hpp\
		./containers/vector.ipp\
		./containers/stack.ipp\
		./containers/stack.ipp\
		./utils/iterator.hpp\
		./utils/random_access_iterator.hpp\
		./utils/type_traits.hpp\
		./utils/equal.hpp\
		./utils/lexicographical_compare.hpp\
		./utils/reverse_iterator.hpp\
		./utils/rb_tree.hpp\
		./utils/rb_node.hpp\
		./utils/Bidirectional_Iterator.hpp\



all : $(NAME)

$(NAME) : $(OBJ) $(LIB)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

main :
	$(CC) $(FLAGS) vec_test.cpp -o std_vector

%.o : %.cpp $(LIB)
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm -fr $(NAME)
	rm -fr std_vector

fclean : clean
	rm -fr $(OBJ)

re : fclean all
