/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_node.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:56:28 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/01 17:48:59 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RB_NODE_HPP
# define RB_NODE_HPP

# include<iostream>

namespace ft {

	enum rb_colour {
		RED,
		BLACK
	};

	template<class T>
	class Node {
		public:
			typedef T	value_type;

			value_type	data;

			Node*		parent;
			Node*		left;
			Node*		right;

			rb_colour	colour;

			Node(value_type data, Node* parent, Node* left, Node* right, rb_colour clr)
				: data(data), parent(parent), left(left), right(right), colour(clr) {}
	};

} // namespace ft

#endif
