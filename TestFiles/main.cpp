#include "./../containers/vector.hpp"
#include "./../containers/stack.hpp"
#include "./../containers/map.hpp"
#include "./../containers/set.hpp"
#include "./../utils/pair.hpp"
#include "./../utils/rb_tree.hpp"
#include "./../utils/Bidirectional_Iterator.hpp"
#include <list>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <functional>
#include <algorithm>
#include <limits>
using std::cout;
using ft::vector;
using ft::stack;
using ft::pair;
using ft::map;
using ft::set;
#ifndef somthing
#define somthing
#endif

int main() {
	map<int, std::string > var;
	var[1] = "hello";
	var[-1] = "world";
	var[849] = "somthing";
	var[-94] = "xD";
	//set<int> var2(var);

	// cout << var.size() << " " << var2.size() << "\n";
	// if (var2 <= var)
	// 	cout << "true\n";
	map<int, std::string>::reverse_iterator it = var.rbegin();
	for (; it != var.rend(); ++it){
		cout << (*it).first << " " << (*it).second << "\n";
	}

}
