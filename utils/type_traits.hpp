/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 17:32:28 by aabdou            #+#    #+#             */
/*   Updated: 2022/09/11 10:16:31 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft{
	// primary template for enable_if
	// defines a member typedef 'type'  if boolean constant b is true

	template<bool B, typename T= void>
	struct enable_if
	{};

	// partial specialization for true
	template<class T>
	struct enable_if<true, T>
	{
		typedef T	type;
	};

	// C++11
	// template designed to provide compile-time constants as type
	// used as the base class for trait type
	// T is type of integeral contant, v is the value
	template <class T, T v>
	struct integeral_constant
	{
		static const	T							value = v;
		typedef			T							value_type;
		typedef			integeral_constant<T, v>	type;

		operator T(){
			return v;
		}
	};

	// 'is_integral' inherits the following from 'integral_constant'
	// member constant value
	// member functions operator bool & operator()
	// member types 'value_type' and type

	typedef integeral_constant<bool , true> true_type;
	typedef integeral_constant<bool , false> false_type;

	// check if T is integral type
	// provide member constant 'value' which is equal to true if 'T' is
	// an integral type, or a cv-qualified form of one of those types
	// otherwise value is equal to false
	// Integral types:  bool, char, unsigned char, signed char, wchar_t, short,
	//                  unsigned short, int, unsigned int, long, and unsigned long.
	//  In addition, with compilers that provide them, an integral type can be
	//  one of long long, unsigned long long, __int64, and unsigned __int64.

	template<class T>
	struct is_integral : public ft::false_type
	{};

	template<>
	struct is_integral<bool> : public ft::true_type
	{};

	template<>
	struct is_integral<char> : public ft::true_type
	{};

	template<>
	struct is_integral<unsigned char> : public ft::true_type
	{};

	template<>
	struct is_integral<wchar_t> : public ft::true_type
	{};

	template<>
	struct is_integral<short> : public ft::true_type
	{};

	template<>
	struct is_integral<unsigned short> : public ft::true_type
	{};

	template<>
	struct is_integral<int> : public ft::true_type
	{};

	template<>
	struct is_integral<unsigned int> : public ft::true_type
	{};

	template<>
	struct is_integral<long> : public ft::true_type
	{};

	template<>
	struct is_integral<unsigned long> : public ft::true_type
	{};


	template<>
	struct is_integral<long long> : public ft::true_type
	{};


	template<>
	struct is_integral<unsigned long long> : public ft::true_type
	{};

} // namespace ft


#endif
