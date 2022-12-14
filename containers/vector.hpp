/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:29:55 by aabdou            #+#    #+#             */
/*   Updated: 2022/09/25 14:07:40 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <algorithm> // max, mix
#include <memory> // std::allocator
#include <cstddef> // ptrdiff_t / size_t
#include <stdexcept> // std::out_of_range
#include "./../utils/allocator.hpp" // :(
#include "./../utils/iterator.hpp"
#include "./../utils/type_traits.hpp"
#include "./../utils/random_access_iterator.hpp"
#include "./../utils/reverse_iterator.hpp"
#include "./../utils/equal.hpp"
#include "./../utils/lexicographical_compare.hpp"

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
		// constructors and assignment operator
			// default: empty container (only runs if its explicitly called)
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
			vector &operator=(const vector &obj);
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
			iterator	insert(iterator pos, T const &value);
			// insert 'count' elements initialized with the value 'value'
			void		insert(iterator pos, size_type count, T const &value);
			// inserts elements in range [first, last] at 'pos' in the same order
			template<class InputIterator>
			void		insert(iterator pos, InputIterator first, InputIterator last,
						typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = NULL);
			// erases (destroys) single element at 'pos', reducing the size by 1
			iterator	erase(iterator pos);
			// erases a range of elements
			iterator	erase(iterator first, iterator last);
			// adds new element to end of vector, copying/moving contant if value to it
			// increases the size by 1
			// automatic reallocation is only triggerd if new size surpasses current capacity
			void	push_back(T const & value);
			// removes and destroys last element , reducing size by 1
			void	pop_back();
			//resize container to contain n elements
			// if container size > 'count', container is reduced to count
			// if count > container size the vector is expanded to count
			// if 'val' id specified, new elems are initialized as copies of 'value'
			void	resize(size_type count, value_type val = T());
			// swaps content of container by content of 'other' container they have to be
			// the same type
			// size my differ, all iterators , references, pointers remain valid
			void	swap(vector &other);

		private:
			size_t	_fill_insert(pointer pos, size_type count, T const& val);
			template<class Integer>
			void	_range_dispatch(Integer n, Integer value, ft::true_type);
			template<class InputIterator>
			void	_range_dispatch (InputIterator n, InputIterator value, ft::false_type);
			void	_reallocate(size_type new_size);
			void	_assign_fill(size_type count, const T& value);
			template<class InputIterator>
			void	_assign_range(InputIterator first, InputIterator last);
			void	_destroy_until(iterator start, iterator end);
			template<class InputIterator>
			size_t	_range_copy_forward(iterator pos, InputIterator first, InputIterator last);

	};

	//non member functions overloads
		//relational operators
			template<class T, class Alloc>
			bool operator==(vector<T,Alloc> const &vec1, vector<T,Alloc> const &vec2){
				return (vec1.size() == vec2.size()
						&& ft::equal(vec1.begin(), vec1.end(), vec2.begin()));
			}
		// based on == operator
			template<class T, class Alloc>
			bool operator!=(vector<T,Alloc> const &vec1, vector<T,Alloc> const &vec2){
				return !(vec1 == vec2);
			}
		// returns true if vec1 < vec2
		// elems must be comparable wiht '<'
			template<class T, class Alloc>
			bool operator<(vector<T,Alloc> const &vec1, vector<T,Alloc> const &vec2){
				return (ft::lexicographical_compare(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()));
			}

			template<class T, class Alloc>
			bool operator<=(vector<T,Alloc> const &vec1, vector<T,Alloc> const &vec2){
				return !(vec2 < vec1);
			}
			template<class T, class Alloc>
			bool operator>(vector<T,Alloc> const &vec1, vector<T,Alloc> const &vec2){
				return (vec2 < vec1);
			}

			template<class T, class Alloc>
			bool operator>=(vector<T,Alloc> const &vec1, vector<T,Alloc> const &vec2){
				return !(vec1 < vec2);
			}

			// overloding the member function 'swap' that improves it preformence
			// by manually transferring ownership over their assets to the other
			// container (container exchange references to there data, with out having
			// to copy or move data)
			template<class T, class Alloc>
			void swap(vector<T,Alloc> const &vec1, vector<T,Alloc> const &vec2){
				vec1.swap(vec2);
			}


}// namespace ft

#include "vector.ipp"

#endif
