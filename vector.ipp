/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.ipp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:17:07 by aabdou            #+#    #+#             */
/*   Updated: 2022/09/16 11:27:50 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(Alloc const &alloc){
	this->_current_capacity = 0;
	this->_current_size = 0;
	this->_array = 	NULL;
	this->_alloc = alloc;
}

template<class T, class Alloc>
ft::vector<T, Alloc>::vector(size_type n, T const &val, Alloc const &alloc){
	this->_alloc = alloc;
	this->_current_size = n;
	this->_current_capacity = n;
	try{
		// allocate n objects with type T wiht out constructing them
		// throws bad_alloc if it cannot allocate the total amount
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
	this->clear();
	if(this->_array != NULL){
		this->_alloc.deallocate(this->_array, this->_current_capacity);
	}
}

// copy assifnment operator
template<class T, class Alloc>
ft::vector<T, Alloc> & ft::vector<T, Alloc>::operator=(const vector &obj){
	if (this != &obj){
		this->assign(obj.begin(), obj.end());
	}
	return *this;
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


	/// capacity functions

template<class T, class Alloc>
bool ft::vector<T,Alloc>::empty() const{
	if (this->_current_size == 0)
		return true;
	return false;
}

template<class T, class Alloc>
typename ft::vector<T,Alloc>::size_type ft::vector<T,Alloc>::size() const{
	return this->_current_size;
}

// the difference between vector start and end cannot exceed ptrdiff_max
// even if _alloc.max_size says we can , so we return the lesser value
template<class T, class Alloc>
typename ft::vector<T,Alloc>::size_type ft::vector<T,Alloc>::max_size() const{
	ft::vector<T, Alloc>::size_type max_diff = std::numeric_limits<ptrdiff_t>::max();
	ft::vector<T, Alloc>::size_type max_alloc = this->_alloc.max_size();
	return std::min(max_diff, max_alloc);
}

//	Only reallocates storage, increasing capacity to `cap`,
//	if `cap` > current capacity. Has no effect on current size.
//	Iterator invalidation:	if reallocation happens, all invalidated.
//	Exceptions:
//	If size requested > vector::max_size, throws length_error exception;
//	If reallocating, allocator may throw bad_alloc.
template<class T, class Alloc>
void ft::vector<T,Alloc>::reserve(size_type cap){
	if (cap > this->max_size())
		throw std::length_error("vector::reserve - new_cap exceeds vector max_size");
	if (cap > this->capacity()){
		_reallocate(cap);
	}
}

template<class T, class Alloc>
typename ft::vector<T,Alloc>::size_type ft::vector<T,Alloc>::capacity() const{
	return this->_current_capacity;
}

		//modifiers
// destroy current elements and replase with newly constucted ones
// automaticlly reallocates if new_size > current capacity
// iterator invalidation: all
template<class T, class Alloc>
void ft::vector<T,Alloc>::assign(size_type count, const T& value){
	_assign_fill(count, value);
}

template<class T, class Alloc>
template<class InputIterator>
void ft::vector<T,Alloc>::assign(InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*){
	_assign_range(first, last);
}

// after a clear() call size returns to 0 and capacity is unchanged
// iterator invalidation: all refs, ptrs, and iterators referring to contained elements
// no-throw guaranteed
template<class T, class Alloc>
void ft::vector<T, Alloc>::clear(){
	_destroy_until(this->begin(), this->end());
}

// Because vectors use an array as their underlying storage, inserting elements
// in positions other than the vector end causes the container to relocate
// all the elements after 'pos' to their new positions
// Reallocates exponentially (N * 2) if current capacity is insufficient.
// Iterator invalidation: If reallocation happens, all invalidated.
// If not, only after point of insertion.
// Exceptions: strong guarantee if exception occurs.
template<class T, class Alloc>
typename ft::vector<T,Alloc>::iterator	ft::vector<T,Alloc>::insert(iterator pos, T const &value){
	difference_type offset = ft::distance(this->begin(), pos);
	this->insert(pos, 1, value);
	return (this->_array + offset);
}


template<class T, class Alloc>
void ft::vector<T, Alloc>::insert(iterator pos, size_type count, T const &value){
	size_type		old_cap = this->capacity();
	difference_type	offset = ft::distance(this->begin(), pos);
	try{
		if (this->size() + count > this->capacity())
			_reallocate(std::max(this->capacity() * 2, this->size() + count));
		if (pos != this->end()){
			size_type	array_cap = this->capacity();
			pointer		tmp = _alloc.allocate(capacity());
			size_t		new_size = 0;
			// copy till 'pos' index, then insert new elements, after finish copying rest of
			// array to avoid invalid read issues
			new_size += _range_copy_forward(tmp, begin(), begin() + offset);
			new_size += _fill_insert(tmp + offset, count, value);
			new_size += _range_copy_forward(tmp + offset, count, begin() + offset, end());

			_destroy_until(this->begin(), this->end());
			_alloc.deallocate(this->_array, this->_current_capacity);
			this->_array = tmp;
			this->_current_size = new_size;
			this->_current_capacity = array_cap;
		}
		else
			this->_current_size += _fill_insert(this->_array + offset, count, value);
	}
	catch (...){
		if (old_cap < this->capacity())
			_alloc.deallocate(&*(this->_array + offset), this->capacity() - old_cap);
		throw;
	}
}

template<class T,class Alloc>
template<class InputIterator>
void ft::vector<T,Alloc>::insert(iterator pos, InputIterator first, InputIterator last,
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*){
	size_type		old_cap = this->capacity();
	difference_type	offset = ft::distance(this->begin(), pos);
	difference_type	count = ft::distance(first, last);
	try{
		if (this->size() + count > this->capacity())
			_reallocate(std::max(this->capacity() * 2, this->size() + count));
		if (pos != this->end()){
			size_type	array_cap = this->capacity();
			pointer		tmp = _alloc.allocate(capacity());
			size_t		new_size = 0;
			// copy till 'pos' index, then insert new elements, after finish copying rest of
			// array to avoid invalid read issues
			new_size += _range_copy_forward(tmp, begin(), begin() + offset);
			new_size += _range_copy_forward(tmp + offset, first, last);
			new_size += _range_copy_forward(tmp + offset, count, begin() + offset, end());

			_destroy_until(this->begin(), this->end());
			_alloc.deallocate(this->_array, this->_current_capacity);
			this->_array = tmp;
			this->_current_size = new_size;
			this->_current_capacity = array_cap;
		}
		else
			this->_current_size += _range_copy_forward(this->_array + offset, first, last);
	}
	catch (...){
		if (old_cap < this->capacity())
			_alloc.deallocate(&*(this->begin() + offset), this->capacity() - old_cap);
		throw;
	}
}

// Because vectors use an array as their underlying storage, erasing elements
// in positions other than the vector end causes the container to relocate
// all the elements after the segment erased to their new positions
// `pos` must be dereferencable. User has responsibility to pass valid input
// `end()` is not valid and causes undefined behaviour
// Iterator invalidation: erased elements and all following including end()
// Exceptions: does not throw unless exception is thrown by the assignment operator of T
// Returns:	iterator following last removed element
// If operation erased last element, end() is returned
template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator	ft::vector<T, Alloc>::erase(iterator pos){
	if (pos + 1 != this->end())
		_range_copy_forward(pos, pos + 1 , end());
	this->_current_size--;
	_alloc.destroy(&this->_array[this->_current_size - 1]);
	return pos;
}


// the iterator first dose not need to be dereferenceble if first==last
// erasing an empty range is a no-op
// invalid range causes undefined behaviour
// returns : first if empty range or first == end();
template<class T, class Alloc>
typename ft::vector<T, Alloc>::iterator	ft::vector<T, Alloc>::erase(iterator first, iterator last){
	if (first != last){
		iterator	saved_end = this->_array + this->_current_size;
		size_type	elems_after = ft::distance(last , saved_end);
		if (last != saved_end)
			_range_copy_forward(first, last, saved_end);
		_destroy_until((first + elems_after), saved_end);
	}
	return first;
}


// Iterator invalidation: If reallocation happens, all invalidated, If not, only end().
// Exceptions: strong guarantee, function has no effect.
// May throw length_error if reallocation exceeds max_size.
template<class T, class Alloc>
void ft::vector<T, Alloc>::push_back(T const & value){
	if(this->capacity() == this->size()){
		size_t len = 0;
		if (this->size() == 0)
			len = 1;
		else
			len = this->size() * 2;
		_reallocate(len);
	}
	this->_alloc.construct(this->_array + this->_current_size, value);
	this->_current_size++;
}

// iterator invalidation if elm earased and end()
template<class T, class Alloc>
void ft::vector<T, Alloc>::pop_back(){
	this->_alloc.destroy(this->_array + (this->_current_size - 1));
	this->_current_size--;
}


// changes only the number of elements is the container, not its capacity
// iterator invalidation if reallocation happens, all invalidated
// if resizing to smaller, at point of destruction uncluding end()
// exceptions: throws lenght_error if resized above max_size then function dose nothing
template<class T, class Alloc>
void	ft::vector<T,Alloc>::resize(size_type count, value_type val){
	if (count > this->max_size())
		throw std::length_error("vector::resize - count exceeds vector max_size");
	else if (count < this->size())
		_destroy_until(this->_array + count, this->_array + this->_current_size);
	else {
		this->reserve(count);
		while (count > this->size())
			push_back(val);
	}
}

template<class T, class Alloc>
void	ft::vector<T,Alloc>::swap(vector &other){
	size_type	tmp_size		= other._current_size;
	size_type	tmp_capacity	= other._current_capacity;
	pointer		tmp_array		= other._array;

	other._current_size			= this->_current_size;
	other._current_capacity		= this->_current_capacity;
	other._array				= this->_array;

	this->_current_size			= tmp_size;
	this->_current_capacity		= tmp_capacity;
	this->_array				= tmp_array;
}

			//privat helper functions
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

// internal function called by reserve ans insert
// reallocates array to new_cap size, copying over any existing elements
template<class T, class Alloc>
void	ft::vector<T,Alloc>::_reallocate(size_type new_cap){
	pointer		new_start = NULL;
	size_type	new_size = 0;

	try{
		new_start = this->_alloc.allocate(new_cap);
		for(; new_size < this->_current_size ; new_size++){
			_alloc.construct(new_start + new_size, this->_array[new_size]);
		}
		this->_alloc.deallocate(this->_array, this->_current_capacity);
		this->_array = new_start;
		this->_current_size = new_size;
		this->_current_capacity = new_cap;
	}
	catch(...){
		if (new_start)
			this->_alloc.deallocate(new_start, new_cap);
	}
}

// internal function called bt assign
template<class T, class Alloc>
void	ft::vector<T,Alloc>::_assign_fill(size_type count, const T& value){
	this->clear();
	if (count == 0)
		return;
	this->reserve(count);
	this->insert(begin(), count, value);
}


// inturnal function called by assign (range)
template<class T, class Alloc>
template<class InputIterator>
void	ft::vector<T,Alloc>::_assign_range(InputIterator first, InputIterator last){
	size_type	count = ft::distance(first, last);

	this->clear();
	if (count == 0)
		return ;
	this->reserve(count);
	for (; first != last; ++first)
		push_back(*first);
}

// internal function called bt resize, erase
// destroys elements from 'end' to 'start' and adjusts size
// if end exceeds start , do nothing
template<class T,class Alloc>
void	ft::vector<T,Alloc>::_destroy_until(iterator end, iterator start){
	if (start - end){
		for (; end != start; end++) {
			_alloc.destroy(&*end);
			this->_current_size -= 1;
		}
	}
	return;
}

// internal function called by erase, insert, _range_dispatch (range constructor)
// insets element in range [first, last] at 'pos'
// return number of elements copied
template<class T, class Alloc>
template<class InputIterator>
size_t	ft::vector<T,Alloc>::_range_copy_forward(iterator pos, InputIterator first, InputIterator last){
	size_type	copied = 0;

	while (first != last){
		_alloc.construct(&*pos, *first);
		++pos;
		++first;
		++copied;
	}
	return copied;
}
