/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arepsa <arepsa@student.42porto.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 19:46:37 by arepsa            #+#    #+#             */
/*   Updated: 2024/11/26 19:51:23 by arepsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <map>
#include <string> //??

class BitcoinExchange {
	public:
		BitcoinExchange(void);
		BitcoinExchange(std::ifstream& dataFile);
		BitcoinExchange(const BitcoinExchange &copy);
		~BitcoinExchange(void);
		BitcoinExchange & operator=(const BitcoinExchange &src);
		
		void	printExchangeRates(void);

	private:
		std::map<std::string, double> _exchangeRates;
};

#endif // BITCOINEXCHANGE_HPP
