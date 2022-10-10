/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:27:28 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/10 21:15:48 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory> //std::allocator
#include <functional> //std::less a funny way of saying <
#include <stdexcept> //std::out_of_range
#include "../utils/pair.hpp"
#include "../utils/Bidirectional_Iterator.hpp"

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
			T&			at( const Key& key );
			const T&	at( const Key& key ) const;

			template<class InputIterator>
			void						insert(InputIterator first, InputIterator last);

			ft::pair<iterator, bool>	insert(const value_type &val);

			template<class InputIterator>
			void						insert(InputIterator pos, const value_type &val);

			void clear();

			void 		erase( iterator pos );
			void		erase(iterator first, iterator last);
			size_type	erase( const Key& key );

			void swap(map& other);

			iterator find(const key_type &key);
			const_iterator find(const key_type &key) const;


};


} // namespace ft

#include "./map.ipp"

#endif
