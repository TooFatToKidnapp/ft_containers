/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   equal.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 13:14:06 by aabdou            #+#    #+#             */
/*   Updated: 2022/09/16 13:57:47 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EQUAL_HPP
#define EQUAL_HPP

#include "./type_traits.hpp"

// p 542

namespace ft{

template<class Itt1, class Itt2>
bool equal(Itt1 first1, Itt1 last1, Itt2 first2,
			typename ft::enable_if<!ft::is_integral<Itt1>::value>::type* = NULL,
			typename ft::enable_if<!ft::is_integral<Itt2>::value>::type* = NULL){
	for(; first1 != last1; first1++, first2++){
		if (*first1 != *first2)
			return false;
	}
	return true
}

template<class Itt1, class Itt2, class BinaryPredicate>
bool equal(Itt1 first1, Itt1 last1, Itt2 first2, BinaryPredicate pred,
			typename ft::enable_if<!ft::is_integral<Itt1>::value>::type* = NULL,
			typename ft::enable_if<!ft::is_integral<Itt2>::value>::type* = NULL){
	for(; first1 != last1; first1++, first2++){
		if (!pred(*first1, *first2))
			return false;
	}
	return true
}

} // namespace ft



#endif
