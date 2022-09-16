/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexicographical_compare.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 18:26:18 by aabdou            #+#    #+#             */
/*   Updated: 2022/09/16 18:41:42 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXICOGRAPHICAL_COMPARE_HPP
#define LEXICOGRAPHICAL_COMPARE_HPP

#include"./type_traits.hpp"

namespace ft{

// p 548

template<class Itt1, class Itt2>
bool	lexicographical_compare(Itt1 start1, Itt1 end1, Itt2 start2, Itt2 end2){
	for(; start1 != end1, start2 != end2; start1++, start2++){
		if (*start1 < *start2){
			if (start1 == end1 && start2 != end2)
				return true;
			else
				return false;
		}
	}
	return false;
}

} // namespace ft





#endif
