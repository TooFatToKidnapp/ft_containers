#include "./utils.hpp"


void test_stack()
{
	cout << YELLOW << "DEFAULT CONSTRUCTOR:" << CLEAR << "stack"<< std::endl;
	ft::stack<DataType> ft_stack;

	cout << std::endl;

	cout << YELLOW << "SIZE:" << CLEAR << std::endl;
	cout << "stack size: " << ft_stack.size() << std::endl;

	cout << std::endl;

	cout << YELLOW << "EMPTY:" << CLEAR << std::endl;
	cout << "stack empty() (1/true if empty 0/false if not): " << std::boolalpha << ft_stack.empty() << std::noboolalpha << std::endl;

	cout << std::endl;

	cout << YELLOW << "PUSH:" << CLEAR << std::endl;
	for (int i = 0; i <= 10; i++)
	{
		ft_stack.push(42 * i);
		cout << YELLOW << "TOP:" << ft_stack.top() << std::endl;
	}

	cout << std::endl;

	cout << YELLOW << "SIZE:" << CLEAR << std::endl;
	cout << "stack size: " << ft_stack.size() << std::endl;

	cout << std::endl;

	cout << YELLOW << "EMPTY:" << CLEAR << std::endl;
	cout << "stack empty() (1/true if empty 0/false if not): " << std::boolalpha << ft_stack.empty() << std::noboolalpha << std::endl;
	cout << std::endl;

	cout << YELLOW << "COPY CONSTRUCTOR:" << CLEAR << std::endl;
	ft::stack<DataType> ft_stack_copy(ft_stack);

	cout << std::endl;

	cout << YELLOW << "POP:" << CLEAR << std::endl;
	for (int i = 0; i <= 10; i++)
	{
		cout << YELLOW << "TOP:" << ft_stack.top() << std::endl;
		ft_stack.pop();
	}

	cout << std::endl;

	cout << YELLOW << "ASSIGNATION OPERATOR:" << CLEAR << std::endl;
	ft_stack_copy = ft_stack;

	cout << std::endl;

	cout << YELLOW << "OPERATIONAL OPERATOR:" << CLEAR << std::endl;
	cout << std::boolalpha;
	cout << "(stack == stack_copy) : " << (ft_stack == ft_stack_copy) << std::endl;
	cout << "(stack != stack_copy) : " << (ft_stack != ft_stack_copy) << std::endl;
	cout << "(stack < stack_copy) : " << (ft_stack < ft_stack_copy) << std::endl;
	cout << "(stack <= stack_copy) : " << (ft_stack <= ft_stack_copy) << std::endl;
	cout << "(stack > stack_copy) : " << (ft_stack > ft_stack_copy) << std::endl;
	cout << "(stack >= stack_copy) : " << (ft_stack >= ft_stack_copy) << std::endl;
	cout << std::noboolalpha;
	cout << std::endl;
}
