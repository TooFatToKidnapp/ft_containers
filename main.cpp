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

// #define __cplusplus 199711L

template<class T >
typename ft::enable_if<!ft::is_integral<T>::value>::type fun(T a)
{

	cout << "is integral " ;
	return a;
}

// template<class T>
// typename ft::enable_if<!ft::is_integral<T>::value>::type fun(T a)
// {
// 	cout << "not integral "
// 	return a;
// }

int main(){

	//cout << fun(12);
	//cout << fun(1.1);
	cout << std::boolalpha;
	cout << "char: " << ft::is_integral< unsigned long int>::value << "\n";
	cout << "char: " << std::is_integral<unsigned long int>::value << "\n";

}
