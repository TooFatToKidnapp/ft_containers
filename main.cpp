#include "allocator.hpp"
#include "vector.hpp"
#include <list>
#include<vector>
#include <limits>
using std::cout;
using ft::vector;
#ifndef somthing
#define somthing
#endif

int main()
{
	vector<int> vec;
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(30);
	vec.push_back(40);
	vec.push_back(50);

	vector<int>::reverse_iterator it = vec.rend() -1 ;
	cout << *it << "\n";

}
