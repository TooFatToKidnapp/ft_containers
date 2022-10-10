/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.ipp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:27:31 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/10 21:16:27 by aabdou           ###   ########.fr       */
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
	insert(first, last);
}

template<class Key, class T, class Compare , class Allocator>
MyMap::map(const map &obj)
	: _comp(obj._comp), _alloc(obj._alloc) {
		insert(obj.begin(), obj.end());
}

template<class Key, class T, class Compare , class Allocator>
MyMap::~map() {}

template<class Key, class T, class Compare , class Allocator>
MyMap &MyMap::operator=(const map &obj) {
	if (this != &obj) {
		if (this->_tree.getRoot() != this->_tree.getNil())
			clear();
		this->_comp = obj._comp;
		this->_alloc = obj._alloc;
		insert(obj.begin(), obj.end());
	}
	return *this;
}

template<class Key, class T, class Compare , class Allocator>
typename MyMap::iterator MyMap::begin() {
	return iterator(_tree.minimum(), _tree.getRoot(), _tree.getNil());
}

template<class Key, class T, class Compare , class Allocator>
typename MyMap::const_iterator MyMap::begin()const {
	return const_iterator(_tree.minimum(), _tree.getRoot(), _tree.getNil());
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
typename MyMap::reverse_iterator MyMap::rbegin() {
	return typename MyMap::reverse_iterator(end());
}

template<class Key, class T, class Compare , class Allocator>
typename MyMap::const_reverse_iterator MyMap::rbegin() const{
	return typename MyMap::const_reverse_iterator(end());
}

template<class Key, class T, class Compare , class Allocator>
typename MyMap::reverse_iterator MyMap::rend() {
	return typename MyMap::reverse_iterator(begin());
}

template<class Key, class T, class Compare , class Allocator>
typename MyMap::const_reverse_iterator MyMap::rend() const{
	return typename MyMap::const_reverse_iterator(begin());
}

template<class Key, class T, class Compare , class Allocator>
bool MyMap::empty() const {
	return (this->_tree.getSize() == 0);
}

template<class Key, class T, class Compare , class Allocator>
typename MyMap::size_type MyMap::size() const {
	return this->_tree.getSize();
}

template<class Key, class T, class Compare , class Allocator>
typename MyMap::size_type MyMap::max_size() const {
	return _tree.max_size();
}

template<class Key, class T, class Compare , class Allocator>
typename MyMap::mapped_type &MyMap::operator[](const typename MyMap::key_type &key) {
	node_ptr val = this->_tree.SearchTree(key);
	// TODO : if this method is too slow rethink it
	if (val != this->_tree.SearchTree(key))
		return val->data.second;
	else {
		_tree.InsertNode(value_type(key, mapped_type()));
		val = _tree.SearchTree(key);
		return val->data.second;
	}
}

template<class Key, class T, class Compare , class Allocator>
T& MyMap::at( const Key& key ) {
	node_ptr tmp = this->_tree.SearchTree(key);
	if (tmp == this->_tree.getNil())
		throw(std::out_of_range("ft::map.at(), key not found"));
	return tmp->data.second;
}

template<class Key, class T, class Compare , class Allocator>
const T& MyMap::at( const Key& key ) const {
	node_ptr tmp = this->_tree.SearchTree(key);
	if (tmp == this->_tree.getNil())
		throw(std::out_of_range("ft::map.at(), key not found"));
	return tmp->data.second;
}

template<class Key, class T, class Compare , class Allocator>
template<class InputIterator>
void MyMap::insert(InputIterator first, InputIterator last){
	while (first != last)
		insert(*first++);
}

template<class Key, class T, class Compare , class Allocator>
ft::pair<typename MyMap::iterator, bool> MyMap::insert(const typename MyMap::value_type &val) {
	typename MyMap::iterator it = find(val.first);
	if (it != end())
		return ft::pair<typename MyMap::iterator, bool>(it, false);
	else {
		this->_tree.InsertNode(val);
		it = find(val.first);
		return (ft::pair<typename MyMap::iterator, bool>(it, true));
	}
}

template<class Key, class T, class Compare , class Allocator>
void MyMap::clear() {
	_tree.ClearTree(_tree.getRoot());
}

template<class Key, class T, class Compare , class Allocator>
template<class InputIterator>
void MyMap::insert(InputIterator pos, const typename MyMap::value_type &val){
	(void)pos;
	return insert(val).first;
}


template<class Key, class T, class Compare , class Allocator>
void MyMap::erase(typename MyMap::iterator pos ){
	erase((*pos).first);
}

template<class Key, class T, class Compare , class Allocator>
void MyMap::erase(typename MyMap::iterator first, typename MyMap::iterator last){
	while(first != last)
		erase((*(first++)).first);
}

template<class Key, class T, class Compare , class Allocator>
typename MyMap::size_type MyMap::erase( const Key& key ) {
	if (this->_tree.DeleteNode(key) == true)
		return 1;
	return 0;
}

template<class Key, class T, class Compare , class Allocator>
void MyMap::swap( map& other ) {
	this->_tree.swap(other._tree);
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
