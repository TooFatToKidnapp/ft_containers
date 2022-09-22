/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BidirectionalIterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 16:28:42 by aabdou            #+#    #+#             */
/*   Updated: 2022/09/22 16:42:48 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_HPP
#define BIDIRECTIONALITERATOR_HPP

#include "./iterator.hpp" // iterator tags

namespace ft {

	template<class T>
	class BidirectionalIterator : public ft::iterator<ft::bidirectional_iterator_tag, T>
	{
		public:
			typedef T	value_type;
			typedef T&	reference;
			typedef T*	pointer;

			typedef ft::bidirectional_iterator_tag iterator_category;
			typedef std::ptrdiff_t					difference_type;

			typedef BidirectionalIterator<T>		self;
	};


} // namespace ft



#endif
