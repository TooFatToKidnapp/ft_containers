#include<vector>
#include<iterator>
#include<iostream>

using std::cout;
using std::vector;

int main(){
	std::vector<int> vec(11, -1);
	cout << vec.capacity() << "-- \n";
	cout << vec.size() << "-- \n";
	for(int i = 0; i < 10 ; i++){
		vec.push_back(i*2);
	}
	cout << vec.capacity() << "-- \n";
	cout << vec.size() << "-- \n";
	std::vector<int>::iterator itt;
	for(itt = vec.begin(); itt != vec.end() ; itt++){
		cout << *itt << "\n";
	}
	cout << vec.capacity() << "-- \n";
	cout << vec.size() << "-- \n";
}
