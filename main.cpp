#include "./containers/vector.hpp"
#include "./containers/stack.hpp"
#include "./containers/map.hpp"
#include "./containers/set.hpp"
#include "./utils/pair.hpp"
#include "./utils/rb_tree.hpp"
#include "./utils/Bidirectional_Iterator.hpp"
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
	set<int> var;
	for (int i = 0; i < 10 ; ++i){
		var.insert(i * 2);
	}
	set<int> var2(var.begin(), var.end());
	var2.insert(1);
	if (var2 >= var)
		cout << "true\n";

	// cout << var.size() << "\n";
	// for (set<int>::iterator it = var.begin(); it != var.end(); ++it){
	// 	cout << "here: " << *it << "\n";
	// }




}
