/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:38:34 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/29 20:05:42 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

#include <iostream>
#include <cstddef>
#include <limits>

template<typename T>
class custom_Allocator
{
	public:
		typedef		T				value_type;
		typedef		T*				pointer;
		typedef		const T*		const_pointer;
		typedef		void *			void_pointer;
		typedef		const void *	const_void_pointer;
		typedef		size_t			size_type;
		typedef		std::ptrdiff_t	difference_type;

	template<typename U>
	struct rebind
	{
		typedef costom_Allocator<U> other;
	}
	costom_Allocator();
	template<class U>
	costom_Allocator(const costom_Allocator<U> &other){}
	~costom_Allocator();
	pointer	allocate(size_type nb_of_obj)
	{
		mAllocations++;
		return static_cast<pointer>(new(sizeof(T) * nb_of_obj));
	}
	pointer	allocate(size_type nb_of_obj)
	{
		return allocate(nb_of_obj);
	}
	void	deallocate(pointer p, size_type nb_of_obj)
	{
		delete p;
	}
	size_type	max_size(void) const
	{
		return std::numeric_limits<size_type>::max();
	}
	template<class U, class... Args>
	void construct(U *p, Args && ...args)
	{
		new(p) U(std::forward<Args>(args)...);
	}
	template<class U>
	void destroy(U *p)
	{
		p->~U();
	}
	size_type get_allocations() const
	{
		return mAllocations;
	}

	private:
		static size_type mAllocations;
};

template <typename T>
typename custom_allocator<T>::size_type TrackingAllocator<T>::mAllocations = 0;

#endif
