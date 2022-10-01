/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:03:58 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/01 18:04:58 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RB_TREE
#define RB_TREE

# include "./rb_node.hpp"
# include <functional> // std::less
# include <memory> // std::allocator

// p 308 intro to algorithms

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

			~RBT() {
				// TODO: add recursive fun to clear the tree (virtual ???)
				_alloc.destroy(_nil);
				_alloc.dealocate(_nil, 1);
			}

			node_ptr	getRoot() const {
				return this->_root;
			}

			node_ptr	getNil() const {
				return this->_nil;
			}

			size_type	getSize() const {
				return this->_size;
			}

			size_type	max_size() const {
				return _alloc.max_size();
			}

			// get the smallest key value in the tree
			node_ptr minimum() const {
				node_ptr tmp = _root;
				if (tmp == _nil)
					return _root;
				while (tmp->left != _nil)
					tmp = tmp->left;
				return tmp;
			}

			// get max key value in the tree
			node_ptr maximum() const {
				node_ptr tmp = _root;
				if (tmp == _nil)
					return _root;
				while (tmp->right != _nil)
					tmp = tmp->right;
				return tmp;
			}

			node_ptr minimum(node_ptr node) const {
				if (node == _nil)
					return _root;
				while (node->left != _nil)
					node = node->left;
				return node;
			}

			node_ptr maximum(node_ptr node) const {
				if (node == _nil)
					return _root;
				while (node->right != _nil)
					node = node->right;
				return node;
			}
			
	};




} // namespace ft

#endif
