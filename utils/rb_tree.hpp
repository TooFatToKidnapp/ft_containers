/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_tree.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 18:03:58 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/03 11:37:42 by aabdou           ###   ########.fr       */
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
			RBT(const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type())
				: _comp(comp), _alloc(alloc), _size(0) {
					_nil = _alloc.allocate(1);
					_alloc.construct(_nil, node_type(value_type(), NULL, NULL, NULL, BLACK));
					_root = _nil;
				}

			~RBT() {
				// TODO: add recursive fun to clear the tree (virtual ???)
				_alloc.destroy(_nil);
				_alloc.deallocate(_nil, 1);
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

			node_ptr	InsertNode(const value_type &data) {
				node_ptr node;
				node = _alloc.allocate(1);
				_alloc.construct(node, node_type(data, NULL, _nil, _nil, RED));

				node_ptr y = NULL;
				node_ptr x = _root;

				while (x != _nil) // find nodes natural palcement
				{
					y = x;
					if (_comp(get_key_from_val()(node->data), get_key_from_val()(x->data)))
						x = x->left;
					else if (_comp(get_key_from_val()(x->data), get_key_from_val()(node->data)))
						x = x->right;
					else { // x->data == data;
						_alloc.destroy(node);
						_alloc.deallocate(node, 1);
						return _nil;
					}
				}
				node->parent = y;
				if (y == NULL)
					this->_root = node;
				else if (_comp(get_key_from_val()(node->data), get_key_from_val()(y->data)))
					y->left = node;
				else
					y->right = node;
				this->_size++;
				// if new node is a root then return
				if (y == NULL) {
					node->colour = BLACK;
					return (this->_root);
				}
				if (node->parent->parent == NULL)
					return node;
				// check if tree needs fixing then fix it
				FixInsert(node);
				return node;
			}
			// bool DeleteNode(key_type key) {
			// 	return _DeleteNode(key);
			// }
			void Print() {
				_Print(this->_root);
				std::cout << "\n";
			}
			node_ptr SearchTree(key_type key) const {
				return _SearchTree(this->_root, key);
			}
		private:
			node_ptr _SearchTree(node_ptr node, key_type key) const {
				if (node == _nil)
					return _nil;
				if (key == get_key_from_val()(node->data))
					return node;
				if (node != _nil) {
					if (_comp(key, get_key_from_val()(node->data)))
						return _SearchTree(node->left, key);
					return _SearchTree(node->right, key);
				}
				return _nil;
			}
			// bool _DeleteNode(key_type key) {
			// 	// find the node containing the given key
			// 	node_ptr z, x, y;

			// 	z =
			// }
			void _Print(node_ptr node) {
				if (_root != _nil) {
					if (node->left != _nil){
						_Print(node->left);
					}
					std::cout <<"[" <<node->data.first << "," << node->data.second << "] ";
					if (node->right != _nil){
						_Print(node->right);
					}
				}
			}
		// tree helper functions
			void	FixInsert(node_ptr node) {
				node_ptr x;
				while (node->parent->colour == RED) {
					if (node->parent == node->parent->right) // parent is gp's right child
					{
						x = node->parent->parent->left; // uncel is left
						if (x->colour == RED) // if unc is also red
						{
							x->colour = BLACK;
							node->parent->colour = BLACK;
							node->parent->parent->colour = RED;
							node = node->parent->parent;
						}
						else {
							if (node == node->parent->left) // node is left child
							{
								node = node->parent;
								right_rotate(node); // new node is old parent
							}
							node->parent->colour = BLACK;
							node->parent->parent->colour = RED;
							left_rotate(node->parent->parent);
						}
					}
					else { // parent id gs's left child (mirror case)
						x = node->parent->parent->right; // uncle
						if (x->colour == RED) {
							// mirror case
							x->colour = BLACK;
							node->parent->colour = BLACK;
							node->parent->parent->colour = RED;
							node = node->parent->parent;
						}
						else {
							if (node == node->parent->right) {
								// mirror case
								node = node->parent;
								left_rotate(node);
							}
							// mirror case
							node->parent->colour = BLACK;
							node->parent->parent->colour = RED;
							right_rotate(node->parent->parent);
						}
					}
					if (node == _root)
						break;
				}
				_root->colour = BLACK;
			}

	};




} // namespace ft

#endif
