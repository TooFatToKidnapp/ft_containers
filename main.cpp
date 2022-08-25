#include "vector.hpp"

int main()
{
	// namespace xD = test;
	// int i = 10;
	// xD::printx(i);

	// std::vector<int> *vec = new std::vector<int>(10);

	// std::vector<int>::iterator it;
	// it = vec->begin();
	// for (int j = 1; j < 11; j++, it++)
	// 	(*it) = j;
	// vec->push_back(11);
	// // vec->push_back(9);
	// // vec->push_back(8);
	// // vec->push_back(7);
	// // vec->push_back(6);
	// // vec->push_back(5);
	// // vec->push_back(4);
	// // vec->push_back(3);
	// // vec->push_back(2);
	// // vec->push_back(1);
	// // vec->push_back(0);
	// i = 0;
	// std::cout << vec->size() << std::endl;
	// for (it = vec->begin(); it != vec->end(); it++)
	// {
	// 	std::cout << *it << "[" << i << "]"<< std::endl;
	// 	i++;
	// }
	// delete vec;

	ft::vector<int> vec;
	vec.push(0);
	vec.push(2);
	vec.push(3);
	vec.push(4);
	vec.push(5);
	vec.push(6);
	vec.push(7);
	vec.push(8);
	vec.push(9);
	vec.push(10);
	std::cout << "vec size = " << vec.size() << std::endl;
	std::cout << "vec capacity = " << vec.getcapacity() << std::endl;

	std::cout << "vec data " << std::endl;
	vec.print();
}
