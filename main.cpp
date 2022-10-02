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

ft::pair<int ,std::string> make_pair(int i, std::string str) {
	ft::pair<int ,std::string> var(i, str);
	return var;
}

int main(){

	ft::RBT<int , ft::pair<int, std::string> , get_key<ft::pair<int, std::string>, int > > tree;

	int tab[5] = {6, 100, 0, -25, 7};
	std::string str[5] = {"hello", "world", "xd", "test", "somthing"};
	for(int i = 0; i < 5; i++)
		tree.InsertNode(make_pair(tab[i], str[i]));
	cout << tree.getRoot()->data.first << " " <<tree.getRoot()->data.second << "\n";
	cout << "smallest val in tree "<< tree.getRoot()->data.first << " " << tree.getRoot()->data.second << "\n";
	tree.right_rotate(tree.getRoot());
	cout << "smallest val in tree "<< tree.getRoot()->data.first << " " << tree.getRoot()->data.second << "\n";
	if (tree.getRoot()->left == tree.getNil()){
		cout << "true\n";
	}
}

