/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.ipp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 17:17:09 by aabdou            #+#    #+#             */
/*   Updated: 2022/09/20 18:46:11 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"./stack.hpp"

namespace ft {

template<class T, class Container>
ft::stack<T, Container>::stack(const Container& cont) : c(cont){}

template<class T, class Container>
ft::stack<T, Container>::stack(const stack& obj): c(obj.c) {}

template<class T, class Container>
ft::stack<T, Container> &ft::stack<T, Container>::operator=(const stack& obj){
	if (this != &obj)
		c = obj.c;
	return *this;
}

template<class T, class Container>
ft::stack<T,Container>::~stack(){}

template<class T, class Container>
typename ft::stack<T,Container>::reference ft::stack<T,Container>::top(){
	return c.back();
}

template<class T, class Container>
typename ft::stack<T, Container>::const_reference ft::stack<T, Container>::top() const{
	return c.back();
}

template<class T, class Container>
bool ft::stack<T, Container>::empty() const{
	return c.empty();
}

template<class T, class Container>
typename ft::stack<T, Container>::size_type ft::stack<T, Container>::size() const {
	return c.size();
}

template<class T, class Container>
void ft::stack<T, Container>::push(typename ft::stack<T, Container>::value_type const &value){
	c.push_back(value);
}

template<class T, class Container>
void ft::stack<T, Container>::pop(){
	c.pop_back();
}

} // namespace ft
