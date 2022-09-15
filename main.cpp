#include "allocator.hpp"
#include "vector.hpp"


int main()
{
	ft::vector<int> vec;
	ft::vector<int>::iterator itt = vec.begin();

	int i = 0;
	for(; i < 10; i++)
		vec.push_back(i + 2);
	for(; itt != vec.end(); itt++)
		std::cout << *itt << "\n";
}
