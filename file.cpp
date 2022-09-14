#include<iostream>
#include<vector>
#include<memory>
#include "allocator.hpp"


int main()
{
	std::vector<int> vec = {1,2,3,45,5,6};

	std::vector<int>::reverse_iterator itt = vec.rbegin();
		std::cout << *itt << std::endl;
	// for(; itt != vec.rend(); itt++){
	// }
}
