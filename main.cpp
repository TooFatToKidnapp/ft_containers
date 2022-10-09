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
using std::map;
#ifndef somthing
#define somthing
#endif

ft::pair<int ,std::string> make_pair(int i, std::string str) {
	ft::pair<int, std::string> var(i, str);
	return var;
}


int main() {

	ft::RBT<int, ft::pair<int, std::string>, ft::get_key<ft::pair<int, std::string>, int> > tree;
	// ft::Node<int> val(10, NULL, NULL ,NULL, ft::RED);
	// tree.InsertNode(val);
	// ft::BidirectionalIterator<int, ft::Node<int> > var2(val, NULL, NULL);
	//ft::BidirectionalIterator<ft::Node<int>, int> var;
	//var = var2;
}

