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
		_fill_insert(this->_array, n, val);
	}
	catch (...){
		this->_alloc.deallocate(this->_array, n);
		throw;
	}

}

template<class T, class Alloc>
ft::vector<T, Alloc>::~vector(){
	//need func to clear the vector

	if(this->_array != NULL){
		this->_alloc.deallocate(this->_array, this->_current_capacity);
	}
}

//	copy constructor
//	all the elms in obj are copied but any unused capasity is not.
//	i.e capasity == size in the new vector
//	Note: if the constructor throws , the destructor is not called , so
//	deallocation is done here b4 throw
template<class T, class Alloc>
ft::vector<T, Alloc>::vector(const vector &obj){
	this->_alloc = obj._alloc;
	this->_current_size = obj._current_size;
	this->_current_capacity = this->_current_size;
	this->_array = this->_alloc.allocate(this->_current_size);
	try{
		*this = obj;
	}
	catch(...){
		this->_alloc.deallocate(this->_array, this->_current_size);
	}
}


//	internal function called by fill constractor
//	inserts count elements with the value 'value' at 'pos'
//	return nb of elms constructed
template<class T, class Alloc>
size_t ft::vector<T, Alloc>::_fill_insert(pointer pos, size_type count, T const& val){
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
