/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:46:34 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/25 21:26:35 by arepsa           ###   ########.fr       */
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
		if (line != "date,exchange_rate") {
			std::cerr << "Error: Invalid header in data file." << std::endl;
				return ;
		}
	}
	while (std::getline(dataFile, line))
	{
		std::stringstream	ss;
		std::string			date;
		std::string			rate;
		
		ss(line, date, ",");
		
		_exchangeRates.insert(pair<std::string, double>(date, rate));
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

