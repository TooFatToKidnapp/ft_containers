#include "./containers/vector.hpp"
#include "./containers/stack.hpp"
#include "./utils/pair.hpp"
#include "./utils/rb_tree.hpp"
#include "./utils/Bidirectional_Iterator.hpp"
#include "./containers/map.hpp"
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
using ft::map;
#ifndef somthing
#define somthing
#endif

ft::pair<int ,std::string> make_pair(int i, std::string str) {
	ft::pair<int, std::string> var(i, str);
	return var;
}


int main() {

	map<int, std::string> var;
	var[7] = "hello";
	var[-1] = "world";
	var[1] = "somthing";
	var[-111] = "xd";
	var[878] = "test";

	map<int, std::string> var2;
	var2[77] = "fff";
	var2[85] = "ppp";
	var2[-5] = "rrr";
	var2[0] = "zzz";

	var.swap(var2);

	map<int, std::string>::iterator it = var.begin();
	for (; it != var.end(); ++it)
		cout << "["<<(*it).first << "," << (*it).second << "] ";
	cout << var.size() <<"\n";

	map<int, std::string>::iterator itt = var2.begin();
	for (; itt != var2.end(); ++itt)
			cout << "["<<(*itt).first << "," << (*itt).second << "] ";
	cout << var2.size() << "\n";
	// cout << var.empty()<< "\n";

}
