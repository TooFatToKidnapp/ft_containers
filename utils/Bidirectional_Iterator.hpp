/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bidirectional_Iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:28:42 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/09 13:47:06 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
#define BIDIRECTIONAL_ITERATOR_HPP

#include "./iterator.hpp" // iterator tags
#include "./rb_tree.hpp" // tree

namespace ft {

	template<class T, class N>
	class BidirectionalIterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef const T*						const_pointer;
			typedef const T&						const_reference;
			typedef N								node_type;
			typedef N*								node_ptr;
			typedef std::ptrdiff_t					difference_type;
			typedef ft::bidirectional_iterator_tag	iterator_category;

		protected:
			node_ptr _ptr;
			node_ptr _root;
			node_ptr _nil;

		public:
			BidirectionalIterator() : _ptr(NULL), _root(NULL), _nil(NULL) {}
			BidirectionalIterator(node_ptr ptr, node_ptr root, node_ptr nil) : _ptr(ptr), _root(root), _nil(nil) {}
			BidirectionalIterator(BidirectionalIterator const &obj) : _ptr(obj._ptr), _root(obj._root), _nil(obj._nil) {}
			BidirectionalIterator &operator=(BidirectionalIterator const & obj) {
				if (this != &obj) {
					this->_ptr = obj._ptr;
					this->_nil = obj._nil;
					this->_root = obj._root;
				}
				return (*this);
			}
			virtual ~BidirectionalIterator() {}

			// overload called when trying to copy construct a const_iterator
			// based on an iterator (const itt(non const itt))
			operator BidirectionalIterator<value_type const , node_type const>() const {
				return BidirectionalIterator<value_type const, node_type const>(_ptr, _root, _nil);
			}

			bool operator==(BidirectionalIterator<value_type, node_type> const &obj) const {
				return this->_ptr == obj._ptr;
			}

			bool operator!=(BidirectionalIterator<value_type, node_type> const &obj) const {
				return this->_ptr != obj._ptr;
			}

			template<class Iterator, class Itt>
			friend bool operator==(BidirectionalIterator<Iterator, ft::Node<Iterator> > const &obj, BidirectionalIterator<Itt, ft::Node<Itt> > const &obj2);

			template<class Iterator, class Itt>
			friend bool operator!=(BidirectionalIterator<Iterator, ft::Node<Iterator> > const &obj, BidirectionalIterator<Itt, ft::Node<Itt> > const &obj2);

			reference operator*() {
				return this->_ptr->data;
			}

			const_reference operator*() const {
				return this->_ptr->data;
			}

			pointer operator->() {
				return (&(operator*()));
			}

			const_pointer operator->() const {
				return (&(operator*()));
			}

			BidirectionalIterator &operator++() {
				if (this->_ptr != _nil)
					_ptr = successor(_ptr);
				return *this;
			}

			BidirectionalIterator operator++(int) {
				BidirectionalIterator tmp(*this);
				operator++();
				return tmp;
			}

			BidirectionalIterator &operator--() {
				if (this->_ptr == this->_nil)
					_ptr = maximum(this->_root);
				else
					this->_ptr = predecessor(this->_ptr);
				return *this;
			}

			BidirectionalIterator operator--(int) {
				BidirectionalIterator tmp(*this);
				operator--();
				return tmp;
			}

		protected:
			node_ptr maximum(node_ptr node) {
				while (node->right != this->_nil)
					node = node->right;
				return node;
			}

			node_ptr minimum(node_ptr node) {
				while (node->left != this->_nil)
					node = node->left;
				return node;
			}

			node_ptr predecessor(node_ptr node) {
				if (node->left != this->_nil) { // if the left subtree is not null the predecessor is the right most node is the left subtree
					return maximum(node->left);
				}
				else { // else it is the lowest ancestor of node whose right child is also an ancestor of node
					node_ptr x = node->parent;
					while (x != NULL && node == x->left) {
						node = x;
						x = x->parent;
					}
					return x;
				}
			}

			node_ptr successor(node_ptr node) {
				if (node->right != this->_nil) {
					return minimum(node->right);
				}
				else {
					node_ptr x = node->parent;
					while (x != NULL && node == x->right) {
						node = x;
						x = x->parent;
					}
					if (x == NULL)
						return _nil;
					return x;
				}
			}
	};


	template<class Iterator, class Itt>
	bool operator==(BidirectionalIterator<Iterator, ft::Node<Iterator> > const &obj, BidirectionalIterator<Itt, ft::Node<Itt> > const &obj2){
		return obj._ptr == obj2._ptr;
	}

	template<class Iterator, class Itt>
	bool operator!=(BidirectionalIterator<Iterator, ft::Node<Iterator> > const &obj, BidirectionalIterator<Itt, ft::Node<Itt> > const &obj2){
		return obj._ptr != obj2._ptr;
	}


} // namespace ft


#endif
