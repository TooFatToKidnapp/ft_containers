/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:17:11 by aabdou            #+#    #+#             */
/*   Updated: 2022/09/21 15:17:37 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
#define STACK_HPP

#include"./vector.hpp"

namespace ft {
	template<class T, class Container = std::vector<T> >
	class stack {
		public:
			typedef Container							container_type;
			typedef T									value_type;
			typedef std::size_t							size_type;
			typedef typename Container::reference		reference;
			typedef typename Container::const_reference	const_reference;

			explicit stack( const Container& cont = Container() );
			stack( const stack& obj );
			~stack();
			stack& operator=( const stack& other );
			reference top();
			const_reference top() const;
			bool empty() const;
			size_type size() const;
			void push( const value_type& value );
			void pop();

		// friend declaration for accessing protecte c container atribute

			template<class T1, class Container1>
			friend bool operator==(stack<T1, Container1> const &first,
									stack<T1, Container1> const &second);

			template<class T1, class Container1>
			friend bool operator<(stack<T1, Container1> const &first,
									stack<T1, Container1> const &second);
		protected:
			Container	c;

	};

	// non member functions

		template<class T, class Container>
		bool operator==(stack<T, Container> const& first,
						stack<T, Container> const& second){
			return first.c == second.c;
		}

		template<class T, class Container>
		bool operator!=(stack<T, Container> const& first,
						stack<T, Container> const& second){
			return !(first == second);
		}

		template<class T, class Container>
		bool operator<(stack<T, Container> const& first,
						stack<T, Container> const& second){
			return (first.c < second.c);
		}

		template<class T, class Container>
		bool operator<=(stack<T, Container> const& first,
						stack<T, Container> const& second){
			return !(second < first);
		}

		template<class T, class Container>
		bool operator>(stack<T, Container> const& first,
						stack<T, Container> const& second){
			return (second < first);
		}

		template<class T, class Container>
		bool operator>=(stack<T, Container> const& first,
						stack<T, Container> const& second){
			return !(first < second);
		}

} // namespace ft

#include"stack.ipp"

#endif
