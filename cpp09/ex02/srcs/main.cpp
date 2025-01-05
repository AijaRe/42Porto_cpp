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
#include <ctime> //clock
#include <iomanip> //setprecision fixed

void	displayInput(int argc, char** argv) {
	for (int i = 1; i < argc; i++) {
		std::cout <<  argv[i] << " ";
	}
	std::cout << std::endl;
}

template <typename T>
void	checkIfSorted(const T& container) {
	typename T::const_iterator it;
	for (it = container.begin(); it != container.end() - 1; it++) {
		if (*it > *(it + 1)) {
			std::cerr << "Error: Number are not sorted." << std::endl;
			return;
		}
	}
	std::cout << "Numbers are sorted." << std::endl;
}

int main (int argc, char** argv) {
	if (argc < 2 || std::strcmp(argv[0], "./PmergeMe") != 0) {
		std::cerr << "Usage: ./PmergeMe <numbers>" << std::endl;
		return 1;
	}

	try {

		PmergeMe sortMe;

		std::clock_t startVec = std::clock(); //unit is "clock ticks"
		sortMe.inputToVector(argc, argv);
		sortMe.sortVector();
		std::clock_t endVec = std::clock();
		std::cout << "Before: ";
		displayInput(argc, argv);
		std::cout << "After: ";
		sortMe.display(sortMe.getVector());
		// CLOCKS_PER_SEC - number of clock ticks per second 
		// 1000000 - number of microseconds in a second
		double timeVecUs = static_cast<double>(endVec - startVec) * 1000000.0 / CLOCKS_PER_SEC;
		std::cout 	<< "Time to process a range of " << argc - 1 
					<< " elements with std::vector : " << std::fixed << std::setprecision(5) 
					<< timeVecUs << " us" << std::endl;

		checkIfSorted(sortMe.getVector());

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}