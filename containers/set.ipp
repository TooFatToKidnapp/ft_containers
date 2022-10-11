/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.ipp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:35:24 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/11 17:45:12 by aabdou           ###   ########.fr       */
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
	this->_alloc = alloc;
	insert(first, last);
}

template<class T, class Compare, class Allocator>
MySet::set(const set &obj) {
	this->_comp = obj._comp;
	this->_alloc = obj._alloc;
	insert(obj.begin(), obj.end());
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

template<class T, class Compare, class Allocator>
typename MySet::iterator MySet::find (const value_type& val) const {
	node_ptr tmp = _tree.SearchTree(val);
	if (tmp == _tree.getNill())
		return end();
	return iterator(tmp, _tree.getRoot(), _tree.getNil());
}

template<class T, class Compare, class Allocator>
ft::pair<typename MySet::iterator,bool> MySet::insert(const value_type& val) {
	iterator it = find(val);
	if (it != end())
		return ft::pair<iterator, bool>(it, false);
	else {
		_tree.InsertNode(val);
		it = find(val);
		return ft::pair<iterator, bool>(it, true);
	}
}

template<class T, class Compare, class Allocator>
typename MySet::iterator MySet::insert(iterator position, const value_type& val) {
	(void)position;
	return insert(val).first;
}

template<class T, class Compare, class Allocator>
template <class InputIterator>
void MySet::insert(InputIterator first, InputIterator last) {
	while (first != last)
		insert(*(first++));
}

} // namespace ft
