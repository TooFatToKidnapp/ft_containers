#include "allocator.hpp"
#include "vector.hpp"
#include <list>

using std::cout;
using ft::vector;

bool bothEvenOrOdd (int elem1, int elem2)
{
	return elem1 % 2 == elem2 % 2;
}
int main()
{
// vector<int> coll1;
// std::list<int> coll2;
// for(int i = 1; i < 8; i++){
// 	coll1.push_back(i * 3);
// 	cout << coll1[i - 1] << " ";
// }
// cout << "\n";
// for(int i = 1; i < 8; i++){
// 	coll2.push_back(i*2);
// }
// std::list<int>::iterator itt = coll2.begin();

// for(; itt != coll2.end(); itt++){
// 	cout << *itt << " ";
// }
// cout << "\n";

// // check whether both collections are equal
// if (ft::equal (coll1.begin(), coll1.end(), // first range
// 	coll2.begin())) { // second range
// 	cout << "coll1 == coll2" << std::endl;
// }
// else {
// 	cout << "coll1 != coll2" << std::endl;
// }
// // check for corresponding even and odd elements
// if (ft::equal (coll1.begin(), coll1.end(), // first range
// 	coll2.begin(), // second range
// 	bothEvenOrOdd)) { // comparison criterion
// 	cout << "even and odd elements correspond" << std::endl;
// }
// else {
// 	cout << "even and odd elements do not correspond" << std::endl;
// }

vector<int> vec;
vec.push_back(10);
vec.push_back(20);
vector<int> vec2;
vec2.push_back(10);
vec2.push_back(20);
if (vec != vec2)
	cout << "true\n";
else
	cout << "false\n";

}
