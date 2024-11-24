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

bool is_file_empty(const std::string& fileName) {
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
	else {
		std::string fileName = argv[1];
		std::ifstream inputFile(fileName.c_str());
		std::ifstream dataFile("data.csv");

		if (fileName.empty() || is_file_empty(fileName)){
			std::cerr << "Warning: fileName or file cannot be empty." << std::endl;
			return 1;
		}
		if (!fileExists(fileName) || !fileExists("data.csv")) {
			std::cerr << "Error: file not valid." << std::endl;
			return 1;
		}
		BitcoinExchange btc(inputFile, dataFile);
		//do prog
	}
	return 0;
}