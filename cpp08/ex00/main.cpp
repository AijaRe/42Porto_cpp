/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:08:01 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/22 18:58:43 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include <list>
#include "main.hpp"
#include "easyfind.hpp"

void	printTitle(std::string title) {
	std::cout << std::endl;
	std::cout << BOLD << CYAN;
	std::cout << LINE << std::endl;
	std::cout << "| " << title << std::endl;
	std::cout << LINE << std::endl;
	std::cout << RESET << std::endl;
}

template<typename T>	
void	performTest(T& container, int value){
	try {
		typename T::const_iterator it = easyfind(container, value);
		std::cout << GREEN << "Found value: " << *it << RESET << std::endl;
	} catch (const std::exception& e) {
		std::cout << RED << e.what() << RESET <<std::endl;
	}
}

int	main(void){
	printTitle("TEST VECTOR");
	int numArr[] = {1, 5, 4, 2, 3};

	//range constructor "std::vector<Type> vec(first, last);"
	std::vector<int> numVect(numArr, numArr + 5); 
	
	std::cout << "Looking for valid value \"3\" " << ARROW << std::endl;
	performTest(numVect, 3);

	std::cout << "Looking for invalid value \"-2\"" << ARROW << std::endl;
	performTest(numVect, -2);

	printTitle("TEST LIST");
	std::list<int> numList(numArr, numArr + 5);
	
	std::cout << "Looking for valid value \"5\"" << ARROW << std::endl;
	performTest(numList, 5);

	std::cout << "Looking for invalid value \"999\"" << ARROW << std::endl;
	performTest(numList, 999);
	
	printTitle("END TESTS");
	
	return 0;
}
