/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:38:34 by aabdou            #+#    #+#             */
/*   Updated: 2022/09/02 18:36:18 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <iostream>
#include <cstddef>
#include <limits>

template<typename T>
class custom_Allocator {

	public:
		typedef T				value_type;
		typedef T				*pointer;
		typedef const T			*const_pointer;
		typedef T				&reference;
		typedef const T			&const_reference;
		typedef size_t			size_type;
		typedef ptrdiff_t		difference_type;

	template<typename U> //required for std::list to work properly (convert custom_Allocator<T> to )
	struct rebind {
		typedef custom_Allocator<U> other;
	};
	custom_Allocator(){}
	~custom_Allocator(){}
	custom_Allocator(const custom_Allocator &obj){}
	template<typename U>
	custom_Allocator(custom_Allocator<U> const &obj){}
		//address
	pointer address(reference r){
		return &r;
	}
	const_pointer address(const_reference r){
		return &r;
	}
		//memory allocation
	pointer allocate(size_type len, typename std::allocator<void>::const_pointer = 0){
		return reinterpret_cast<pointer>(::operator new(len * sizeof(T))); // allocate the given size of the type 'T' WITH OUT CONSTRUCTING IT (VERRY IMPORTENT)
	}
	void deallocate(pointer p, size_type len){
		::operator delete(p);
	}

};

#endif
