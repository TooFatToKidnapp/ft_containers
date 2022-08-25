/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 17:29:55 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/25 18:50:46 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>

namespace ft
{
	template<typename T>
	class vector
	{
		private:
			T*				data;
			size_t			capacity;
			size_t			current;
		public:
			vector();
			~vector();
			void push(T val);
			void push(T val, int index);
			T get(unsigned int index);
			void pop();
			int size();
			int getcapacity();
			void print();
	};
}



#endif
