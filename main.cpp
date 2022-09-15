#include "allocator.hpp"
#include "vector.hpp"

using std::cout;

int main()
{
	ft::vector<int> vec;
	int i = 0;
	for(; i < 10; i++)
		vec.push_back(i + 2);
	ft::vector<int>::iterator itt = vec.end();
	cout << vec.capacity() << "\n";
	cout << vec.size() << "\n";
	itt += 5;
	cout << *itt << "\n";
}
