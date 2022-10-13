#include "./utils.hpp"


void print_size(std::vector<DataType> &vector, std::string name) {
	cout << name << " size: " << vector.size() << ", capacity: " << vector.capacity() << ", max size: " << vector.max_size() << std::endl;
	cout << name << " is empty: " << std::boolalpha << vector.empty() << std::noboolalpha << std::endl;
}

void print_vector(std::vector<DataType> &vector, std::string name) {
	cout << name << ": ";
	for (std::vector<DataType>::iterator it = vector.begin(); it != vector.end(); ++it)
		cout << *it << " ";
	cout << std::endl;
}



void vector_tests() {
	print_title("Default Constructor", "ft_vector");
	std::vector<DataType> ft_vector;
	print_size(ft_vector, "vector");

	print_title("FILL CONSTRUCTOR", "ft_vector_fill");
	std::vector<DataType> ft_vector_fill(10, 42);
	print_size(ft_vector_fill, "vector_fill");
	print_vector(ft_vector_fill, "vector_fill");

	print_title("RANGE CONSTRUCTOR", "ft_vector_range");
	std::vector<DataType> ft_vector_range(ft_vector_fill.begin(), ft_vector_fill.end());
	print_size(ft_vector_range, "vector_range");
	print_vector(ft_vector_range, "vector_range");

	print_title("COPY CONSTRUCTOR", "ft_vector_copy");
	std::vector<DataType> ft_vector_copy(ft_vector_range);
	print_size(ft_vector_copy, "vector_copy");
	print_vector(ft_vector_copy, "vector_copy");

	print_title("ASSIGNMENT OPERATOR", "ft_vector_assigned");
	std::vector<DataType> ft_vector_assigned;
	ft_vector_assigned = ft_vector_range;
	print_size(ft_vector_assigned, "vector_assigned");
	print_vector(ft_vector_assigned, "vector_assigned");

	for (int i = 0 ; i < 10; i++)
		ft_vector.push_back(i * 5);

	print_title("ITERATOR TESTE'S");
	cout << "ft_vector iterator: ";
	for (std::vector<DataType>::iterator it = ft_vector.begin(); it != ft_vector.end(); ++it)
		cout << *it << " ";
	cout << "\n";

	cout << "ft_vector const_iterator: ";
	for (std::vector<DataType>::const_iterator it = ft_vector.begin(); it != ft_vector.end(); ++it)
		cout << *it << " ";
	cout << "\n";

	cout << "ft_vector reverse_iterator: ";
	for (std::vector<DataType>::reverse_iterator it = ft_vector.rbegin(); it != ft_vector.rend(); ++it)
		cout << *it << " ";
	cout << "\n";

	cout << "ft_vector const_reverse_iterator: ";
	for (std::vector<DataType>::const_reverse_iterator it = ft_vector.rbegin(); it != ft_vector.rend(); ++it)
		cout << *it << " ";
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
		cout << e.what() << std::endl;
	}
	cout << std::endl;

	try
	{
		ft_vector.reserve(ft_vector.max_size() + 1);
	}
	catch (std::exception &e)
	{
		cout << e.what() << std::endl;
	}
	cout << std::endl;

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
	cout << "vector : ";
	for (unsigned long i = 0; i < ft_vector.size(); i++)
		cout << ft_vector[i] << " ";
	cout << std::endl;
	cout << std::endl;

	print_title("VECTOR AT()");
	try
	{
		cout << "ft_vector : ";
		for (size_t i = 0; i < ft_vector.size() + 1 ; i++)
			cout << ft_vector.at(i) << ", ";
		cout << std::endl;
	}
	catch (std::exception &e)
	{
		cout << e.what() << std::endl;
	}
	cout << std::endl;

	print_title("VECTOR FRONT()");
	cout << "vector : " << ft_vector.front() << std::endl;
	cout << std::endl;

	print_title("VECTOR BACK()");
	cout << "vector : " << ft_vector.back() << std::endl;
	cout << std::endl;

	print_title("VECTOR ASSIGN: ft_vector_fill(first, last)");
	ft_vector.assign(ft_vector_fill.begin(), ft_vector_fill.end());
	print_size(ft_vector, "vector");
	print_vector(ft_vector, "vector");

	print_title("VECTOR ASSIGN(n, val)");
	ft_vector.assign(10, 42);
	print_size(ft_vector, "ft_vector");
	print_vector(ft_vector, "ft_vector");

	print_title("VECTOR PUSH_BACK(i * 42)");
	for (int i = 0; i <= 10; i++)
	{
		ft_vector.push_back(i * 42);
		print_size(ft_vector, "vector");
	}
	cout << std::endl;
	print_vector(ft_vector, "vector");

	print_title("VECTOR POP_BACK()");
	for (int i = 0; i < 10; i++)
	{
		ft_vector.pop_back();
		print_size(ft_vector, "vector");
	}
	cout << std::endl;
	print_vector(ft_vector, "vector");

	print_title("VECTOR INSERT(position, n, val)");
	ft_vector.insert(ft_vector.begin(), 5, 420);
	print_vector(ft_vector, "vector");

	print_title("VECTOR INSERT(position, first, last)");
	ft_vector.insert(ft_vector.end(), ft_vector_fill.begin(), ft_vector_fill.end());
	print_vector(ft_vector, "vector");

	print_title("VECTOR ERASE(position)", "erasing first half");
	for (std::vector<int>::iterator it = (ft_vector.begin() + (ft_vector.size() / 2)); it != ft_vector.end() - 1 ; it++)
		ft_vector.erase(it);
	print_vector(ft_vector, "vector");

	print_title("VECTOR SWAP() (MEMBER)", "swaping vector and range vector");
	print_title("BEFORE SWAP");
	print_vector(ft_vector, "vector");
	print_vector(ft_vector_range, "vector_range");
	ft_vector.swap(ft_vector_range);
	print_title("AFTER SWAP");
	print_vector(ft_vector, "vector");
	print_vector(ft_vector_range, "vector_range");

	print_title("VECTOR SWAP() (NON MEMBER)", "swaping vector and range vector again");
	print_title("BEFORE SWAP");
	print_vector(ft_vector, "vector");
	print_vector(ft_vector_range, "vector_range");
	std::swap(ft_vector, ft_vector_range);
	print_title("AFTER SWAP");
	print_vector(ft_vector, "vector");
	print_vector(ft_vector_range, "vector_range");

	print_title("OPERATIONAL OPERATOR", "vector & vector_copy");
	print_vector(ft_vector, "vector");
	print_vector(ft_vector, "vector");
	cout << "vector == vector_copy: " << (ft_vector == ft_vector_copy) << std::endl;
	cout << "vector != vector_copy: " << (ft_vector != ft_vector_copy) << std::endl;
	cout << "vector < vector_copy: " << (ft_vector < ft_vector_copy) << std::endl;
	cout << "vector <= vector_copy: " << (ft_vector <= ft_vector_copy) << std::endl;
	cout << "vector > vector_copy: " << (ft_vector > ft_vector_copy) << std::endl;
	cout << "vector >= vector_copy: " << (ft_vector >= ft_vector_copy) << std::endl;
	cout << std::endl;

	print_title("OPERATIONAL OPERATOR", "vector_assignation & vector_copy");
	print_vector(ft_vector_assigned, "vector_assignation");
	print_vector(ft_vector_copy, "vector_copy");
	cout << std::boolalpha;
	cout << "vector_assignation == vector_copy: " << (ft_vector_assigned == ft_vector_copy) << std::endl;
	cout << "vector_assignation != vector_copy: " << (ft_vector_assigned != ft_vector_copy) << std::endl;
	cout << "vector_assignation < vector_copy: " << (ft_vector_assigned < ft_vector_copy) << std::endl;
	cout << "vector_assignation <= vector_copy: " << (ft_vector_assigned <= ft_vector_copy) << std::endl;
	cout << "vector_assignation > vector_copy: " << (ft_vector_assigned > ft_vector_copy) << std::endl;
	cout << "vector_assignation >= vector_copy: " << (ft_vector_assigned >= ft_vector_copy) << std::endl;
	cout << std::noboolalpha;

	cout << std::endl;

	print_title("VECTOR CLEAR()");
	print_size(ft_vector, "vector before clear()");
	print_size(ft_vector_range, "vector_range before clear()");
	ft_vector.clear();
	print_size(ft_vector, "vector after(clear)");
	print_size(ft_vector_range, "vector_range after(clear)");

}
