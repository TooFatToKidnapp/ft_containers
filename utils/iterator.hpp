/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:01:38 by aabdou            #+#    #+#             */
/*   Updated: 2022/09/15 11:28:05 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include<iterator> // iterator_tags
#include<cstddef> // ptrdiff_t, size_t

namespace ft{

	/*
		cant creat seperat itt tags, as they would only work for ft::iterators
		without being compatible to std::iterators, therefor defeating the purpose of
		general itt tags

		struct output_iterator_tag {};
		struct input_iterator_tag {};
		struct forward_iterator_tag: public input_iterator_tag {};
		struct bidirectional_iterator_tag: public forward_iterator_tag {};
		struct random_access_iterator_tag: public bidirectional_iterator_tag {};
	*/


	//iterator tags
	//these are types used to distinguish different iterators.
	typedef std::input_iterator_tag				input_iterator_tag;
	typedef std::output_iterator_tag			output_iterator_tag;
	typedef	std::forward_iterator_tag			forward_iterator_tag;
	typedef std::bidirectional_iterator_tag		bidirectional_iterator_tag;
	typedef std::random_access_iterator_tag		random_access_iterator_tag;

	//common itt class defining nested typedefs which iterator classes can inherit to save work
	//(one itt class for all the containers)
	template<class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	class iterator {
		public:
			//categoty of the itt , must be one of the iterator category tags
			typedef Category		iterator_category;
			//type of val obtained when derederencing the iterator.
			typedef T				value_type;
			//type of identify distance between iterators
			typedef Distance		difference_type;
			//pointer to val type
			typedef Pointer			pointer;
			//ref to val type
			typedef Reference		reference;
	};

	//traits class defining propeties of iterators
	//generic definition
	template<class Itt>
	struct iterator_traits{
		public:
			typedef typename Itt::difference_type		difference_type;
			typedef typename Itt::value_type			value_type;
			typedef typename Itt::pointer				pointer;
			typedef typename Itt::reference				reference;
			typedef typename Itt::iterator_category		iterator_category;
	};

	//T* specialization
	template<class T>
	struct iterator_traits<T*>{
		public:
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef ft::random_access_iterator_tag	iterator_categoty;
	};

	//const T* specialization
	template<class T>
	struct iterator_traits<T const*>{
		public:
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef T const*						pointer;
			typedef T const&						reference;
			typedef ft::random_access_iterator_tag	iterator_categoty;
	};

	template <class input_itt>
	typename iterator_traits<input_itt>::difference_type
		distance(input_itt first, input_itt last){
			typename ft::iterator_traits<input_itt>::difference_type res = 0;
			while (first != last){
				first++;
				res++;
			}
			return res;
		}

} // namespace ft

#endif
