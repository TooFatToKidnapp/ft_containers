#include "./containers/vector.hpp"
#include "./containers/stack.hpp"
#include <list>
#include <vector>
#include <stack>
#include <algorithm>
#include <limits>
using std::cout;
using ft::vector;
using ft::stack;
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
	vector<int>::iterator it;
	it = vec.begin();
	cout <<  *( (1 + it) + 3) << "\n";

}
