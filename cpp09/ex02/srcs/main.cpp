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
			std::cerr << "--->Error: Number are not sorted." << std::endl;
			return;
		}
	}
	std::cout << "--->Numbers are sorted." << std::endl;
}

template <typename T>
void	checkIfCorrectCount(const T& container, int count) {
	if (container.size() != static_cast<size_t>(count)) {
		std::cerr << "--->Error: Incorrect number of elements." << std::endl;
		return;
	}
	std::cout << "--->Correct number of elements." << std::endl;
}

int main (int argc, char** argv) {
	if (argc < 2 || std::strcmp(argv[0], "./PmergeMe") != 0) {
		std::cerr << "Usage: ./PmergeMe <numbers>" << std::endl;
		return 1;
	}

	try {

		PmergeMe sortMe;

		std::clock_t startVec = std::clock(); //unit is "clock ticks"
		sortMe.parseInputVec(argc, argv);
		sortMe.sortVector();
		std::clock_t endVec = std::clock();

		std::cout << "Before: ";
		displayInput(argc, argv);
		std::cout << "After: ";
		sortMe.display(sortMe.getVector());

		std::clock_t startDeq = std::clock();
		sortMe.parseInputDeq(argc, argv);
		sortMe.sortDeque();
		std::clock_t endDeq = std::clock();
		
		std::cout << "Before: ";
		displayInput(argc, argv);
		std::cout << "After: ";
		sortMe.display(sortMe.getDeque());

		// CLOCKS_PER_SEC - number of clock ticks per second 
		// Dividing a count of clock ticks by this expression yields the number of seconds.
		double timeVecSec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC;
		double timeDeqSec = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC;
		std::cout 	<< "Time to process a range of " << argc - 1 
					<< " elements with std::vector : " << std::fixed << std::setprecision(5) 
					<< timeVecSec << " s" << std::endl;
		std::cout 	<< "Time to process a range of " << argc - 1
					<< " elements with std::deque : " << std::fixed << std::setprecision(5) 
					<< timeDeqSec << " s" << std::endl;

		std::cout << "Checking if vector is sorted..." << std::endl;
		checkIfSorted(sortMe.getVector());
		checkIfCorrectCount(sortMe.getVector(), argc - 1);
		std::cout << "Checking if deque is sorted..." << std::endl;
		checkIfSorted(sortMe.getDeque());
		checkIfCorrectCount(sortMe.getDeque(), argc - 1);

	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}

	return 0;
}