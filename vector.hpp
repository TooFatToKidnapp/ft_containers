/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:29:55 by aabdou            #+#    #+#             */
/*   Updated: 2022/09/10 18:37:25 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <algorithm> // max, mix, fill_n
#include <memory> // std::allocator
#include <cstddef> // ptrdiff_t / size_t
#include "allocator.hpp" // :(
#include "./utils/iterator.hpp"
#include "./utils/type_traits.hpp"

namespace ft
{
	template<typename T, class Alloc = std::allocator<T> >
	class vector {

		public:
			typedef T									value_type;
			typedef Alloc								allocator_type;
			typedef	std::size_t							size_type;
			typedef std::ptrdiff_t						difference_type;
			typedef typename Alloc::reference			reference;
			typedef typename Alloc::const_reference		const_reference;
			typedef typename Alloc::pointer				pointer;
			typedef typename Alloc::const_pointer		const_pointer;
			//itterators not yet implemented

			// vector's core
		private:
			Alloc						_alloc;
			size_type					_current_capacity;
			pointer						_array;
			size_type					_current_size;


			//member functions
		public:
		// constructors and assignment operators
			// default: empty container (only runs if its explicitly calld)
			explicit vector(Alloc const & alloc = Alloc());
			//fill container with n elem, each are a copy of val
			explicit vector(size_type n, T const &val = T(),
							Alloc const& alloc = Alloc());
			//copy container elms into another vector
			vector(vector const &obj);
			//destructor
			~vector();

		private:
			size_t _fill_insert(pointer pos, size_type count, T const& val);
	};
}

#include "vector.ipp"

#endif
