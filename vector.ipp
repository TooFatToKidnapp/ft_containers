/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.ipp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:17:07 by aabdou            #+#    #+#             */
/*   Updated: 2022/09/14 10:17:22 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// range constructor
// also called if passing 2 integers as first 2 params, insted if fill cons.
// Exceptions:
// std::distance may throw if arithnatical operations preformed on the iterators throw.
// allocator::allocate & allocator::construct may throw bad_alloc.
// note: if constructors throw, destructor is not called, so clean up should be done here b4 throw
template<class T, class Alloc>
template<class InputIterator>
ft::vector<T, Alloc>::vector(InputIterator first,
		InputIterator last, Alloc const &alloc) : _alloc(alloc){
	try{
		//checks if integral ype received. if so, its not an iterator.
		typedef typename ft::is_integral<InputIterator>::type	Integral;
		_range_dispatch(first, last, Integral());
	}
	catch(...){
		_alloc.deallocate(_array, _current_size);
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

			// ITERATOR FUNCITOTN
		// iteration is done in ordinary elment order

// returns iterator that points to the first element in a vector
template<class T, class Alloc>
typename ft::vector<T,Alloc>::iterator ft::vector<T, Alloc>::begin() {
	return iterator(this->_array);
}

template<class T, class Alloc>
typename ft::vector<T,Alloc>::const_iterator ft::vector<T, Alloc>::begin() const {
	return const_iterator(this->_array);
}

// returns iterator pointing to one past the last element
template<class T, class Alloc>
typename ft::vector<T,Alloc>::iterator ft::vector<T, Alloc>::end() {
	return iterator(this->_array + this->_current_size);
}

template<class T, class Alloc>
typename ft::vector<T,Alloc>::const_iterator ft::vector<T, Alloc>::end() const{
	return const_iterator(this->_array + this->_current_size);
}

//returns reverse iterator pointing to last element
template<class T, class Alloc>
typename ft::vector<T,Alloc>::reverse_iterator ft::vector<T, Alloc>::rbegin() {
	return reverse_iterator(end());
}

template<class T, class Alloc>
typename ft::vector<T,Alloc>::const_reverse_iterator ft::vector<T, Alloc>::rbegin() const{
	return const_reverse_iterator(end());
}

//returns reverse iterator pointing to first element
template<class T, class Alloc>
typename ft::vector<T,Alloc>::reverse_iterator ft::vector<T, Alloc>::rend() {
	return reverse_iterator(begin());
}

template<class T, class Alloc>
typename ft::vector<T,Alloc>::const_reverse_iterator ft::vector<T, Alloc>::rend() const{
	return const_reverse_iterator(begin());
}

template<class T, class Alloc>
typename ft::vector<T,Alloc>::allocator_type ft::vector<T, Alloc>::get_allocator() const{
	return this->_alloc;
}

		// element access finctions
//returns element at given index (dose not check for out of bounds)
template<class T, class Alloc>
typename ft::vector<T,Alloc>::reference ft::vector<T, Alloc>::operator[](size_type pos){
	return this->_array[pos];
}

template<class T, class Alloc>
typename ft::vector<T,Alloc>::const_reference ft::vector<T, Alloc>::operator[](size_type pos) const{
	return this->_array[pos];
}

// provides safer data access then [] by checking parameter befor access
// throws exception if pos is invalid index
template<class T, class Alloc>
typename ft::vector<T,Alloc>::reference ft::vector<T, Alloc>::at(size_type pos){
	if(pos >= this->_current_size)
		throw std::out_of_range("vector::at - index given is out of range");
	return this->_array[pos];
}

template<class T, class Alloc>
typename ft::vector<T,Alloc>::const_reference ft::vector<T, Alloc>::at(size_type pos) const{
	if(pos >= this->_current_size)
		throw std::out_of_range("vector::at - index given is out of range");
	return this->_array[pos];
}

// returns reference to data at the first elemnt of the vector
// calling front on an empty container is undefined
template<class T, class Alloc>
typename ft::vector<T,Alloc>::reference ft::vector<T, Alloc>::front(){
	return *begin();
}

template<class T, class Alloc>
typename ft::vector<T,Alloc>::const_reference ft::vector<T, Alloc>::front() const{
	return *begin();
}

// returns reference to data at the last element of the vector
template<class T, class Alloc>
typename ft::vector<T,Alloc>::reference ft::vector<T, Alloc>::back(){
	return *(end() - 1);
}

template<class T, class Alloc>
typename ft::vector<T,Alloc>::const_reference ft::vector<T, Alloc>::back() const{
	return *(end() - 1);
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

//	internal function called by range constructor
//	integer specialization
template<class T, class Alloc>
template<class Integer>
void	ft::vector<T, Alloc>::_range_dispatch(Integer n, Integer value, ft::true_type){
	size_type count = static_cast<size_type>(n);
	_array = _alloc.allocate(count);
	_current_size = count;
	_current_capacity = _current_size;
	_fill_insert(_array, count, value);
}
