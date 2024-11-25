/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:10:56 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/24 19:10:56 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include "BitcoinExchange.hpp"

bool fileEmpty(const std::string& fileName) {
	std::ifstream file(fileName.c_str());
	//peek() returns the next character in the input stream without extracting it
	return file.peek() == EOF;
}

bool fileExists(const std::string& fileName) {
    std::ifstream file(fileName.c_str());
    return file.good();
}

int	main(int argc, char** argv) {

	if (argc != 2)
	{
		std::cerr << "Incorrect input." << std::endl;
		std::cerr << "Usage: ./btc <fileName>" << std::endl;
		return 1;
	}
	try {
		std::string fileName = argv[1];
		std::ifstream inputFile(fileName.c_str());
		std::ifstream dataFile("data.csv");
		if (!inputFile || !dataFile) {
			if (errno == ENOENT)
				throw std::runtime_error("Error: File does not exist.");
			else if (errno == EACCES)
				throw std::runtime_error("Error: Permission denied.");
			else
				throw std::runtime_error("Error: Could not open file.");
		}
		if (!fileExists(fileName) || !fileExists("data.csv")) {
			throw std::runtime_error("Error: file not valid.");
		}
		if (fileEmpty(fileName) || fileEmpty("data.csv")) {
			throw std::logic_error("Error: empty file.");
		}
		BitcoinExchange btc(dataFile);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}
	return 0;
}