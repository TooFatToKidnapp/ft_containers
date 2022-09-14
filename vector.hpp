/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:29:55 by aabdou            #+#    #+#             */
/*   Updated: 2022/09/14 12:46:55 by aabdou           ###   ########.fr       */
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

		// vector access function
			reference			operator[](size_type pos);
			const_reference		operator[](size_type pos) const;
			reference			at(size_type pos);
			const_reference		at(size_type pos) const;
			reference			front();
			const_reference		front() const;
			reference			back();
			const_reference		back() const;

		// capacity functions

			// check if vector is empty
			bool		empty() const;
			// returns current number of elements
			size_type	size() const;
			// returns the max number of elements a vector can hold
			size_type	max_size() const;
			// requests enough space for at least 'cap' elements
			// only reallocating if capacity is less than 'cap'
			void		reserve(size_type cap);
			// returns number of elements container can hold before needing to reallocate
			// is necessary (done automaticlly by container)
			// this is not always equal to caontainer size
			size_type	capacity() const;

		// modifier functions
			// replaces current contents with 'count' elements, each initialized
			// to a copy of 'value'
			void		assign(size_type count, T const &value);
			// replace current contents with elements constructed from
			// elements in range [first,last] in the same order
			template<class InputIterator>
			void		assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL);
			// removes (destroys) all elements from the vector, leaving size of 0
			// reallocation id not guarenteed and capacity is not guarenteed to change
			// typical alternative that forces reallocation : vector<T>().swap(x);
			void		clear();
			// insert a single element at a specified 'pos', increasing the size by 1
			iterator	insert(iterator pos, const &value);


		private:
			size_t	_fill_insert(pointer pos, size_type count, T const& val);
			template<class Integer>
			void	_range_dispatch(Integer n, Integer value, ft::true_type);
			template<class InputIterator>
			void	_range_dispatch(InputIterator n, InputIterator value, ft::false_type);
			void	_reallocate(size_type new_size);
			void	_assign_fill(size_type count, const T& value);
			template<class InputIterator>
			void	_assign_range(InputIterator first, InputIterator last);
			void	_destroy_until(iterator start, iterator end);
	};
}

#include "vector.ipp"

#endif
