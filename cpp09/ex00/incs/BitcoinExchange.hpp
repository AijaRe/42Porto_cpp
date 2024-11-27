/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:46:37 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/27 22:14:06 by arepsa           ###   ########.fr       */
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
#include <string> //??

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
};

#endif // BITCOINEXCHANGE_HPP
