/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.ipp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 16:27:31 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/09 15:42:00 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./map.hpp"

namespace ft {

template<class Key, class T, class Compare , class Allocator>
ft::map<Key, T, Compare, Allocator>::map(const Compare &comp, const Allocator &alloc)
				: _comp(comp), _alloc(alloc), _tree() {}


template<class Key, class T, class Compare , class Allocator>
template<class InputIterator>
ft::map<Key, T, Compare, Allocator>::map(InputIterator first, InputIterator last, const key_compare &comp, const allocator_type& alloc)
				: _comp(comp), _alloc(alloc), _tree() {
	// TODO: creat and call the insert finction 
}

} // namespace ft
