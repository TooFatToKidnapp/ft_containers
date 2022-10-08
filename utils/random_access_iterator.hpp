/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:17:12 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/08 14:37:13 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP

#include "iterator.hpp"

namespace ft {

	template<class T>
	class random_access_iterator : public ft::iterator<ft::random_access_iterator_tag, T>{
		private:
			typedef ft::iterator<ft::random_access_iterator_tag, T> _it_type;

		public:
			typedef typename _it_type::difference_type	difference_type;
			typedef typename _it_type::pointer			pointer;
			typedef typename _it_type::reference		reference;

		protected:
			pointer _current;

		public:
		// constructors and destructors
			// default constructor
			random_access_iterator(void) : _current(NULL){}
			// initialise constructor with a pointer
			random_access_iterator(pointer ptr) : _current(ptr) {}
			// copy constructor
			random_access_iterator(const random_access_iterator & obj) : _current(obj._current) {}
			// assignment operator
			random_access_iterator& operator=(const random_access_iterator  &obj){
				if (this != &obj)
					this->_current = obj._current;
				return *this;
			}
			// destructor
			~random_access_iterator(void) {}

			// return _current, the iterator used for underlying work
			pointer base(void) const {
				return _current;
			}

		// operators
			//returns a ref to the value at _current (if derefrenceable)
			reference	operator*()const{
				return *_current;
			}

			//returns a pointer to the value at _current (if derefrenceable)
			pointer	operator->() const{
				return _current;
			}

			//returns value at _current + 'n'
			reference	operator[](difference_type n) const{
				return _current[n];
			}

			//user defined conversion function for converting to const it
			operator random_access_iterator<T const>() const{
				return random_access_iterator<T const>(_current);
			}

			// returns an iterator rederring to _curent + 'n'
			random_access_iterator operator+(difference_type n) const {
				return random_access_iterator(_current + n);
			}

			// pre-increment ++i
			random_access_iterator &operator++(){
				++_current;
				return *this;
			}

			// post-increment i++
			random_access_iterator operator++(int){
				random_access_iterator tmp = *this;
				++_current;
				return tmp;
			}

			// moves iterator forward n steps
			random_access_iterator &operator+=(difference_type n){
				_current += n;
				return *this;
			}

			// returns it rederring to _current -n
			random_access_iterator operator-(difference_type n) const {
				return random_access_iterator(_current - n);
			}

			// --i
			random_access_iterator &operator--(){
				--_current;
				return *this;
			}

			// i--
			random_access_iterator operator--(int){
				random_access_iterator tmp = *this;
				--_current;
				return tmp;
			}

			// move backwards n steps
			random_access_iterator &operator-=(difference_type n){
				_current -= n;
				return *this;
			}
	};

	// non member functions

		//return distance in address between 2 it
		template<class T>
		typename random_access_iterator<T>::difference_type operator-(
			random_access_iterator<T> const &start,
			random_access_iterator<T> const end){
			return start.base() - end.base();
		}

		// op- must support mixed const / non const iterator param
		template<class TL, class TR>
		typename random_access_iterator<TL>::difference_type operator-(
			random_access_iterator<TL> const &start,
			random_access_iterator<TR> const &end){
				return start.base() - end.base();
			}

		template<class T>
		random_access_iterator<T> operator+(
			typename random_access_iterator<T>::difference_type n,
			random_access_iterator<T> const & i){
				return random_access_iterator<T>(i.base() + n);
			}

		template<class T>
		bool	operator==(random_access_iterator<T> const &obj,
			random_access_iterator<T> const &obj2){
				return (obj.base() == obj2.base());
			}

		// for comparison between defferent typed iterators (const == non const)
		template<class TL,class TR>
		bool	operator==(random_access_iterator<TL> const &obj,
			random_access_iterator<TR> const &obj2){
				return (obj.base() == obj2.base());
			}


		template<class T>
		bool	operator!=(const random_access_iterator<T>  &obj,
			const random_access_iterator<T>  &obj2){
				return obj.base() != obj2.base();
			}

		// for comparison between defferent typed iterators (const == non const)
		template<class TL,class TR>
		bool	operator!=(random_access_iterator<TL> const &obj,
			random_access_iterator<TR> const &obj2){
				return obj.base() != obj2.base();
			}

		template<class T>
		bool	operator<(random_access_iterator<T> const &obj,
			random_access_iterator<T> const &obj2){
				return obj.base() < obj2.base();
			}

		// const < non const
		template<class TL, class TR>
		bool	operator<(random_access_iterator<TL> const &obj,
			random_access_iterator<TR> const &obj2){
				return obj.base() < obj2.base();
			}

		template<class T>
		bool	operator>(random_access_iterator<T> const &obj,
			random_access_iterator<T> const &obj2){
				return obj.base() > obj2.base();
			}

		// const < non const
		template<class TL, class TR>
		bool	operator>(random_access_iterator<TL> const &obj,
			random_access_iterator<TR> const &obj2){
				return obj.base() > obj2.base();
			}

		template<class T>
		bool	operator<=(random_access_iterator<T> const &obj,
			random_access_iterator<T> const &obj2){
				return obj.base() <= obj2.base();
			}

		// const < non const
		template<class TL, class TR>
		bool	operator<=(random_access_iterator<TL> const &obj,
			random_access_iterator<TR> const &obj2){
				return obj.base() <= obj2.base();
			}

		template<class T>
		bool	operator>=(random_access_iterator<T> const &obj,
			random_access_iterator<T> const &obj2){
				return obj.base() >= obj2.base();
			}

		// const < non const
		template<class TL, class TR>
		bool	operator>=(random_access_iterator<TL> const &obj,
			random_access_iterator<TR> const &obj2){
				return obj.base() >= obj2.base();
			}

} // namespace ft



#endif
