#include "./containers/vector.hpp"
#include "./containers/stack.hpp"
#include "./utils/pair.hpp"
#include "./utils/rb_tree.hpp"
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

template <class T, class Key>
struct get_key : public std::unary_function<T, Key> {
	const Key &operator()(const T &x) const {
		return x.first;
	}
};

ft::pair<std::string ,int> make_pair(int i, std::string str) {
	ft::pair<std::string ,int > var(str, i);
	return var;
}



int main() {
	int tab[6] = {125,548,-6,0,58,99};
	std::string arr[6] = {"hello", "world", "somthing", "xd", ":)", ":)"};
	ft::RBT<std::string , ft::pair<std::string, int> , get_key<ft::pair<std::string, int>, std::string > > tree;
	for (int i = 0; i < 6; i++)
		tree.InsertNode(make_pair(tab[i], arr[i]));

	tree.DeleteNode("hello");
	tree.Print();
}
