/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:29:55 by aabdou            #+#    #+#             */
/*   Updated: 2022/09/14 09:04:01 by aabdou           ###   ########.fr       */
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
#include "./utils/random_access_iterator.hpp"
#include "./utils/reverse_iterator.hpp"

namespace ft
{
	template<typename T, class Alloc = std::allocator<T> >
	class vector {

		public:
			typedef T												value_type;
			typedef Alloc											allocator_type;
			typedef	std::size_t										size_type;
			typedef std::ptrdiff_t									difference_type;
			typedef typename Alloc::reference						reference;
			typedef typename Alloc::const_reference					const_reference;
			typedef typename Alloc::pointer							pointer;
			typedef typename Alloc::const_pointer					const_pointer;
			typedef ft::random_access_iterator<value_type>			iterator;
			typedef ft::random_access_iterator<value_type const>	const_iterator;
			typedef ft::reverse_iterator<iterator>					reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;

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
			// range : container with first-last elements
			template<typename InputIterator>
			vector(InputIterator first, InputIterator last,
					 Alloc const & alloc = Alloc());
			//copy container elms into another vector
			vector(vector const &obj);
			// assignment operator
			vector &operator=(const vector &obj); // needs iterator metods
			//destructor
			~vector();

		// vector iterator functions
			iterator				begin();
			const_iterator			begin() const;
			iterator				end();
			const_iterator			end() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;

			//returns a copy of the allocator object assosciated with the vector
			allocator_type			get_allocator() const;

		private:
			size_t _fill_insert(pointer pos, size_type count, T const& val);
			template<class Integer>
			void _range_dispatch(Integer n, Integer value, ft::true_type);
			template<class InputIterator>
			void _range_dispatch(InputIterator n, InputIterator value, ft::false_type);
	};
}

#include "vector.ipp"

#endif
