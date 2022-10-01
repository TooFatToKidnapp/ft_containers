/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:03:58 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/01 16:24:53 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE
#define RB_TREE

# include "./rb_node.hpp"
# include <functional> // std::less
# include <memory> // std::allocator

namespace ft {

	template<class Key, class T, class get_key_from_val, class Compare = std::less<Key>, class Alloc = std::allocator<Node<T> > >
	class RBT {

		public:
			typedef T					value_type;
			typedef Key					key_type;
			typedef Compare				key_compare;
			typedef Alloc				allocator_type;
			typedef Node<value_type>	node_type;
			typedef Node<value_type>*	node_ptr;
			typedef std::size_t			size_type;

		private:
			node_ptr		_root;
			node_ptr		_nil; // sentinal node
			key_compare		_comp;
			allocator_type	_alloc;
			size_type		_size;

		public:

		RBT(const key_compare &comp = key_compare(), const alloctor_type &alloc = allocator_type())
			: _comp(comp), _alloc(alloc), _size(0) {
				_nil = _alloc.allocate(1);
				_alloc.construct(_nill, node_type(value_type(), NULL, NULL, NULL, BLACK));
				_root = _nil;
			}

	};




} // namespace ft

#endif
