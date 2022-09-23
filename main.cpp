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
	vec.push_back(10);
	vec.push_back(20);
	vec.push_back(40);
	vector<int > vec2;
	vec2.insert(vec2.begin(),vec.begin(), vec.end());
	vector<int>::iterator it = vec2.begin();
	for (; it != vec2.end(); ++it){
		cout << *it << "\n";
	}
}
