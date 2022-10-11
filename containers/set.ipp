/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.ipp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:35:24 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/11 17:01:48 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./set.hpp"

#define MySet ft::set<T, Compare, Allocator>

namespace ft {

template<class T, class Compare, class Allocator>
MySet::set(const key_compare& comp, const allocator_type& alloc) : _tree() {
	this->_comp = comp;
	this->_alloc = alloc;
}

template<class T, class Compare, class Allocator>
template <class InputIterator>
MySet::set(InputIterator first, InputIterator last, const key_compare& comp, const allocator_type& alloc) : _tree() {
	this->_comp = comp;
	this->_alloc = alloc; (void)first; (void)last;
	// insert
}

template<class T, class Compare, class Allocator>
MySet::set(const set &obj) {
	this->_comp = obj._comp;
	this->_alloc = obj._alloc;
	// insert
}

template<class T, class Compare, class Allocator>
MySet::~set() {}



template<class T, class Compare, class Allocator>
typename MySet::iterator MySet::begin() {
	return iterator(_tree.minimum(), _tree.getRoot(), _tree.getNill());
}

template<class T, class Compare, class Allocator>
typename MySet::const_iterator MySet::begin()const {
	return const_iterator(_tree.minimum(), _tree.getRoot(), _tree.getNill());
}
template<class T, class Compare, class Allocator>
typename MySet::iterator MySet::end() {
	return iterator(_tree.getNil(), _tree.getRoot(), _tree.getNill());
}

template<class T, class Compare, class Allocator>
typename MySet::const_iterator MySet::end() const{
	return const_iterator(_tree.getNil(), _tree.getRoot(), _tree.getNill());
}

template<class T, class Compare, class Allocator>
typename MySet::iterator MySet::rbegin() {
	return reverse_iterator(end());
}

template<class T, class Compare, class Allocator>
typename MySet::const_iterator MySet::rbegin() const {
	return const_reverse_iterator(end());
}

template<class T, class Compare, class Allocator>
typename MySet::iterator MySet::rend() {
	return reverse_iterator(begin());
}

template<class T, class Compare, class Allocator>
typename MySet::const_iterator MySet::rend() const{
	return const_reverse_iterator(begin());
}



} // namespace ft
