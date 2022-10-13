#include "./utils.hpp"


void print_size(ft::vector<DataType> &vector, std::string name) {
	cout << name << " size: " << vector.size() << ", capacity: " << vector.capacity() << ", max size: " << vector.max_size() << std::endl;
	cout << name << " is empty: " << std::boolalpha << vector.empty() << std::noboolalpha << std::endl;
}

void print_vector(ft::vector<DataType> &vector, std::string name) {
	cout << name << ": ";
	for (ft::vector<DataType>::iterator it = vector.begin(); it != vector.end(); ++it)
		cout << *it << " ";
	std::cout << std::endl;
}



void vector_tests() {
	print_title("Default Constructor", "ft_vector");
	ft::vector<DataType> ft_vector;
	print_size(ft_vector, "vector");

	print_title("FILL CONSTRUCTOR", "ft_vector_fill");
	ft::vector<DataType> ft_vector_fill(10, 42);
	print_size(ft_vector_fill, "vector_fill");
	print_vector(ft_vector_fill, "vector_fill");

	print_title("RANGE CONSTRUCTOR", "ft_vector_range");
	ft::vector<DataType> ft_vector_range(ft_vector_fill.begin(), ft_vector_fill.end());
	print_size(ft_vector_range, "vector_range");
	print_vector(ft_vector_range, "vector_range");

	print_title("COPY CONSTRUCTOR", "ft_vector_copy");
	ft::vector<DataType> ft_vector_copy(ft_vector_range);
	print_size(ft_vector_copy, "vector_copy");
	print_vector(ft_vector_copy, "vector_copy");

	print_title("ASSIGNMENT OPERATOR", "ft_vector_assigned");
	ft::vector<DataType> ft_vector_assigned;
	ft_vector_assigned = ft_vector_range;
	print_size(ft_vector_assigned, "vector_assigned");
	print_vector(ft_vector_assigned, "vector_assigned");

	for (int i = 0 ; i < 10; i++)
		ft_vector.push_back(i * 5);

	print_title("ITERATOR TESTE'S");
	cout << "ft_vector iterator: ";
	for (ft::vector<DataType>::iterator it = ft_vector.begin(); it != ft_vector.end(); ++it)
		std::cout << *it << " ";
	cout << "\n";

	cout << "ft_vector const_iterator: ";
	for (ft::vector<DataType>::const_iterator it = ft_vector.begin(); it != ft_vector.end(); ++it)
		std::cout << *it << " ";
	cout << "\n";

	cout << "ft_vector reverse_iterator: ";
	for (ft::vector<DataType>::reverse_iterator it = ft_vector.rbegin(); it != ft_vector.rend(); ++it)
		std::cout << *it << " ";
	cout << "\n";

	cout << "ft_vector const_reverse_iterator: ";
	for (ft::vector<DataType>::const_reverse_iterator it = ft_vector.rbegin(); it != ft_vector.rend(); ++it)
		std::cout << *it << " ";
	cout << "\n";

	print_title("ACCESSOR AND MEMBER FUNCTIONS", "size, max_size, capacity, resize, empty, reserve");
	print_title("BEFORE RESIZE");
	print_size(ft_vector, "ft_vector");

	print_title("AFTER RESIZE(20)");
	ft_vector.resize(20);
	print_size(ft_vector, "ft_vector");
	print_vector(ft_vector, "ft_vector");

	print_title("AFTER RESIZE(20, 42)");
	ft_vector.resize(40, 42);
	print_size(ft_vector, "ft_vector");
	print_vector(ft_vector, "ft_vector");

	print_title("VECTOR EMPTY()");
	print_size(ft_vector, "vector");


	print_title("VECTOR RESERVE(max_size)");
	try
	{
		ft_vector.reserve(ft_vector.max_size());
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		ft_vector.reserve(ft_vector.max_size() + 1);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	print_title("VECTOR RESERVE(50)");
	ft_vector.reserve(50);
	print_size(ft_vector, "ft_vector");
	print_vector(ft_vector, "ft_vector");
	print_title("VECTOR RESERVE(45)");
	ft_vector.reserve(45);
	print_size(ft_vector, "ft_vector");
	print_vector(ft_vector, "ft_vector");
	print_title("VECTOR RESERVE(30)");
	ft_vector.reserve(30);
	print_size(ft_vector, "ft_vector");
	print_vector(ft_vector, "ft_vector");

	print_title("VECTOR [] OPERATOR");
	std::cout << "vector : ";
	for (unsigned long i = 0; i < ft_vector.size(); i++)
		std::cout << ft_vector[i] << " ";
	std::cout << std::endl;
	std::cout << std::endl;

	print_title("VECTOR AT()");
	try
	{
		std::cout << "ft_vector : ";
		for (size_t i = 0; i < ft_vector.size() + 1 ; i++)
			std::cout << ft_vector.at(i) << ", ";
		std::cout << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	print_title("VECTOR FRONT()");
	std::cout << "vector : " << ft_vector.front() << std::endl;
	std::cout << std::endl;

	print_title("VECTOR BACK()");
	std::cout << "vector : " << ft_vector.back() << std::endl;
	std::cout << std::endl;

	print_title("VECTOR ASSIGN: ft_vector_fill(first, last)");
	ft_vector.assign(ft_vector_fill.begin(), ft_vector_fill.end());
	print_size(ft_vector, "vector");
	print_vector(ft_vector, "vector");

	print_title("VECTOR ASSIGN(n, val)");
	ft_vector.assign(10, 42);
	print_size(ft_vector, "ft_vector");
	print_vector(ft_vector, "ft_vector");





}
