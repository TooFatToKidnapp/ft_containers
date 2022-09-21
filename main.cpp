#include "./containers/vector.hpp"
#include "./containers/stack.hpp"
#include "./containers/pair.hpp"
#include <list>
#include <vector>
#include <stack>

#include <algorithm>
#include <limits>
using std::cout;
using ft::vector;
using ft::stack;
using ft::pair;
#ifndef somthing
#define somthing
#endif

int main()
{
	pair<int, int> obj(10 , 12);
	pair<int, int> obj2;
	obj2 = obj;
	obj2.first = 100;
	if (obj2 > obj)
		cout << "true\n";
//	cout << obj2.second << " " << obj2.first << std::endl;
}
