NAME = ft_containers

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98 #-g -fsanitize=address

OBJ = $(SRC:.cpp=.o)

SRC =	./TestFiles/main.cpp\
		./TestFiles/std_set_tests.cpp\
#		./TestFiles/std_stack_tests.cpp\
		./TestFiles/ft_set_tests.cpp\
		./TestFiles/std_map_tests.cpp\
		./TestFiles/ft_map_tests.cpp\
		./TestFiles/ft_vector_tests.cpp\
		./TestFiles/std_vector_tests.cpp\
		./TestFiles/ft_stack_tests.cpp

LIB =	./containers/vector.hpp\
		./containers/vector.ipp\
		./containers/stack.hpp\
		./containers/stack.ipp\
		./containers/map.hpp\
		./containers/map.ipp\
		./containers/set.hpp\
		./containers/set.ipp\
		./utils/iterator.hpp\
		./utils/random_access_iterator.hpp\
		./utils/type_traits.hpp\
		./utils/equal.hpp\
		./utils/lexicographical_compare.hpp\
		./utils/reverse_iterator.hpp\
		./utils/rb_tree.hpp\
		./utils/rb_node.hpp\
		./utils/Bidirectional_Iterator.hpp\
		./TestFiles/utils.hpp\



all : $(NAME)

$(NAME) : $(OBJ) $(LIB)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp $(LIB)
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm -fr $(NAME)
	rm -fr std_vector

fclean : clean
	rm -fr $(OBJ)

re : fclean all
