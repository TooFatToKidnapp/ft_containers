#include "vector.hpp"

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(Alloc const &alloc){
	this->_current_capacity = 0;
	this->_current_size = 0;
	this->_array = nullptr;
	this->_alloc = alloc;
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(size_type n, T const &val, Alloc const &alloc){
	this->_alloc = alloc;
	this->_current_size = n;
	this->_current_capacity = n;
	try{
		this->_array = this->_alloc.allocate(n);
		fill_insert(this->_array, n, val);
	}
	catch (...){
		this->_alloc.deallocate(this->_array, n);
		throw;
	}

}


//	internal function called by fill constractor
//	inserts count elements with the value 'value' at 'pos'
//	return nb of elms constructed
template<class T, class Alloc>
size_t ft::vector<T, Alloc>::fill_insert(pointer pos, size_type count, T const& val){
	size_type constructed;
	try{
		pointer start = pos;
		for (constructed = 0; start != pos + count; constructed++, start++)
			this->_alloc.construct(start, val);
		return constructed;
	}
	catch(...) {
		for (size_type i = 0; i < constructed; i++)
			this->_alloc.destroy(pos + 1);
		throw;
	}
}
