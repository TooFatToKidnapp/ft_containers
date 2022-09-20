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
	stack<int> vec;
	vec.push(10);
	vec.push(20);
	vec.push(30);
	vec.push(40);
	vec.push(50);
	stack<int> sta;
	sta = vec;
	vec.push(50);

	if (sta != vec)
		cout << "true\n";
	cout << sta.top() << "\n";
	vec.pop();
	cout << sta.top() << "\n";
	sta.pop();
	cout << sta.top() << "\n";

}
