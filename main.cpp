#include "allocator.hpp"
#include "vector.hpp"
#include <list>
#include<vector>

using std::cout;
using ft::vector;

void printCollection (const std::list<int>& l)
{
	std::list<int>::const_iterator itt = l.begin();
	for(; itt != l.end(); itt++){
		cout << *itt << " ";
	}
	cout << "\n";
}

bool check(int one, int two){
	if (one > two)
		return true;
	return false;
}

bool lessForCollection (const std::list<int>& l1, const std::list<int>& l2)
{
return ft::lexicographical_compare
(l1.cbegin(), l1.cend(), // first range
l2.cbegin(), l2.cend()); // second range
}
int main()
{
std::list<int> c1, c2, c3, c4;
// fill all collections with the same starting values
for(int i = 0; i < 5 ; i++){
	c1.push_back(-1);
}
c4 = c3 = c2 = c1;
// and now some differences
c1.push_back(7);
c3.push_back(2);
c3.push_back(0);
c4.push_back(2);
// create collection of collections
std::vector<std::list<int> > cc;
cc.insert ( cc.begin(), { c1, c2, c3, c4, c3, c1, c4, c2 } );
// print all collections
for_each (cc.cbegin(), cc.cend(),
printCollection);
cout << std::endl;
// sort collection lexicographically
sort (cc.begin(), cc.end(), // range
lessForCollection); // sorting criterion
// print all collections again
for_each (cc.cbegin(), cc.cend(),
printCollection);
}

