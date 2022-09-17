#include "allocator.hpp"
#include "vector.hpp"
#include <list>
#include<vector>

using std::cout;
using ft::vector;

int main()
{
	vector<int> vec(10, -1);
	vec.push_back(9);
	vec.push_back(8);
	vec.push_back(7);
	vec.push_back(6);
	vec.push_back(5);
	vector<int> vec2(vec.begin(), vec.end());
	cout << vec2.size() << " " << vec2.capacity() << "\n";
	for(vector<int>::iterator it = vec2.begin(); it != vec2.end(); it++ ){
		cout << *it << "\n";
	}
}


