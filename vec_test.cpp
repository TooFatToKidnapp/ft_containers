#include<vector>
#include<iterator>
#include<iostream>

using std::cout;


int main(){
	cout << "================std::vector test ==================\n";
	std::vector<int> vec;
	int i = 0;
	for(; i < 10; i++)
		vec.push_back(i + 2);
	std::vector<int> tmp = vec;
	std::vector<int>::iterator itt2 = tmp.begin();
	std::vector<int>::iterator itt = vec.begin();
	for(; itt != vec.end(); itt++, itt2++){
		std::cout <<*itt << "\n";
		std::cout <<*itt2 << "\n";
	}

}
