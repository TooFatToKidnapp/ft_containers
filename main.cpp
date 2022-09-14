#include "allocator.hpp"
#include "vector.hpp"


int main()
{
	ft::vector<int> vec;
	int i = 0;
	for(; i < 10; i++)
		vec.push_back(i);

for(i = 0; i < 10; i++)
		std::cout << vec[i] << "\n";
}	
