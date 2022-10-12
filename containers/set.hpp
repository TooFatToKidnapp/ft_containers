/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:34:49 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/12 12:43:15 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <functional> // std::less<>, std::unary_function<>
#include <memory> // std::allocator<>
#include "./../utils/rb_tree.hpp"
#include "./../utils/rb_node.hpp"
#include "./../utils/Bidirectional_Iterator.hpp"
#include "./../utils/pair.hpp"

namespace ft
{
	template<class T, class Key>
	class get_key_from_val : public std::unary_function<T, Key>
	{
		public:
			const Key &operator()(const T &obj) const{
				return obj;
			}
	};

	template<class T, class Compare = std::less<T>, class Allocator = std::allocator<T> >
	class set {
		public:
			typedef T											key_type;
			typedef T											value_type;
			typedef Compare										key_compare;
			typedef Compare										value_compare;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;

			typedef ft::RBT<key_type, value_type, get_key_from_val<value_type, key_type>, key_compare> tree_type;
			typedef ft::Node<value_type> node_type;
			typedef ft::Node<value_type>* node_ptr;

			typedef ft::BidirectionalIterator<value_type const, node_type const>				iterator;
			typedef ft::BidirectionalIterator<value_type const, node_type const>	const_iterator;
			typedef ft::reverse_iterator<iterator>									reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;


		private:
			Compare			_comp;
			tree_type		_tree;
			allocator_type	_alloc;

		public:
			explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

			template <class InputIterator>
			set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

			set(const set &obj);

			~set();

			set &operator=(const set & obj);

			iterator			begin();
			const_iterator		begin()const;
			iterator			end();
			const_iterator		end() const;
			iterator			rbegin();
			const_iterator		rbegin() const;
			iterator			rend();
			const_iterator		rend() const;

			iterator find (const value_type& val) const;

			ft::pair<iterator,bool> insert(const value_type& val);
			iterator insert(iterator position, const value_type& val);
			template <class InputIterator>
			void insert(InputIterator first, InputIterator last);

			bool empty() const;
			size_type size() const;
			size_type max_size() const;
			void clear();

			void erase (iterator position);
			size_type erase (const value_type& val);
			void erase (iterator first, iterator last);
			void swap(set &obj);
			key_compare key_comp() const;
			value_compare value_comp() const;
			size_type count(const value_type &val) const;
			iterator lower_bound (const value_type& val) const;
			iterator upper_bound (const value_type& val) const;
			pair<iterator,iterator> equal_range (const value_type& val) const;
			allocator_type get_allocator() const;

	};

	template<class T, class Compare, class Allocator>
	bool operator==(const set<T, Compare, Allocator> &obj, const set<T, Compare, Allocator> &obj2) {
		if (obj.size() != obj2.size())
			return false;
		return ft::equal(obj.begin(), obj.end(), obj2.begin());
	}

	template<class T, class Compare, class Allocator>
	bool operator!=(const set<T, Compare, Allocator> &obj, const set<T, Compare, Allocator> &obj2) {
		return (!(obj2 == obj));
	}

	template<class T, class Compare, class Allocator>
	bool operator<(const set<T, Compare, Allocator> &obj, const set<T, Compare, Allocator> &obj2) {
		return (ft::lexicographical_compare(obj.begin(), obj.end(), obj2.begin(), obj2.end()));
	}

	template<class T, class Compare, class Allocator>
	bool operator<=(const set<T, Compare, Allocator> &obj, const set<T, Compare, Allocator> &obj2) {
		return (!(obj2 < obj));
	}

	template<class T, class Compare, class Allocator>
	bool operator>(const set<T, Compare, Allocator> &obj, const set<T, Compare, Allocator> &obj2) {
		return (obj2 < obj);
	}

	template<class T, class Compare, class Allocator>
	bool operator>=(const set<T, Compare, Allocator> &obj, const set<T, Compare, Allocator> &obj2) {
		return (!(obj < obj2));
	}

} // namespace ft


#include "./set.ipp"

#endif
