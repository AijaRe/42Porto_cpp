/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:46:37 by arepsa            #+#    #+#             */
/*   Updated: 2025/02/14 19:38:35 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <climits>
#include <map>
#include <string>
#include <ctime>

class BitcoinExchange {
	public:
		BitcoinExchange(void);
		BitcoinExchange(std::ifstream& dataFile);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange(void);
		BitcoinExchange & operator=(const BitcoinExchange &src);
		
		void	printExchangeRates(void) const;
		void	processInput(std::ifstream& inputFile);

	private:
		std::map<std::string, double> _exchangeRates;
		
		std::string trimSpace(std::string& str);
		bool		createAndValidateValue(const std::string& valueStr, double& value);
		bool		isValidDate(const std::string& date);
		void		convertValue(const std::string& date, const double& value);
};

#endif // BITCOINEXCHANGE_HPP
