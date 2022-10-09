/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.ipp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:27:31 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/09 18:20:35 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./map.hpp"

#define  MyMap ft::map<Key, T, Compare, Allocator>

namespace ft {

template<class Key, class T, class Compare , class Allocator>
MyMap::map(const Compare &comp, const Allocator &alloc)
				: _comp(comp), _alloc(alloc), _tree() {}

template<class Key, class T, class Compare , class Allocator>
template<class InputIterator>
MyMap::map(InputIterator first, InputIterator last, const key_compare &comp, const allocator_type& alloc)
				: _comp(comp), _alloc(alloc), _tree() {
	// TODO: creat and call the insert finction
}

template<class Key, class T, class Compare , class Allocator>
MyMap::map(const map &obj)
	: _comp(obj._comp), _alloc(obj._alloc) {
		// insert here too
}

template<class Key, class T, class Compare , class Allocator>
MyMap::~map() {}

template<class Key, class T, class Compare , class Allocator>
MyMap &MyMap::operator=(const map &obj) {
	if (this != &obj) {
		if (this->_tree.getRoot() != this->_tree.getNil())
			// clear
		this->_comp = obj._comp;
		this->_alloc = obj._alloc;
		// insert
	}
	return *this;
}

template<class Key, class T, class Compare , class Allocator>
typename MyMap::iterator MyMap::end() {
	return iterator(_tree.getNil(), _tree.getRoot(), _tree.getNil());
}

template<class Key, class T, class Compare , class Allocator>
typename MyMap::const_iterator MyMap::end()const {
	return const_iterator(_tree.getNil(), _tree.getRoot(), _tree.getNil());
}





template<class Key, class T, class Compare , class Allocator>
template<class InputIterator>
void MyMap::insert(InputIterator first, InputIterator last){
	while (first != last)
		insert(*first++)
}

template<class Key, class T, class Compare , class Allocator>
ft::pair<typename MyMap::iterator, bool> MyMap::insert(const typename MyMap::value_type &val) {
	typename ft::map::iterator it = find(val.first);
	if (it != end())
		return ft::pair<typename MyMap::iterator, bool>(it, false);
	else {
		this->_tree.InsertNode(val);
	}
}

template<class Key, class T, class Compare , class Allocator>
typename MyMap::iterator MyMap::find(const typename MyMap::key_type &key) {
	node_ptr tmp = _tree.SearchTree(key);
	if (tmp == _tree.getNil())
		return end();
	return iterator(tmp, _tree.getRoot(), _tree.getNil());
}

template<class Key, class T, class Compare , class Allocator>
typename MyMap::const_iterator MyMap::find(const typename MyMap::key_type &key) const {
	node_ptr tmp = _tree.SearchTree(key);
	if (tmp == _tree.getNil())
		return end();
	return const_iterator(tmp, _tree.getRoot(), _tree.getNil());
}





} // namespace ft
