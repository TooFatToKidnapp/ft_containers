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

int main()
{
	map<int , std::string> Map;
	Map[-1] = "text";
	Map[5846] = "somthing";

	Map[11];
	Map[1] = "ali";
	std::string name = "hello";
	ft::pair<int , std::string> p;
	p.first = 0;
	p.second = name;
	//Map.insert(0, name);
	if (Map.find(-1) != Map.end())
		cout << "true\n";
	cout << Map.at(-1) << "\n";
	Map.erase(-1);
	map<int,std::string>::iterator it = Map.begin();
	for(; it != Map.end(); ++it){
		cout << it->first << " " << it->second << "\n";
	}
}
