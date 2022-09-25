#include "./containers/vector.hpp"
#include "./containers/stack.hpp"
#include "./utils/pair.hpp"
#include <list>
#include <vector>
#include <map>
#include <stack>
#include <functional>
#include <algorithm>
#include <limits>
using std::cout;
using ft::vector;
using ft::stack;
using ft::pair;
using std::map;
#ifndef somthing
#define somthing
#endif

int main(){
	vector<int> vec;
	vec.insert(vec.begin(), 5, 6);
	for (vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
		cout << *it << "\n";
	}
	return 0;
}
