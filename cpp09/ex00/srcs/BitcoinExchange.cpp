/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:46:34 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/26 20:29:55 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
	std::cout << "BitcoinExchange default constructor called." << std::endl;
}

BitcoinExchange::BitcoinExchange(std::ifstream& dataFile) {
	std::cout << "BitcoinExchange assignment constructor called." << std::endl;
	
	std::string line;
	
	//verify if first line is date,exchange_rate
	if(std::getline(dataFile, line)){
		if (trimSpace(line) != "date,exchange_rate") {
			std::cerr << "Error: Invalid header in data file." << std::endl;
				return ;
		}
	}
 	while (std::getline(dataFile, line))
	{
		std::stringstream	ss(line);
		std::string			date;
		std::string			rate;
		
		std::getline(ss, date, ',');
		ss >> rate;
		
		_exchangeRates.insert(std::pair<std::string, double>(date, std::strtod(rate.c_str(), NULL)));
	};
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy) {
	std::cout << "BitcoinExchange copy constructor called." << std::endl;
	*this = copy;
}

BitcoinExchange::~BitcoinExchange(void) {
	std::cout << "BitcoinExchange destructor called." << std::endl;
}

BitcoinExchange & BitcoinExchange::operator=(const BitcoinExchange &src) {
	std::cout << "BitcoinExchange assignment operator called." << std::endl;
	if (this != &src) {
		// Implement assignment
	}
	return *this;
}

std::string	BitcoinExchange::trimSpace(std::string& str) {
	size_t i = 0;
	size_t j = str.size();
	
	while (i < str.size() && std::isspace(str[i]))
		i++;
	while (j > i && std::isspace(str[j - 1]))
		j--;
	
	return str.substr(i, j - i);
}

void	BitcoinExchange::printExchangeRates(void) const {
	std::map<std::string, double>::const_iterator it = _exchangeRates.begin();
	std::map<std::string, double>::const_iterator ite = _exchangeRates.end();
	
	for (it; it != ite; ++it) {
		std::cout << it->first << " - " << it->second << std::endl;
	}
}

void	BitcoinExchange::processInput(std::ifstream& inputFile) {
	std::string	line;
	
	if(std::getline(inputFile, line)){
		if (trimSpace(line) != "date | value") {
			std::cerr << "Error: Invalid header in input file." << std::endl;
				return ;
		}
	}
	
	while (std::getline(inputFile, line)) {
		std::stringstream	ss(line);
		std::string			date;
		std::string			value;
	}
}

