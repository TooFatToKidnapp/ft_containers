#include<iostream>
#include<vector>
#include<memory>
#include "allocator.hpp"

class Int
{
	public:
		int x;
		Int(){std::cout << "here" << std::endl;}
		Int(int i)
		{
			std::cout << "constructing " << (void *)this << std::endl;
			x = i;
		}
		~Int()
		{
			std::cout << "Dustructing " << (void *)this << std::endl;
		}
		Int &operator++()
		{
			x++;
			return *this;
		}
};


int main()
{
	Int *obj = (Int *)::operator new(1 * sizeof(Int));
	::operator delete(obj);
}
