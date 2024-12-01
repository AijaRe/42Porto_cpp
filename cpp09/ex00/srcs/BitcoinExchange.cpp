/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:46:34 by arepsa            #+#    #+#             */
/*   Updated: 2024/12/01 11:57:00 by arepsa           ###   ########.fr       */
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
		std::string			rateStr;
		
		std::getline(ss, date, ',');
		ss >> rateStr;
		
		_exchangeRates.insert(std::pair<std::string, double>(date, std::strtod(rateStr.c_str(), NULL)));
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

bool	BitcoinExchange::createAndValidateValue(const std::string& valueStr, double& value) {
	
		char* end;
		value = std::strtod(valueStr.c_str(), &end);
		if (*end != 0 || !value) {
			std::cerr << "Error: invalid numeric value. " << std::endl;
			return false;
		}
		if (value <= 0) {
			std::cerr << "Error: not a positive number. " << std::endl;
			return false;
		}
		else if (value > static_cast<double>(INT_MAX)) {
			std::cerr << "Error: too large a number. " << std::endl;
			return false;
		}
		return true;
}

bool	BitcoinExchange::isValidDate(const std::string& date) {
	if (date.size() != 10 && date[4] != '-' && date[7] != '-') {
		return false;
	}
	int year, month, day;
	char dash1, dash2;
	std::istringstream iss(date);
	// >> reads characters from the stream until it encounters whitespace 
	// or a character that does not match the expected format for the type being extracted.
	if (!(iss >> year >> dash1 >> month >> dash2 >> day)) {
		return false;
	}
	
	std::tm time = {};
	time.tm_year = year - 1900; //	years since 1900
	time.tm_mon = month - 1; // months since January (0-11)
	time.tm_mday = day; // day of the month (1-31)

	std::tm normalizedTime = time;
	//normalizes the fields and returns time_t value, on failure returns -1
	//normalization, e.g., convert 2022-05-32 to 2022-06-01
	if (mktime(&normalizedTime) == -1)
		return false;
		
	if (normalizedTime.tm_year != time.tm_year ||
		normalizedTime.tm_mon != time.tm_mon ||
		normalizedTime.tm_mday != time.tm_mday) {
			return false;
	}
	return true;
}

void	BitcoinExchange::convertValue(const std::string& date, const double& value) {
	std::map<std::string, double>::const_iterator it = _exchangeRates.upper_bound(date);
	if (it != _exchangeRates.begin()) {
        --it;
        double rate = it->second;
		if (rate <= 0) {
			 std::cerr << "Error: invalid rate." << std::endl;
			 return ;
		}
		//std::cout << "rate: " << rate << std::endl;
		//std::cout << "value: " << value << std::endl;
        double convertedValue = value * rate;
        std::cout << date << " => " << value << " = " << convertedValue << std::endl;
    } else {
        std::cerr << "Error: date too old => " << date << " / Dates start at 2009-01-02" << std::endl;
    }
	/* if (it != _exchangeRates.end()) {
		double rate = it->second;
		std::cout << "rate: " << rate << std::endl;
		std::cout << "value: " << value << std::endl;
		double convertedValue = value * rate;
		std::cout << date << "=>" << convertedValue << std::endl;
	} else {
		std::cerr << "Error: bad input => " << date << std::endl;
	} */
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
		std::string			valueStr;
		double				value;
		
		if (std::getline(ss, date, '|') && std::getline(ss, valueStr)) {
			date = trimSpace(date);
			valueStr = trimSpace(valueStr);
		
		if (!isValidDate(date)) {
			std::cerr << "Error: Invalid date in input file => " << date << std::endl;
                continue;
		}
		
		if (!createAndValidateValue(valueStr, value)){
			continue ;
		}
		
		convertValue(date, value);
			
		} else {
			std::cerr << "Error: bad input => " << line << std::endl;
		}
	}
}

