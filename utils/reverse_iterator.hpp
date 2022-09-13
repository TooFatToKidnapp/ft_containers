/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:06:51 by aabdou            #+#    #+#             */
/*   Updated: 2022/09/13 10:37:28 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "./iterator.hpp"

namespace ft {
	template<class Iterator>
	class reverse_iterator
		:	public iterator<typename ft::iterator_traits<Iterator>::iterator_category,
							typename ft::iterator_traits<Iterator>::value_type,
							typename ft::iterator_traits<Iterator>::difference_type,
							typename ft::iterator_traits<Iterator>::pointer,
							typename ft::iterator_traits<Iterator>::reference>{

		private:
			typedef ft::iterator_traits<Iterator>	_traits_type;

		public:
			typedef Iterator								iterator_type;
			typedef typename _traits_type::defference_type	difference_type;
			typedef typename _traits_type::defference_type	difference_type;
			typedef typename _traits_type::reference		reference;

		// default constructor
		reverse_iterator() : _current(NULL){}
		// initialise constructor with a pointer
		explicit reverse_iterator(iterator_type p) : _current(p){}
		//copy constructor
		template<class Iter>
		reverse_iterator(reverse_iterator<Iter> const & obj) : _current(obj.base()) {}
		// destructor
		~reverse_iterator(){}
		// returns the used iterator
		iterator_type base() const{
			return _current;
		}
		// returns a reference to the value at _current (if dereferenceable)
		// internally, function decreases a copy of base iterator and
		// returns result of dereferencing this.
		reference operator*() const{
			Iterator tmp = _current;
			return *(--tmp);
		}
		//return a pointer to the value at _current (if dereferenceable)
		pointer operator->() const {
			return &(operator*());
		}
		// returns the value at current + n
		reference operator[](difference_type n) const {
			return *(this + n);
		}
		// returns an iterator referring to _current - `n`.
		reverse_iterator	operator+(difference_type n) const {
			return reverse_iterator(_current - n);
		}
		// ++i
		reverse_iterator &operator++(){
			--_current;
			return *this;
		}
		// i++
		reverse_iterator operator++(int){
			reverse_itertor tmp = *this;
			--_current;
			return tmp;
		}
		// move the iterator n steps
		//reverse_iterator





		protected:
			Iterator	_current;
	};
}



#endif
