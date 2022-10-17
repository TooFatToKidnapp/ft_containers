/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabdou <aabdou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 09:43:34 by aabdou            #+#    #+#             */
/*   Updated: 2022/10/17 16:19:47 by aabdou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.hpp"

void header(std::string container) {

	std::string header = GREEN + container + " TESTS: " + CLEAR + "press enter to continue\n";
	int width = 100 - (header.length() / 2);

	cout << '/' << std::setfill('*') << std::setw(100) << "/\n" << std::setfill(' ') << std::endl;
	cout << std::setw(width) << header << std::endl;
	cout << '/' << std::setfill('*') << std::setw(100) << "/\n" << std::setfill(' ') << std::endl;

}

void print_title(std::string title, std::string sub) {
	cout << "\n";
	cout << YELLOW << title << ": " << CLEAR << sub << "\n\n";
}

int main() {

	header("VECTOR");
	std::cin.get();
	vector_tests();
	cout << std::endl;
	header("STACK");
	std::cin.get();
	stack_tests();
	cout << std::endl;
	header("MAP");
	std::cin.get();
	map_tests();
	cout << std::endl;
	header("SET");
	std::cin.get();
	set_tests();
	cout << std::endl;
}
