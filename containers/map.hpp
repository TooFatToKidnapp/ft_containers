/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:27:28 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/13 13:31:16 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory> //std::allocator
#include <functional> //std::less a funny way of saying <
#include <stdexcept> //std::out_of_range
#include "../utils/pair.hpp"
#include "../utils/Bidirectional_Iterator.hpp"
#include "../utils/allocator.hpp"

namespace ft{

	template <class T, class Key>
	struct get_key : public std::unary_function<T, Key> {
		const Key &operator()(const T &x) const {
			return x.first;
		}
	};

	template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map {
		public:

			// class used to compare elements of type value_type
			class value_compare;

			typedef Key											key_type;
			typedef T											mapped_type;
			typedef ft::pair<const Key, T>						value_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;
			typedef	typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;

			typedef ft::RBT<key_type, value_type, get_key<value_type, key_type>, key_compare> tree_type;
			typedef Node<value_type>	node_type;
			typedef Node<value_type>*	node_ptr;

			typedef ft::BidirectionalIterator<value_type, node_type>				iterator;
			typedef ft::BidirectionalIterator<value_type const, node_type const>	const_iterator;
			typedef ft::reverse_iterator<iterator>									reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;

		private:
			key_compare		_comp;
			allocator_type	_alloc;
			tree_type		_tree;

		public:

			explicit map(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type());
			template<class InputIterator>
			map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type());
			map(const map &obj);
			~map();
			map &operator=(const map &obj);

			iterator				begin();
			const_iterator			begin() const;
			iterator				end();
			const_iterator			end() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;

			bool			empty() const;
			size_type		max_size() const;
			size_type		size() const;

			mapped_type	&operator[](const key_type &key);
			T&			at(const Key& key);
			const T&	at(const Key& key) const;

			template<class InputIterator>
			void						insert(InputIterator first, InputIterator last);

			ft::pair<iterator, bool>	insert(const value_type &val);

			template<class InputIterator>
			void						insert(InputIterator pos, const value_type &val);

			void clear();

			void 		erase( iterator pos );
			void		erase(iterator first, iterator last);
			size_type	erase( const Key& key );

			void			swap(map& other);
			key_compare		key_comp() const;
			value_compare	value_comp() const;

			iterator		find(const key_type &key);
			const_iterator	find(const key_type &key) const;

			size_type		count(const key_type &key) const;
			iterator		lower_bound(const key_type& k);
			const_iterator	lower_bound(const key_type& k) const;
			iterator		upper_bound(const key_type& k);
			const_iterator	upper_bound(const key_type& k) const;

			ft::pair<const_iterator,const_iterator>	equal_range(const key_type& k) const;
			ft::pair<iterator,iterator>				equal_range(const key_type& k);

			allocator_type	get_allocator() const;
};

template <class Key, class T, class Compare, class Alloc>
class map<Key, T, Compare, Alloc>::value_compare {
		friend class map;
	protected:
		Compare comp;
		value_compare(Compare c) : comp(c) {}
	public:
		typedef bool result_type;
		typedef value_type first_argument_type;
		typedef value_type second_argument_type;
		bool operator() (const value_compare & obj, const value_compare &obj2) {
			return (comp(obj.first, obj2.first));
		}
};

template<class Key, class T, class Compare, class Alloc>
bool operator==(const map<Key, T, Compare, Alloc> &first, const map<Key, T, Compare, Alloc> &second) {
	if (first.size() != second.size())
		return false;
	return ft::equal(first.begin(), first.end(), second.begin());
}

template<class Key, class T, class Compare, class Alloc>
bool operator!=(const map<Key, T, Compare, Alloc> &first, const map<Key, T, Compare, Alloc> &second) {
	return (!(second == first));
}

template<class Key, class T, class Compare, class Alloc>
bool operator<(const map<Key, T, Compare, Alloc> &first, const map<Key, T, Compare, Alloc> &second) {
	return ft::lexicographical_compare(first.begin(), first.end(), second.begin(), second.end());
}

template<class Key, class T, class Compare, class Alloc>
bool operator>(const map<Key, T, Compare, Alloc> &first, const map<Key, T, Compare, Alloc> &second) {
	return (second < first);
}

template<class Key, class T, class Compare, class Alloc>
bool operator<=(const map<Key, T, Compare, Alloc> &first, const map<Key, T, Compare, Alloc> &second) {
	return (!(second < first));
}

template<class Key, class T, class Compare, class Alloc>
bool operator>=(const map<Key, T, Compare, Alloc> &first, const map<Key, T, Compare, Alloc> &second) {
	return (!(first < second));
}

} // namespace ft

#include "./map.ipp"

#endif
