/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb_node.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:56:28 by aabdou            #+#    #+#             */
/*   Updated: 2022/09/30 18:46:43 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef RB_NODE_HPP
# define RB_NODE_HPP

# include<iostream>

namespace ft {

	enum rb_colour {
		RED = false,
		BLACK = true
	};


	// base class that dosen't know about val "user data"
	// used for sentinal node "NULL" to prevent unecessary memory usage
	class rb_node_base {
		public:
			rb_node_base*	left;
			rb_node_base*	right;
			rb_node_base*	parent;
			rb_colour		colour;

			// default constructor for sentinal
			rb_node_base() : left(NULL), right(NULL) ,parent(NULL), colour(BLACK) {}

			// constructor with parent and children (for passing NULL)
			rb_node_base(rb_node_base * parent, rb_node_base * child)
				: left(child), right(child), parent(parent), colour(RED) {}

			// copy constructor
			rb_node_base(const rb_node_base &obj) {
				this->parent = obj.parent;
				this->left = obj.left;
				this->right = obj.right;
				this->colour = obj.colour;
			}
	};


	// derived class that knows KEY (used for nodes with <key,T> data)
	template<class Key>
	class rb_node : public rb_node_base {
		public:
			// val is a pair <Key,T> obj
			Key val;

			// constructor with val and parent and child (NULL)
			rb_node(const Key &val, rb_node_base* parent, rb_node_base* child)
				: val(val), rb_node_base(parent, child) {}

			rb_node(const rb_node_base &base) : rb_node_base(base) {}

			rb_node(const rb_node& other) : rb_node_base(other) , val(other.val) {}

	};

} // namespace ft

#endif
