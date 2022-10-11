/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:26:18 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/11 15:45:40 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

#include"./type_traits.hpp"

namespace ft {

// p 548

template<class Itt1, class Itt2>
bool	lexicographical_compare(Itt1 start1, Itt1 end1, Itt2 start2, Itt2 end2){
	while(start1 != end1 || start2 != end2){
		if (start2 == end2)
			return false;
		if (start1 == end1)
			return true;
		if (*start1 < *start2)
				return true;
		if (*start1 > *start2)
				return false;
		++start1;
		++start2;
	}
	return false;
}

template<class Itt1, class Itt2, class CompFunc>
bool	lexicographical_compare(Itt1 start1, Itt1 end1, Itt2 start2,
								Itt2 end2, CompFunc op){
	while(start1 != end1 || start2 != end2){
		if (start2 == end2)
			return false;
		if (start1 == end1)
			return true;
		if (op(*start1, *start2))
				return true;
		if (op(*start2, *start1))
				return false;
		++start1;
		++start2;
	}
	return false;
}


} // namespace ft





#endif
