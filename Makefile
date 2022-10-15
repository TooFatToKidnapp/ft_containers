NAME = ft_containers

STD_NAME = std_containers

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

OBJ = $(SRC:.cpp=.o)

STD_OBJ = $(STD_SRC:.cpp=.o)

SRC =	./TestFiles/main.cpp\
		./TestFiles/ft_set_tests.cpp\
		./TestFiles/ft_map_tests.cpp\
		./TestFiles/ft_vector_tests.cpp\
		./TestFiles/ft_stack_tests.cpp


STD_SRC =	./TestFiles/std_set_tests.cpp\
			./TestFiles/std_map_tests.cpp\
			./TestFiles/std_vector_tests.cpp\
			./TestFiles/std_stack_tests.cpp\
			./TestFiles/main.cpp


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



all : $(NAME) $(STD_NAME)

$(NAME) : $(OBJ) $(LIB)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

$(STD_NAME) : $(STD_OBJ) $(LIB)
	$(CC) $(FLAGS) $(STD_OBJ) -o $(STD_NAME)

%.o : %.cpp $(LIB)
	$(CC) $(FLAGS) -o $@ -c $<

clean :
	rm -f $(OBJ) $(STD_OBJ)

fclean : clean
	rm -f $(NAME) $(STD_NAME)

re : fclean all
