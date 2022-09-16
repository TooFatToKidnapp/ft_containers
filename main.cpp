#include "allocator.hpp"
#include "vector.hpp"

using std::cout;
using ft::vector;

int main()
{
	ft::vector<int> vec;
	for(int i = 0; i < 10 ; i++){
		vec.push_back(i*2);
	}

	ft::vector<int>::iterator itt;
	for(itt = vec.begin(); vec.end() != itt ; itt++){
		cout << *itt << "\n";
	}
}
