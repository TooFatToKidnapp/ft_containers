/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 18:16:35 by aabdou            #+#    #+#             */
/*   Updated: 2022/08/25 18:47:08 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

template<typename T>
ft::vector<T>::vector(void)
{
	data = new T[1];
	capacity  = 1;
	current = 0;
}

template<typename T>
ft::vector<T>::~vector(void)
{
	delete [] data;
}

template<typename T>
void ft::vector<T>::push(T val)
{
	if (current == capacity)
	{
		T *tmp = new T[2 * capacity];
		for (int i = 0; i < capacity; i++)
			tmp[i] = data[i];
		delete [] data;
		capacity = capacity * 2;
		data = tmp;
	}
	data[current] = val;
	current++;
}

template<typename T>
void ft::vector<T>::push(T val, int index)
{
	if (index == capacity)
		push(val);
	else
		data[index] = val;
}

template<typename T>
T ft::vector<T>::get(unsigned int index)
{
	if (index < current)
		return data[index];
}

template<typename T>
void ft::vector<T>::pop(void)
{
	current--;
}

template<typename T>
int ft::vector<T>::size(void)
{
	return current;
}

template<typename T>
int ft::vector<T>::getcapacity(void)
{
	return capacity;
}

template<typename T>
void ft::vector<T>::print(void)
{
	for (size_t i = 0; i < current; i++)
	{
		std::cout << data[i] << std::endl;
	}
}
