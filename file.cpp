#include<iostream>
#include<vector>
#include<memory>
#include "allocator.hpp"

class Int
{
	private:
		static bool bIsconstructed;
	public:
		int x;
		Int(int i)
		{
			std::cout << "constructing" << (void *)this << std::endl;
			x = i;
			bIsconstructed = true;
		}
		~Int()
		{
			std::cout << "Dustructing" << (void *)this << std::endl;
			bIsconstructed = false;
		}
		Int &operator++()
		{
			x++;
			return *this;
		}
};

int main()
{
	std::vector<int, custom_Allocator<int> > v;
	return 0;
}
