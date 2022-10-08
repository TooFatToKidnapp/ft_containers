/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bidirectional_Iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:28:42 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/08 17:19:19 by aabdou           ###   ########.fr       */
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


	};


} // namespace ft



#endif
