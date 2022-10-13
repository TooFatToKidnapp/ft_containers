/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 10:06:51 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/13 14:51:09 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "./iterator.hpp"

namespace ft {
	template<class Iterator>
	class reverse_iterator {
		// :	public iterator<typename ft::iterator_traits<Iterator>::iterator_category,
		// 					typename ft::iterator_traits<Iterator>::value_type,
		// 					typename ft::iterator_traits<Iterator>::difference_type,
		// 					typename ft::iterator_traits<Iterator>::pointer,
		// 					typename ft::iterator_traits<Iterator>::reference>{

		private:
			typedef ft::iterator_traits<Iterator>	_traits_type;

		public:
			typedef Iterator									iterator_type;
			typedef typename _traits_type::difference_type		difference_type;
			typedef typename _traits_type::pointer				pointer;
			typedef typename _traits_type::reference			reference;
			// typedef typename _traits_type::iterator_category	iterator_category;
			// typedef typename _traits_type::value_type			value_type;

		// default constructor
		reverse_iterator() : _current(NULL){}
		// initialise constructor with a pointer
		explicit reverse_iterator(iterator_type p) : _current(p){}
		//copy constructor
		template<class Iter>
		reverse_iterator(reverse_iterator<Iter> const & obj) : _current(obj.base()) {}
		// destructor
		virtual ~reverse_iterator(){}
		reverse_iterator &operator=(reverse_iterator const &obj) {
			if (this != obj)
				this->_current = obj._current;
			return (*this);
		}
		// returns the used iterator
		iterator_type base() const{
			return _current;
		}
		// returns a reference to the value at _current (if dereferenceable)
		// internally, function decreases a copy of base iterator and
		// returns result of dereferencing this.
		reference operator*() const{
			Iterator tmp(_current);
			return *--tmp;
		}
		//return a pointer to the value at _current (if dereferenceable)
		pointer operator->() const {
			return &(operator*());
		}
		// returns the value at current + n
		reference operator[](difference_type n) const {
			return *(*this + n);
		}
		// returns an iterator referring to _current - `n`.
		reverse_iterator	operator+(difference_type n) const {
			return reverse_iterator<Iterator>(_current - n);
		}
		// ++i
		reverse_iterator &operator++(){
			--_current;
			return *this;
		}
		// i++
		reverse_iterator operator++(int){
			reverse_iterator<Iterator> tmp = *this;
			--_current;
			return tmp;
		}
		// move the iterator n steps
		reverse_iterator &operator+=(difference_type n){
			_current -= n;
			return *this;
		}
		// return an iterator referring to _current + n
		reverse_iterator operator-(difference_type n)const {
			return reverse_iterator<Iterator>(_current + n);
		}
		// --i
		reverse_iterator &operator--() {
			++_current;
			return *this;
		}
		// i--
		reverse_iterator operator--(int) {
			reverse_iterator tmp = *this;
			++_current;
			return tmp;
		}
		// moves iterator n steps
		reverse_iterator &operator-=(difference_type n) {
			_current += n;
			return *this;
		}

		protected:
			Iterator	_current;
};
	// non member functions
	template<class T>
	bool operator==(reverse_iterator<T> const & left,
					reverse_iterator<T> const & right){
		return (left.base() == right.base());
	}

	// for comparison between different typed iterators, i.e. const == non-const
	template<class TL, class TR>
	bool operator==(reverse_iterator<TL> const & left,
					reverse_iterator<TR> const & right){
		return (left.base() == right.base());
	}

	template<class T>
	bool operator!=(reverse_iterator<T> const &left,
					reverse_iterator<T> const &right){
		return (left.base() != right.base());
	}

	template<class TL, class TR>
	bool operator!=(reverse_iterator<TL> const &left,
					reverse_iterator<TR> const &right){
		return (left.base() != right.base());
	}

	template<class T>
	bool operator< (reverse_iterator<T> const &left,
					reverse_iterator<T> const &right){
		return (left.base() < right.base());
	}

	template<class TL, class TR>
	bool operator< (reverse_iterator<TL> const &left,
					reverse_iterator<TR> const &right){
		return (left.base() < right.base());
	}

	template<class T>
	bool operator> (reverse_iterator<T> const &left,
					reverse_iterator<T> const &right){
		return (left.base() > right.base());
	}
	// const > non-const
	template<class TL, class TR>
	bool operator> (reverse_iterator<TL> const &left,
					reverse_iterator<TR> const &right){
		return (left.base() > right.base());
	}

	template<class T>
	bool operator<=(reverse_iterator<T> const &left,
					reverse_iterator<T> const &right){
		return (left.base() >= right.base());
	}

	template<class TL, class TR>
	bool operator<=(reverse_iterator<TL> const &left,
					reverse_iterator<TR> const &right){
		return (left.base() >= right.base());
	}

	template<class T>
	bool operator>=(reverse_iterator<T> const &left,
					reverse_iterator<T> const &right){
		return (left.base() <= right.base());
	}

	template<class TL, class TR>
	bool operator>=(reverse_iterator<TL> const &left,
					reverse_iterator<TR> const &right){
		return (left.base() <= right.base());
	}
	// return distance in addewss between 2 iterators
	template<class T>
	typename reverse_iterator<T>::difference_type operator-(
							reverse_iterator<T> const &left,
							reverse_iterator<T> const &right){
			return (left.base() - right.base());
		}

	template<class TL, class TR>
	typename reverse_iterator<TL>::difference_type operator-(
							reverse_iterator<TL> const &left,
							reverse_iterator<TR> const &right){
			return (left.base() - right.base());
		}

	template<class T>
	reverse_iterator<T>operator++(
			typename reverse_iterator<T>::difference_type n,
			reverse_iterator<T> const &x) {
			return reverse_iterator<T>(x.base() - n);
		}

} //namespase ft


#endif
