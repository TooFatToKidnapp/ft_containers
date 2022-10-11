/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 12:34:49 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/11 15:28:59 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
#define SET_HPP

#include <functional> // std::less<>
#include <memory> // std::allocator
#include "./../utils/rb_tree.hpp"
#include "./../utils/rb_node.hpp"
#include "./../utils/Bidirectional_Iterator.hpp"

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

			typedef ft::RBT<key_type, value_type, get_key_from_val<value_type, key_type>, key_compare> tree_type;
			typedef ft::Node<value_type> node_type;
			typedef ft::Node<value_type>* node_ptr;

			typedef ft::BidirectionalIterator<value_type const, node_type const>	iterator;
			typedef ft::BidirectionalIterator<value_type const, node_type const>	const_iterator;
			typedef ft::reverse_iterator<iterator>									reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>							const_reverse_iterator;

	};

} // namespace ft


#endif
