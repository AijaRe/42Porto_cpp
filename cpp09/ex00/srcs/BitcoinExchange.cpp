/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:46:34 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/24 20:03:59 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) {
    std::cout << "BitcoinExchange default constructor called." << std::endl;
}

BitcoinExchange::BitcoinExchange(std::ifstream& inputFile, std::ifstream& dataFile) {
    std::cout << "BitcoinExchange assignment constructor called." << std::endl;
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

