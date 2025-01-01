/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 14:02:20 by arepsa            #+#    #+#             */
/*   Updated: 2024/12/30 14:02:20 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstring> //strcmp

void	displayInput(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		std::cout <<  argv[i] << " ";
	}
	std::cout << std::endl;
}

int main (int argc, char** argv) {
	if (argc <= 2 || std::strcmp(argv[0], "./PmergeMe") != 0) {
		std::cerr << "Usage: ./PmergeMe <numbers>" << std::endl;
		return 1;
	}

	try {
		PmergeMe sortVect;

		sortVect.inputToVector(argc, argv);

		std::cout << "Before: ";
		displayInput(argc, argv);

		sortVect.sortVector();

		std::cout << "After: ";
		sortVect.display();

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}