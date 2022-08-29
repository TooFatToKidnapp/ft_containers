/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:29:55 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/29 17:33:53 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include <vector>
#include "allocator.hpp"

namespace ft
{
	template<typename T, class Alloc = allocator<T> >
	class vector
	{
		private:
			T*				data;
			size_t			capacity;
			size_t			current;
		public:
			vector()
			{
				data = new T[1];
				capacity  = 1;
				current = 0;
			}
			~vector()
			{
				delete [] data;
			}
			void push(T val)
			{
				if (current == capacity)
				{
					T *tmp = new T[2 * capacity];
					for (unsigned int i = 0; i < capacity; i++)
						tmp[i] = data[i];
					delete [] data;
					capacity = capacity * 2;
					data = tmp;
				}
				data[current] = val;
				current++;
			}
			void push(T val, int index)
			{
				if (index == capacity)
					push(val);
				else
					data[index] = val;
			}
			T get(unsigned int index)
			{
				if (index < current)
					return data[index];
			}
			void pop()
			{
				current--;
			}
			int size()
			{
				return current;
			}
			int getcapacity()
			{
				return capacity;
			}
			void print();
	};
}

#include "vector.ipp"

#endif
