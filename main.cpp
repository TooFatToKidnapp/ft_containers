#include "allocator.hpp"
#include "vector.hpp"

using std::cout;

int main()
{
	ft::vector<int> vec;
	int i = 0;
	for(; i < 10; i++)
		vec.push_back(i + 2);
	ft::vector<int>::const_reverse_iterator itt = vec.rbegin();
	for(; itt != vec.rend(); itt++)
		std::cout << "here " <<*itt << "\n";

}
