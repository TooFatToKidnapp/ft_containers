/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:03:58 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/01 18:53:33 by aabdou           ###   ########.fr       */
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

			void left_rotate(node_ptr node) {
				node_ptr tmp = node->right; // save node's right branch
				node->right = tmp->left; //node's new right child is tmp's old left child
				if (tmp->left != _nil) // if tmp->left is not NULL
					tmp->left->parent = node;
				tmp->parent = node->parent; // tmp is the new node so it takes node's parent
				if (node->parent == NULL)
					this->_root = tmp;
				else if (node == node->parent->left) // is node was its parents left child, tmp becomes its new parents left child
					node->parent->left = tmp;
				else
					node->parent->right = tmp; // mirror case
				tmp->left = node;
				node->parent = tmp;

			}

			void right_rotate(node_ptr node) //mirror case
			{
				node_ptr tmp = node->left;

				node->left = tmp->right;
				if (tmp->right != _nil)
					tmp->right->parent = node;
				tmp->parent = node->parent;
				if (node->parent == NULL)
					this->_root = tmp;
				else if (node == node->parent->left)
					node->parent->left = tmp;
				else
					node->parent->right = tmp;
				tmp->right = node;
				node->parent = tmp;
			}


	};




} // namespace ft

#endif
