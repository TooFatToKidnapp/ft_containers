/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 15:49:19 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/17 09:30:27 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
#define UTILS_HPP


#include "./../containers/vector.hpp"
#include "./../containers/stack.hpp"
#include "./../containers/map.hpp"
#include "./../containers/set.hpp"
#include "./../utils/pair.hpp"
#include "./../utils/rb_tree.hpp"
#include "./../utils/Bidirectional_Iterator.hpp"
#include <list>
#include <vector>
#include <exception>
#include <map>
#include <set>
#include <stack>
#include <functional>
#include <algorithm>
#include <limits>
#include <iomanip>
#include <iostream>

#define DataType int

using std::cout;

#define GREEN "\033[0;32m"
#define RED "\033[0;31m"
#define YELLOW "\033[0;33m"
#define CLEAR "\033[0m"

void print_title(std::string title, std::string sub = "");
void vector_tests();
void stack_tests();
void map_tests();
void set_tests();


#endif
