#include "vector.hpp"

void ft::vector::print()
{
	for (size_t i = 0; i < current; i++)
	{
		std::cout << data[i] << std::endl;
	}
}
