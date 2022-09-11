/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 10:17:12 by aabdou            #+#    #+#             */
/*   Updated: 2022/09/11 10:32:06 by aabdou           ###   ########.fr       */
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
			typedef typename _it_type::differance_type	difference_type;
			typedef typename _it_type::pointer			pointer;
			typedef typename _it_type::reference		reference;

		protected:
			pointer _current;

		// constructors and destructors
			// default constructor
			random_access_iterator(void) : _current(NULL){}
			// initialise constructor with a pointer
			random_access_iterator(pointer ptr) : _current(ptr) {}
			// copy constructor
			random_access_iterator(const random_access_iterator & obj) : _current(obj._current) {}
			// assignment operator
			random_access_iterator& operator=(random_access_iterator const &obj){
				if (this != obj)
					this->_current = obj._current;
				return *this;
			}
			// destructor
			~random_access_iterator(void) {}

			// return _current, the iterator used for underlying work
			pointer base(void) const {
				return _current;
			}
	};
}



#endif
